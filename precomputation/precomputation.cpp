#include <cstdio>
#include <cstdlib>

#include <cstdint>
#include <cstring>
extern "C"
{
#include <math.h>
#include <inttypes.h>
}
#include <algorithm>
#include <iostream>
 #include <fstream>
#include <set>
#include <iterator>
#include <vector>
#include <unordered_set>
#include <bitset>
#include <functional>
#include <map>

using namespace std;

typedef uint64_t poly;

uint64_t corres(uint32_t b1, uint32_t b2, uint32_t n) {
    /* Permet de faire la correspondance entre la multiplication de deux fonctions linéaires et des monômes quadratiques obtenus*/
    uint32_t i;
    uint32_t j;
    if (b1 < b2)    {
        i = b1;
        j = b2;
    }
    else {
        i = b2;
        j = b1;
    }
    uint64_t res = (n *(n -1))/2 -1 -i*(n-1) + (i*(i-1)/2) - (j-i) +1;
    return res;
}

vector<vector<poly>> create_mat_op(uint32_t nb_bits) {
    /*crée une matrice à 3 colonnes où chaque ligne représente 2 fonctions linéaires et la valeur de la fonction quadratique obtenue*/
    /* La ligne 10|13|61 illustre que (10 = (1010)_2 = x0+x2) * (13 = (1101)_2 = x0+x1+x3) = (x0 + x0x1 + x0x3 + x0x2 + x1x2 + x2x3 = 111101 = 61)*/
    vector<vector<poly>> Mat_op;
    poly nb_op_lin = 1ul<<nb_bits;
    /* On écrit une opération linéaire comme un mot où chaque bit représente un monôme ; ie 10110 représente x0 + x2 + x3*/
    for (poly i = 1; i < nb_op_lin; i++) {
        int temp_i = i;
        int bits_i[nb_bits];
        for (int b = nb_bits-1; b > -1; b--) {
            bits_i[b] = temp_i&1ul;
            temp_i >>= 1;
        }
        for (poly j = 1; j < nb_op_lin; j++) {
            int temp_j = j;
            int bits_j[nb_bits];
            for (int b = nb_bits-1; b > -1; b--) {
                bits_j[b] = temp_j&1ul;
                temp_j >>= 1;
            }
            poly res = 0;
            /* On récupère le résultat de l'opération sous forme d'un mot où chaque bit représente un monôme QUADRATIQUE ; ie 101100 représente (sur 4 bits) x0x1 + x0x3 + x1*x2*/
            for (uint32_t b1 = 0; b1 < static_cast<uint32_t>(nb_bits); b1++) {
                for (uint32_t b2 = 0; b2 < static_cast<uint32_t>(nb_bits); b2++) {
                    if (b1 != b2) {
                        if ((bits_i[b1] == bits_j[b2]) && (bits_i[b1] == 1))
                            res ^= 1ul << corres(b1, b2, nb_bits);
                    }
                }
            }
            vector<poly> ligne = {i, j, res};
            Mat_op.push_back(ligne);
        }
    }
    return Mat_op;
}

set<poly> create_set_op(uint32_t nb_bits)   {
    /* crée le set d'opérations */
    vector<vector<poly>> Mat_op = create_mat_op(nb_bits);
    set<poly> set_op;
    for (uint32_t i=0; i<Mat_op.size() ;i++)   {
        /*Les opérations pouvant être obtenues en 1 AND correspondent à la dernière colonne de la matrice*/
        set_op.insert(Mat_op[i][2]);
    }
    set_op.erase(0);
    return set_op;
}

map<poly,set<set<poly>>> create_map (set<poly> set_op)    {
    // Récupère le dictionnaire contenant le xor 2 à 2 de toutes les opérations du set initial et les couples asscoiées
    map<poly,set<set<poly>>> map_xor;
    for (auto i= set_op.begin(); i != set_op.end(); i++)    {
        for (auto j= next(i); j!= set_op.end(); j++)    {
            set<poly> p = {*i,*j};
            map_xor[*i ^ *j].insert(p);
        }
    }
    return map_xor;
}

int hammingWeight(poly x) {
    /*Calcule le poids de Hamming de x*/
    bitset<64> bits(x);
    return bits.count();
}

