#include "config.h"
#include "poly.h"
#include "precalcul.h"
#include "non_lin.h"
#include "lin.h"
#include "get_and_print_implem.h"

using namespace std;


void print_implem_lin(implem * vect_map_sol, indexx * map_index, uint32_t nb_bits)  {
    uint32_t ind =0;
    for (uint32_t j=0; j<(*vect_map_sol).size(); j++)    {
        for (auto it_m = (*vect_map_sol)[j].begin(); it_m != (*vect_map_sol)[j].end(); it_m ++) {
            cout<<"\tuint8_t l_"<<ind<<" = ";
            for (uint32_t k=0; k<(*it_m).second.size(); k++)   {
                auto it = (*map_index).find((*it_m).second[k]);
                if (k==0)   {
                    if (it != (*map_index).end())  {
                        cout<<"l_"<<(*it).second;
                    }
                    else    {
                        print_monom((*it_m).second[k], nb_bits);
                    }
                }
                else {
                    if (it != (*map_index).end())  {
                        cout<<" ^ l_"<<(*it).second;
                    }
                    else    {
                        cout<<" ^ ";
                        print_monom((*it_m).second[k], nb_bits);
                    }
                }
            }
            (*map_index)[(*it_m).first] = ind ;
            cout<<";";
            cout<<endl;
            ind ++;
            
        }
    }
}

