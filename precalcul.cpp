#include "config.h"
#include "poly.h"
#include "precalcul.h"

using namespace std;

vector<vector<poly>> create_mat_op(int nb_bits) {
    vector<vector<poly>> Mat_op;
    poly nb_op_lin = 1ul<<nb_bits;
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

set<poly> create_set_op( vector<vector<poly>> * Mat_op)   {
    set<poly> set_op;
    for (uint32_t i=0; i<(*Mat_op).size() ;i++)   {
        set_op.insert((*Mat_op)[i][2]);
    }
    set_op.erase(0);
    return set_op;
}

map<poly,set<set<poly>>> create_map (set<poly> * set_op)    {
    map<poly,set<set<poly>>> map_xor;
    for (auto i= (*set_op).begin(); i != (*set_op).end(); i++)    {
        for (auto j= next(i); j!= (*set_op).end(); j++)    {
            set<poly> s = {*i,*j};
            map_xor[*i ^ *j].insert(s);
        }
    }
    for (auto it=map_xor.begin(); it != map_xor.end(); it++)    {
        if ((*it).second.size() != 10)  {
            map_xor.erase(it);
        }
    }
    return map_xor;
}

map<poly,pair<poly,poly>> create_map_lin (vector<vector<poly>> Mat_op, set<poly> set_op, uint8_t nb_bits)    {
    map<poly,set<poly>> map_lin;
    for (auto it = set_op.begin(); it != set_op.end(); it++)    {
        for (uint32_t j=0; j<Mat_op.size(); j++)   {
            if ( *it == Mat_op[j][2])   {
                map_lin[*it].insert(Mat_op[j][0]);
                map_lin[*it].insert(Mat_op[j][1]);
            }
        }
    }
    map<poly,pair<poly,poly>> mat_op;
    for (auto it_m = map_lin.begin(); it_m != map_lin.end(); it_m++)  {
        set<poly> * monom_lin ;
        monom_lin = &(*it_m).second;
        poly op1 = lowest_hw(monom_lin,nb_bits);
        poly op2 = lowest_hw(monom_lin,nb_bits);
        mat_op[(*it_m).first].first = op1;
        mat_op[(*it_m).first].second = op2;
    }
    return mat_op;
}

uint32_t nb_bits_to_size_set (uint32_t size){
    uint32_t res;
    if (size == 5)  {
        res = 155;
    }
    if (size == 6)  {
        res = 651;
    }
    if (size == 7)  {
        res = 2667;
    }
    if (size == 8)  {
        res = 10795;
    }
    if (size == 9)  {
        res = 43435;
    }
    if (size == 10)  {
        res = 174251;
    }
    return res;
}

uint32_t nb_bits_to_size_map_xor (uint32_t size){
    uint32_t res;
    if (size == 5)  {
        res = 868;
    }
    if (size == 6)  {
        res = 18228;
    }
    if (size == 7)  {
        res = 330708;
    }
    if (size == 8)  {
        res = 5622036;
    }
    if (size == 9)  {
        res = 92672916;
    }
    return res;
}

void parse_file_and_create_set(uint32_t size, poly set_op []) {
    
    string filename = string("precomputation/precomputed_set_") + to_string(size) + string(".txt");

    FILE* fp = fopen(filename.c_str(), "r");
    if (fp == NULL) {
        cerr << "Couldn't open file " << filename << endl;
        exit(EXIT_FAILURE);
    }

    uint32_t it = 0;

    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        size_t pos = line.find("{");
        while (pos != string::npos) {
            size_t endPos = line.find("}", pos); //Position of '}'
            if (endPos == string::npos) 
                break;

            string set_str = line.substr(pos + 1, endPos - pos - 1); //To extract the char beetween '{' and '}'

            size_t pos_valeur = set_str.find_first_of("0123456789"); //Position of the first value
            while (pos_valeur != string::npos) { 
                size_t pos_virgule = set_str.find(",", pos_valeur); //position of ','
                if (pos_virgule == string::npos)
                    pos_virgule = set_str.size();
                
                poly value = stoul(set_str.substr(pos_valeur, pos_virgule - pos_valeur)); //To convert the char beetween ',' into an int.
                set_op[it] = value;
                it++;

                pos_valeur = set_str.find_first_of("0123456789", pos_virgule + 1);
            }
            pos = line.find("{", endPos);
        }
    }

    file.close();
}