poly plus_petit_poids(set<poly> * set_op,int nb_bits) {
    /* Renvoie l'élément d'un set avec le poids de Hamming le plus faible et le supprime du set*/
    int lowest = -1;
    int lowestWeight = nb_bits;
    auto a_supprimer = (*set_op).begin();
    for (auto it = (*set_op).begin(); it != (*set_op).end(); it++) {
        int poids = hammingWeight(*it);
        if (poids < lowestWeight) {
            lowest = *it;
            lowestWeight = poids;
            a_supprimer = it;
        }
    }
    (*set_op).erase(a_supprimer);
    return lowest;
}

int main(int argc, char *argv[]) {

    if (argc < 2) {
        cerr << "Please provide the maximum S-box size you want to implement.\nPlease note that large sizes require a large space in RAM, so check that you have this amount of RAM available beforehand.\n\nThe make command to build precomputation files should look like\n\tmake precomputation_files MAX_SIZE=6\n\n";
        exit(1);
    }
    int nb_bits_max = atoi(argv[1]);

    for (int nb_bits = 4; nb_bits < nb_bits_max +1; nb_bits ++) {
    
    vector<vector<poly>> Mat_op = create_mat_op(nb_bits);

    set<poly> set_op = create_set_op(nb_bits);

    string filename = string("../precomputation/precomputed_set_") + to_string(nb_bits) + string(".txt");
    
    FILE* fp = fopen(filename.c_str(), "w");
    if (fp == NULL) {
        cerr << "Couldn't open file " << filename << endl;
        exit(EXIT_FAILURE);
    }

    ofstream file(filename);

    file <<"{";
    for (auto it = set_op.begin(); it != set_op.end(); it++)    {
        if (it == set_op.begin() )  {
            file <<*it;
        }
        else {
            file <<","<<*it;
        }
    }
    file <<"};"<<endl;
    
    file.close();

    filename = string("../precomputation/precomputed_map_lin_") + to_string(nb_bits) + string(".txt");
    
    fp = fopen(filename.c_str(), "w");
    if (fp == NULL) {
        cerr << "Couldn't open file " << filename << endl;
        exit(EXIT_FAILURE);
    }

    ofstream file2(filename);

    map<poly,set<poly>> map_lin;
    for (auto it = set_op.begin(); it != set_op.end(); it++)    {
        set<poly> op;
        for (uint32_t j=0; j<Mat_op.size(); j++)   {
            if ( *it == Mat_op[j][2])   {
                map_lin[*it].insert(Mat_op[j][0]);
                map_lin[*it].insert(Mat_op[j][1]);
            }
        }
    }
    //Pour chaque opération non-linéaire présente, on récupère les opérations linéaires ayant le poids de Hamming le plus faible permettant de l'obtenir 
    map<poly,vector<poly>> mat_op;
    for (auto it_m = map_lin.begin(); it_m != map_lin.end(); it_m++)  {
        set<poly> * monom_lin ;
        monom_lin = &(*it_m).second;
        poly op1 = plus_petit_poids(monom_lin,nb_bits);
        poly op2 = plus_petit_poids(monom_lin,nb_bits);
        mat_op[(*it_m).first].push_back(op1);
        mat_op[(*it_m).first].push_back(op2);
    }

    for (auto it_m = mat_op.begin(); it_m != mat_op.end(); it_m++)  {
        file2 <<"["<<(*it_m).first<<", {"<<(*it_m).second[0]<<","<<(*it_m).second[1]<<"}]"<<endl;
    }

    file2.close();

    filename = string("../precomputation/precomputed_map_xor_") + to_string(nb_bits) + string(".txt");
    
    fp = fopen(filename.c_str(), "w");
    if (fp == NULL) {
        cerr << "Couldn't open file " << filename << endl;
        exit(EXIT_FAILURE);
    }

    ofstream file3(filename);

    map<poly,set<set<poly>>> map_xor = create_map(set_op);
    
    
    for (auto it_m = map_xor.begin(); it_m != map_xor.end(); it_m++)  {
        if ((*it_m).second.size()==10)  {
            file3 <<"["<<(*it_m).first<<", ";
            for (auto it_set = (*it_m).second.begin(); it_set != (*it_m).second.end(); it_set++)   {
                file3 <<"{";
                for (auto it=(*it_set).begin(); it != (*it_set).end(); it++)   {
                    if (it == (*it_set).begin())    {
                        file3 <<*it;
                    }
                    else {
                        file3 <<","<<*it;
                    }
                }
                file3 <<"}";
            }
            file3 <<"]"<<endl;
        }
    }
    file3.close();
    }

    exit(0);
}