void print_implem(vector<vector<poly>> * Mat_op, uint32_t size, vector<poly> Ynon_lin, vector<poly> Ylin, vector<poly> Yneg, map<uint32_t, vector<poly>> map_sol, uint8_t precomputed_files)  {

    /* Récupère les opérations linéaires permettant d'obtenir les opérations non-linéaires nécessaires à l'implémentation */

    set<poly> set_op ; // Contient toutes les opérations non-linéaires de l'implem
    set<poly> op_lin; // Contient toutes les expressions linéaires qu'il faudra générer

    for (auto it = map_sol.begin(); it != map_sol.end(); it ++)   { 
    // map_sol contient la position à laquelle le bit doit être calculé en 1er élément et un vecteur contenant le bit (poly) et les opérations non-linéaires pour l'obtenir
        for (uint32_t i=1; i<(*it).second.size(); i++)   {
            set_op.insert((*it).second[i]);
        }
    }

    //cout<<"Size of set_op : "<<set_op.size()<<endl;
    uint32_t size_map_lin = nb_bits_to_size_set(size);
    pair_lin map_lin [size_map_lin]; 
    map<poly,pair<poly,poly>> mat_op; 

    if (precomputed_files == 0) {
        mat_op = create_map_lin(*Mat_op, set_op, size);
        for (auto it = mat_op.begin(); it != mat_op.end(); it++)    {
            if (hammingWeight(((*it).second).first) != 1){
                op_lin.insert(((*it).second).first);
            }
            if (hammingWeight(((*it).second).second) != 1){
                op_lin.insert(((*it).second).second);
            }
        }
    }
    if (precomputed_files == 1) {
        mat_op = create_map_lin_tab(size, map_lin, size_map_lin, set_op);
 // mat_op contient les opérations non-linéaires présentes dans l'implem en 1er paramètre et les op linéaires permettant de les calculer en second
        for (auto it = mat_op.begin(); it != mat_op.end(); it++)    {
            if (hammingWeight(((*it).second).first) != 1){
                op_lin.insert(((*it).second).first);
            }
            if (hammingWeight(((*it).second).second) != 1){
                op_lin.insert(((*it).second).second);
            }
        }
    }

    for (uint32_t i=0; i<Ylin.size(); i++)  {// Récupère les opérations linéaires présentes dans les bits de sortie
        if ( (hammingWeight(Ylin[i]) != 1) && ( hammingWeight(Ylin[i])) != 0){
            op_lin.insert(Ylin[i]);
        }
    }

    //cout<<"Size of op_lin : "<<op_lin.size()<<endl;

    vector<poly> v_op_lin (op_lin.begin(),op_lin.end());

    /* crée les sets pour l'optimisation linéaire*/
    set<poly> set_op_lin_p = create_set_op_lin(size);
    set<poly> * set_op_lin;
    set_op_lin = &set_op_lin_p;

    set<poly> set_op2_lin_p = create_set_op_lin2(set_op_lin);
    set<poly> * set_op2_lin;
    set_op2_lin = &set_op2_lin_p;

    uint32_t nb_xor = v_op_lin.size();
    implem vect_sol = return_implem_lin(set_op_lin, set_op2_lin, v_op_lin, nb_xor ,TIME_LIN);
    while (vect_sol.empty() == 1) {
        nb_xor ++;
        vect_sol = return_implem_lin(set_op_lin, set_op2_lin, v_op_lin, nb_xor ,TIME_LIN);
    }

    indexx map_index_bits_de_sortie; // Contient le bit de sortie et l'indice auquel il correspond
    for (uint32_t i=0; i<Ynon_lin.size(); i++) {
        map_index_bits_de_sortie[Ynon_lin[i]] = i;
    }

    implem * i;
    i = &vect_sol;

    indexx map_index_p;
    indexx * map_index; // Contient les opérations linéaires (de plus de deux monomes) et leur ordre d'apparition 
    map_index = &map_index_p;

    cout<<"The given s-box can be implemented by :"<<endl;
    cout<<endl;
    cout<<"uint32_t Sbox(uint32_t X, uint8_t size) {"<<endl;
    cout<<"\tuint32_t x[size];"<<endl;
    cout<<"\tfor(uint8_t b=0; b<size; b++)  {"<<endl;
    cout<<"\t\tx[b] = X&1ul;"<<endl;
    cout<<"\t\tX >>= 1;"<<endl;
    cout<<"\t}"<<endl;
    cout<<"\tuint32_t y[size];"<<endl;

    print_implem_lin(i, map_index, size);

    indexx map_index_q; //Contient une opération quadratique et son numéro 
    uint32_t index_q = 0;

    //cout<<"Size of map_sol : "<<map_sol.size()<<endl;
    for (auto it = map_sol.begin(); it != map_sol.end(); it ++)    { //On parcourt les bits de sortie dans l'ordre où ils ont été calculées
        
        for (uint32_t i=1; i < (*it).second.size(); i++ )  { // On parcourt les opérations non_linéaires associés, on commence donc à i=1
            auto k = map_index_q.find((*it).second[i]); // Si l'opération n'est pas encore apparu et n'est donc pas dans map_index_q, on l'ajoute et on l'affiche
            if ( k == map_index_q.end() )   {
                cout<<"\tuint8_t q"<<index_q<<" = (";
                map_index_q[(*it).second[i]] = index_q;
                index_q ++;
                
                auto it_lin = mat_op.find((*it).second[i]); // On récupère les opérations linéaires associés

                auto j = (*map_index).find((*it_lin).second.first);
                if (j != (*map_index).end())   { // Si l'opération est présente dans l'index on l'affiche sinon il s'agit d'un monôme seul
                    cout<<"l_"<<(*j).second;
                }
                else    {
                    if ((hammingWeight(((*it_lin).second).first)) == 1)  {
                        print_monom((*it_lin).second.first,size);
                    }
                    else {
                        cerr<<"Error in map_index : "<<endl;
                    }
                }
                cout<<" & ";
                j = (*map_index).find((*it_lin).second.second);
                if (j != (*map_index).end())   {
                    cout<<"l_"<<(*j).second;
                }
                else    {
                    if ((hammingWeight(((*it_lin).second).second)) == 1)  {
                        print_monom((*it_lin).second.second,size);
                    }
                    else {
                        cerr<<"Error in map_index : "<<endl;
                    }
                }
                cout<<")";
                uint32_t a = print_bit_lin_sup((*it_lin).second.first, (*it_lin).second.second, size);
                nb_xor +=a ;
                cout<<";"<<endl;
            }
        }

        auto ind = map_index_bits_de_sortie.find((*it).second[0]); // On récupère l'indice du bit de sortie
        if (ind != map_index_bits_de_sortie.end())  {
            
            cout<<"\ty["<<(*ind).second<<"] = ";

            for (uint32_t i=1; i < (*it).second.size(); i++ )  {
                if (i == 1)  {
                    auto k = map_index_q.find((*it).second[i]);
                    if ( k != map_index_q.end() )   {
                        cout<<"q"<<(*k).second;
                    }
                    else cerr<<"Error in map_index_q"<<endl;
                }
                else {
                    auto k = map_index_q.find((*it).second[i]);
                    if ( k != map_index_q.end() )   {
                        cout<<" ^ q"<<(*k).second;
                        nb_xor++;
                    }
                    else cerr<<"Error in map_index_q"<<endl;
                }
            }
            auto l = (*map_index).find(Ylin[(*ind).second]);
            if (Ylin[(*ind).second] != 0)   {
                cout<<" ^ ";
                nb_xor++;
            }
            if (l != (*map_index).end())   {
                cout<<"l_"<<(*l).second;
            }
            else    {
                if (hammingWeight(Ylin[(*ind).second]) == 1)  {
                    print_monom(Ylin[(*ind).second],size);
                }
            }
            if (Yneg[(*ind).second] == 1)
                cout<<" ^ 1";
            cout<<";"<<endl;
        }
        else {
            cout<<"Error in map_index_bits_de_sortie"<<endl;
        }
    }

    cout<<"\tuint32_t Y = 0;"<<endl;
    cout<<"\tfor(uint8_t b=0; b<size; b++) {"<<endl;
    cout<<"\t\tY ^= ((Y>>b) ^ y[b]) << b;"<<endl;
    cout<<"\t}"<<endl;
    cout<<"\treturn Y;"<<endl;
    cout<<"}"<<endl;

    cout<<endl<<"Number of AND : "<<map_index_q.size() <<endl<<"Number of XOR : "<<nb_xor<<endl;
}