void parse_file_and_create_map_lin(uint32_t size, pair_lin map_lin []) {
    
    string filename = string("precomputation/precomputed_map_lin_") + to_string(size) + string(".txt");

    FILE* fp = fopen(filename.c_str(), "r");
    if (fp == NULL) {
        cerr << "Couldn't open file " << filename << endl;
        exit(EXIT_FAILURE);
    }
    
    uint32_t i=0;

    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        size_t pos = line.find("[");
        if (pos == string::npos)
            continue;

        poly key = stoul(line.substr(pos + 1)); //If we find "[", the next character is the key.
        map_lin[i].first = key;

        pos = line.find("{", pos); //Position of '{'
        while (pos != string::npos) {
            size_t endPos = line.find("}", pos); //of '}'
            if (endPos == string::npos) 
                break;

            string vect_str = line.substr(pos + 1, endPos - pos - 1); //To extract the char beetween '{' and '}'
            uint32_t j=0;

            size_t pos_valeur = vect_str.find_first_of("0123456789"); //Position of the first value.
            while (pos_valeur != string::npos) { 
                size_t pos_virgule = vect_str.find(",", pos_valeur); //position of ','
                if (pos_virgule == string::npos)
                    pos_virgule = vect_str.size();
                
                poly value = stoul(vect_str.substr(pos_valeur, pos_virgule - pos_valeur)); //To convert the char beetween ',' into an int.
                map_lin[i].second[j] = value ;

                pos_valeur = vect_str.find_first_of("0123456789", pos_virgule + 1);
                j ++;
            }
            i++;
            pos = line.find("{", endPos);
        }
        
    }

    file.close();
}

void parse_file_and_create_map_xor(uint32_t size, pair_xor map_xor []) {
    
    string filename = string("precomputation/precomputed_map_xor_") + to_string(size) + string(".txt");

    FILE* fp = fopen(filename.c_str(), "r");
    if (fp == NULL) {
        cerr << "Couldn't open file " << filename << endl;
        exit(EXIT_FAILURE);
    }

    uint32_t i = 0; //counter on the number of elements of map_xor 
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        size_t pos = line.find("[");
        if (pos == string::npos)
            continue;

        poly key = stoul(line.substr(pos + 1)); 
        map_xor[i].first = key;
        
        uint32_t j=0; //counter on the first index of the array contained in .second 

        pos = line.find("{", pos); 
        while (pos != string::npos) {
            size_t endPos = line.find("}", pos); 
            if (endPos == string::npos) 
                break;

            string set_str = line.substr(pos + 1, endPos - pos - 1);
           
            uint32_t k=0; //counter on the second index of the array contained in .second 

            size_t pos_valeur = set_str.find_first_of("0123456789");
            while (pos_valeur != string::npos) { 
                size_t pos_virgule = set_str.find(",", pos_valeur); 
                if (pos_virgule == string::npos)
                    pos_virgule = set_str.size();
                
                poly value = stoul(set_str.substr(pos_valeur, pos_virgule - pos_valeur));
                map_xor[i].second[j][k] = value;

                pos_valeur = set_str.find_first_of("0123456789", pos_virgule + 1);
                k++;
            }

            pos = line.find("{", endPos);
            j++;
        }
        i++;
    }

    file.close();
}

int64_t find_set (poly val, poly set_op [], uint64_t look_start, uint64_t look_end) {
    if (look_start==look_end){
        return -1;
    }
    int64_t mid = (look_start + look_end)/2;
    int64_t test = val - set_op[mid];
    return (test?(test<0?find_set(val,set_op,look_start,mid):find_set(val,set_op,mid + 1,look_end)):mid);
}

int64_t find_map (poly val, pair_xor v [], uint64_t look_start, uint64_t look_end)   {
    if (look_start==look_end){
        return -1;
    }
    int64_t mid = (look_start + look_end)/2;
    int64_t test = val - v[mid].first;
    return (test?(test<0?find_map(val,v,look_start,mid):find_map(val,v,mid + 1,look_end)):mid);
}

int64_t find_map_lin (poly val, pair_lin v [], uint64_t look_start, uint64_t look_end)   {
    if (look_start==look_end){
        return -1;
    }
    int64_t mid = (look_start + look_end)/2;
    int64_t test = val - v[mid].first;
    return (test?(test<0?find_map_lin(val,v,look_start,mid):find_map_lin(val,v,mid + 1,look_end)):mid);
}

map<poly,pair<poly,poly>> create_map_lin_tab (uint32_t size, pair_lin map_lin [], uint32_t size_map_lin, set<poly> set_op) {
    parse_file_and_create_map_lin(size, map_lin);

    map<poly,pair<poly,poly>> mat_op;
    for (auto it = set_op.begin(); it != set_op.end(); it++)    {
        int32_t indice = find_map_lin(*it, map_lin, 0, size_map_lin);
        if ( indice != -1)   {
            mat_op[(*it)].first = map_lin[indice].second[0];
            mat_op[(*it)].second = map_lin[indice].second[1];
        }
        else {
            cerr<<"Error in create_map_lin_tab"<<endl;
        }
    }
    return mat_op;
}