void lut_to_implems (uint32_t lut[], uint32_t size_in, uint32_t size_out, int nb_sol, uint32_t nb_and_max, uint64_t time_max, uint8_t precomputed_files)  {

    cout<<"Begin pre-calculus "<<endl;
    time_t now = chrono::system_clock::to_time_t(chrono::system_clock::now());
    cout <<"Time is " << ctime(&now) << endl;

    uint32_t nb_elem = 1ul<<size_in;

    uint32_t size_set = nb_bits_to_size_set(size_in);
    poly set_op [size_set];

    uint32_t size_map_xor = nb_bits_to_size_map_xor(size_in);
    pair_xor * map_xor = new pair_xor[size_map_xor];

    vector<vector<poly>> * Mat_op = NULL;
    vector<vector<poly>> Mat_op_p;
    
    
    if (precomputed_files == 0){

        set<poly> * set_op_s = NULL;
        set<poly> set_op_p;

        map<poly,set<set<poly>>> * map_xor_m = NULL;
        map<poly,set<set<poly>>> map_xor_p;
        

        Mat_op_p = create_mat_op(size_in);
        Mat_op = &Mat_op_p;

        set_op_p = create_set_op(Mat_op);
        set_op_s = &set_op_p;

        map_xor_p = create_map(set_op_s);
        map_xor_m = &map_xor_p;

        uint32_t indice = 0;
        for (auto it = (*set_op_s).begin(); it != (*set_op_s).end(); it ++, indice ++)    {
            set_op[indice] = *it;
        }

        cout<<"set_op done"<<endl;

        uint32_t indice_key = 0;
        for (auto it = (*map_xor_m).begin(); it != (*map_xor_m).end(); it ++)    {
            map_xor[indice_key].first = (*it).first;
            uint32_t indice_1 = 0;
            for (auto it_set = (*it).second.begin(); it_set != (*it).second.end(); it_set ++){
                uint32_t indice_2 = 0;
                for (auto j = (*it_set).begin(); j != (*it_set).end(); j++){
                    map_xor[indice_key].second[indice_1][indice_2] = *j;
                    indice_2 ++;
                }
                indice_1 ++;
            }
            indice_key ++;
        }

        cout<<" map_xor done"<<endl;
    }
    if (precomputed_files == 1) {
        parse_file_and_create_set(size_in, set_op);
        parse_file_and_create_map_xor(size_in, map_xor);
    }

    // Compute the ANF
    uint32_t ** anf = (uint32_t**)malloc(size_in * sizeof(uint32_t*));
    for(uint32_t i=0; i<size_in; i++)   {
        anf[i] = (uint32_t*)calloc(nb_elem/32 , sizeof(uint32_t));
    }
    lut_to_anf(anf, lut, size_in, size_out);

    vector<poly> Y;
    Y = anf_to_poly_non_lin(anf,size_in,size_out);
    cout<<"Y is equal to : ";
    for (uint32_t i=0; i<Y.size(); i++) {
        cout<<Y[i]<<" ";
    }
    cout<<endl;

    vector<poly> Ylin;
    Ylin = anf_to_poly_lin(anf,size_in,size_out);

    vector<poly> Yneg;
    Yneg = anf_to_poly_neg(anf,size_in,size_out);

    cout<<"End of pre_calculus "<<endl;
    now = chrono::system_clock::to_time_t(chrono::system_clock::now());
    cout <<"Time is " << ctime(&now) << endl;
    
    vector<map<uint32_t,vector<poly>>> vect_implem;
    if (nb_and_max != 0)    {
        vect_implem = return_implem(set_op, size_set, map_xor, size_map_xor, Y, nb_and_max, nb_sol, time_max);
    }
    else {
        if (size_in == 4)  {
            nb_and_max = 4;
            vect_implem = return_implem(set_op, size_set, map_xor, size_map_xor, Y, nb_and_max, nb_sol, time_max);
        }
        if (size_in == 5)  {
            nb_and_max = 7;
            vect_implem = return_implem(set_op, size_set, map_xor, size_map_xor, Y, nb_and_max, nb_sol, time_max);
        }
        if (size_in == 6)  {
            nb_and_max = 9;
            vect_implem = return_implem(set_op, size_set, map_xor, size_map_xor, Y, nb_and_max, nb_sol, time_max);
        }
        if (size_in == 7)  {
            nb_and_max = 12;
            vect_implem = return_implem(set_op, size_set, map_xor, size_map_xor, Y, nb_and_max, nb_sol, time_max);
        }
        if (size_in == 8)  {
            nb_and_max = 16;
            vect_implem = return_implem(set_op, size_set, map_xor, size_map_xor, Y, nb_and_max, nb_sol, time_max);
        }
        while (vect_implem.empty() != 1)    {
            cout<<"We can get an implementation using "<<nb_and_max<<" AND gates"<<endl;
            nb_and_max --;
            cout<<"Testing for "<<nb_and_max<<" AND gates"<<endl;
            vect_implem = return_implem(set_op, size_set, map_xor, size_map_xor, Y, nb_and_max, 1, time_max);
        }
        vect_implem = return_implem(set_op, size_set, map_xor, size_map_xor, Y, nb_and_max +1 ,nb_sol ,time_max);
    }
    
    cout<<vect_implem.size()<<" implementations have been found"<<endl;
    cout<<endl;
    for (uint8_t i=0; i<vect_implem.size(); i++)  {
        print_implem(Mat_op, size_in, Y, Ylin, Yneg, vect_implem[i], precomputed_files);
    }

    for (uint32_t i=0; i<size_in; i++)
        free(anf[i]);
    free(anf);

    delete [] map_xor;
}
