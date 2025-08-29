#include "config.h"
#include "poly.h"
#include "precalcul.h"
#include "non_lin.h"

/*!
* \var stop
* \brief Variable to make the program stop when the time limit has been exceeded or when the required number of solutions has been reached.
*/
static int stop = 0;

vector<set<poly>> test_xor(poly x, vector<poly> op_selec, uint8_t a, poly set_op [], uint32_t size_set, pair_xor map_xor [], uint32_t size_map_xor, uint8_t b) {
    vector<set<poly>> sol;
    poly elem1;
    poly elem2;
    poly elem3;
    poly elem4;
    poly elem5;
    poly elem6;

    if ( (a==2) && (b==0) ){
        for (uint8_t i= 0; i < op_selec.size() && !stop ; i++) {
            elem1 = x ^ op_selec[i];
            for (uint8_t j= i+1; j < op_selec.size(); j++) {
                if (op_selec[j] == elem1) {
                    set<poly> op;
                    sol.push_back(op);
                }
            }
        }
    }
    if ( (a==3) && (b==0) ){
        for (uint8_t i= 0; i < op_selec.size() && !stop ; i++) {
            elem1 = x ^ op_selec[i];
            for (uint8_t j= i+1; j < op_selec.size(); j++) {
                elem2 = elem1 ^ op_selec[j];
                for (uint8_t k= j+1; k < op_selec.size(); k++) {
                    if (op_selec[k] == elem2) {
                        set<poly> op;
                        sol.push_back(op);
                    }
                }
            }
        }
    }
    if ( (a==4) && (b==0) ){
        for (uint8_t i= 0; i < op_selec.size() && !stop ; i++) {
            elem1 = x ^ op_selec[i];
            for (uint8_t j= i+1; j < op_selec.size(); j++) {
                elem2 = elem1 ^ op_selec[j];
                for (uint8_t k= j+1; k < op_selec.size(); k++) {
                    elem3 = elem2 ^ op_selec[k];
                    for (uint8_t l= k+1; l < op_selec.size(); l++) {
                        if (op_selec[l] == elem3) {
                            set<poly> op;
                            sol.push_back(op);
                        }
                    }
                }
            }
        }
    }
    if ( (a==5) && (b==0) ){
        for (uint8_t i= 0; i < op_selec.size() && !stop ; i++) {
            elem1 = x ^ op_selec[i];
            for (uint8_t j= i+1; j < op_selec.size(); j++) {
                elem2 = elem1 ^ op_selec[j];
                for (uint8_t k= j+1; k < op_selec.size(); k++) {
                    elem3 = elem2 ^ op_selec[k];
                    for (uint8_t l= k+1; l < op_selec.size(); l++) {
                        elem4 = elem3 ^ op_selec[l];
                        for (uint8_t m= l+1; m < op_selec.size(); m++) {
                            if (op_selec[m] == elem4) {
                                set<poly> op;
                                sol.push_back(op);
                            }
                        }
                    }
                }
            }
        }
    }
    if ( (a==6) && (b==0) ){
        for (uint8_t i= 0; i < op_selec.size() && !stop ; i++) {
            elem1 = x ^ op_selec[i];
            for (uint8_t j= i+1; j < op_selec.size(); j++) {
                elem2 = elem1 ^ op_selec[j];
                for (uint8_t k= j+1; k < op_selec.size(); k++) {
                    elem3 = elem2 ^ op_selec[k];
                    for (uint8_t l= k+1; l < op_selec.size(); l++) {
                        elem4 = elem3 ^ op_selec[l];
                        for (uint8_t m= l+1; m < op_selec.size(); m++) {
                            elem5 = elem4 ^ op_selec[m];
                            for (uint8_t n= m+1; n < op_selec.size(); n++) {
                                if (op_selec[n] == elem5) {
                                    set<poly> op;
                                    sol.push_back(op);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ( (a==7) && (b==0) ){
        for (uint8_t i= 0; i < op_selec.size() && !stop ; i++) {
            elem1 = x ^ op_selec[i];
            for (uint8_t j= i+1; j < op_selec.size(); j++) {
                elem2 = elem1 ^ op_selec[j];
                for (uint8_t k= j+1; k < op_selec.size(); k++) {
                    elem3 = elem2 ^ op_selec[k];
                    for (uint8_t l= k+1; l < op_selec.size(); l++) {
                        elem4 = elem3 ^ op_selec[l];
                        for (uint8_t m= l+1; m < op_selec.size(); m++) {
                            elem5 = elem4 ^ op_selec[m];
                            for (uint8_t n= m+1; n < op_selec.size(); n++) {
                                elem6 = elem5 ^ op_selec[n];
                                for (uint8_t p = n+1; p < op_selec.size(); p++) {
                                    if (op_selec[p] == elem6) {
                                        set<poly> op;
                                        sol.push_back(op);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ( (a==1) && (b==1) ){
        for (uint8_t i= 0; i < op_selec.size() && !stop ; i++) {
            elem1 = x ^ op_selec[i];
            int32_t indice; 
            indice = find_set(elem1, set_op, 0, size_set);
            if (indice != -1)   {
                sol.push_back({set_op[indice]});
            }
        }
    }
    if ( (a==2) && (b==1) ){
        for (uint8_t i= 0; i < op_selec.size() && !stop ; i++) {
            elem1 = x ^ op_selec[i];
            for (uint8_t j= i+1; j < op_selec.size(); j++) {
                elem2 = elem1 ^ op_selec[j];
                int32_t indice; 
                indice = find_set(elem2, set_op, 0, size_set);
                if (indice != -1)   {
                    sol.push_back({set_op[indice]});
                }
            }
        }
    }
    if ( (a==3) && (b==1) ){
        for (uint8_t i= 0; i < op_selec.size() && !stop ; i++) {
            elem1 = x ^ op_selec[i];
            for (uint8_t j= i+1; j < op_selec.size(); j++) {
                elem2 = elem1 ^ op_selec[j];
                for (uint8_t k= j+1; k < op_selec.size(); k++) {
                    elem3 = elem2 ^ op_selec[k];
                    int32_t indice; 
                    indice = find_set(elem3, set_op, 0, size_set);
                    if (indice != -1)   {
                        sol.push_back({set_op[indice]});
                    }
                }
            }
        }
    }
    if ( (a==4) && (b==1) ){
        for (uint8_t i= 0; i < op_selec.size() && !stop ; i++) {
            elem1 = x ^ op_selec[i];
            for (uint8_t j= i+1; j < op_selec.size(); j++) {
                elem2 = elem1 ^ op_selec[j];
                for (uint8_t k= j+1; k < op_selec.size(); k++) {
                    elem3 = elem2 ^ op_selec[k];
                    for (uint8_t l= k+1; l < op_selec.size(); l++) {
                        elem4 = elem3 ^ op_selec[l];
                        int32_t indice; 
                        indice = find_set(elem4, set_op, 0, size_set);
                        if (indice != -1)   {
                            sol.push_back({set_op[indice]});
                        }
                    }
                }
            }
        }
    }
    if ( (a==5) && (b==1) ){
        for (uint8_t i= 0; i < op_selec.size() && !stop ; i++) {
            elem1 = x ^ op_selec[i];
            for (uint8_t j= i+1; j < op_selec.size(); j++) {
                elem2 = elem1 ^ op_selec[j];
                for (uint8_t k= j+1; k < op_selec.size(); k++) {
                    elem3 = elem2 ^ op_selec[k];
                    for (uint8_t l= k+1; l < op_selec.size(); l++) {
                        elem4 = elem3 ^ op_selec[l];
                        for (uint8_t m= l+1; m < op_selec.size(); m++) {
                            elem5 = elem4 ^ op_selec[m];
                            int32_t indice; 
                            indice = find_set(elem5, set_op, 0, size_set);
                            if (indice != -1)   {
                                sol.push_back({set_op[indice]});
                            }
                        }
                    }
                }
            }
        }
    }
    if ( (a==6) && (b==1) ){
        for (uint8_t i= 0; i < op_selec.size() && !stop ; i++) {
            elem1 = x ^ op_selec[i];
            for (uint8_t j= i+1; j < op_selec.size(); j++) {
                elem2 = elem1 ^ op_selec[j];
                for (uint8_t k= j+1; k < op_selec.size(); k++) {
                    elem3 = elem2 ^ op_selec[k];
                    for (uint8_t l= k+1; l < op_selec.size(); l++) {
                        elem4 = elem3 ^ op_selec[l];
                        for (uint8_t m= l+1; m < op_selec.size(); m++) {
                            elem5 = elem4 ^ op_selec[m];
                            for (uint8_t n= m+1; n < op_selec.size(); n++) {
                                elem6 = elem5 ^ op_selec[n];
                                int32_t indice; 
                                indice = find_set(elem6, set_op, 0, size_set);
                                if (indice != -1)   {
                                    sol.push_back({set_op[indice]});
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ( (a==1) && (b==2) ){
        for (uint8_t i= 0; i < op_selec.size() && !stop ; i++) {
            elem1 = x ^ op_selec[i];
            int32_t indice;
            indice = find_map(elem1, map_xor, 0, size_map_xor);
            if (indice != -1)   {
                for (uint32_t j=0; j<10; j++)   {
                    set<poly> op;
                    op.insert(map_xor[indice].second[j][0]);
                    op.insert(map_xor[indice].second[j][1]);
                    sol.push_back(op);
                }
            }
        }
    }
    if ( (a==2) && (b==2) ){
        for (uint8_t i=0; i<op_selec.size() && !stop ; i++) {
            elem1 = x ^ op_selec[i];
            for (uint8_t j=i+1; j<op_selec.size(); j++) {
                elem2 = elem1 ^ op_selec[j];
                int32_t indice;
                indice = find_map(elem2, map_xor, 0, size_map_xor);
                if (indice != -1)   {
                    for (uint32_t k=0; k<10; k++)   {
                        set<poly> op;
                        op.insert(map_xor[indice].second[k][0]);
                        op.insert(map_xor[indice].second[k][1]);
                        sol.push_back(op);
                    }
                }
            }
        }
    }
    if ( (a==3) && (b==2) ){
        for (uint8_t i=0; i<op_selec.size() && !stop ; i++) {
            elem1 = x ^ op_selec[i];
            for (uint8_t j=i+1; j<op_selec.size(); j++) {
                elem2 = elem1 ^ op_selec[j];
                for (uint8_t k=j+1; k<op_selec.size(); k++) {
                    elem3 = elem2 ^ op_selec[k];
                    int32_t indice;
                    indice = find_map(elem3, map_xor, 0, size_map_xor);
                    if (indice != -1)   {
                        for (uint32_t l=0; l<10; l++)   {
                            set<poly> op;
                            op.insert(map_xor[indice].second[l][0]);
                            op.insert(map_xor[indice].second[l][1]);
                            sol.push_back(op);
                        }
                    }
                }
            }
        }
    }
    if ( (a==4) && (b==2) ){
        for (uint8_t i=0; i<op_selec.size() && !stop ; i++) {
            elem1 = x ^ op_selec[i];
            for (uint8_t j=i+1; j<op_selec.size(); j++) {
                elem2 = elem1 ^ op_selec[j];
                for (uint8_t k=j+1; k<op_selec.size(); k++) {
                    elem3 = elem2 ^ op_selec[k];
                    for (uint8_t l=k+1; l<op_selec.size(); l++) {
                        elem4 = elem3 ^ op_selec[l];
                        int32_t indice;
                        indice = find_map(elem4, map_xor, 0, size_map_xor);
                        if (indice != -1)   {
                            for (uint32_t m=0; m<10; m++)   {
                                set<poly> op;
                                op.insert(map_xor[indice].second[m][0]);
                                op.insert(map_xor[indice].second[m][1]);
                                sol.push_back(op);
                            }
                        }
                    }
                }
            }
        }
    }
    if ( (a==5) && (b==2) ){
        for (uint8_t i=0; i<op_selec.size() && !stop ; i++) {
            elem1 = x ^ op_selec[i];
            for (uint8_t j=i+1; j<op_selec.size(); j++) {
                elem2 = elem1 ^ op_selec[j];
                for (uint8_t k=j+1; k<op_selec.size(); k++) {
                    elem3 = elem2 ^ op_selec[k];
                    for (uint8_t l=k+1; l<op_selec.size(); l++) {
                        elem4 = elem3 ^ op_selec[l];
                        for (uint8_t m=l+1; m<op_selec.size(); m++) {
                            elem5 = elem4 ^ op_selec[m];
                            int32_t indice;
                            indice = find_map(elem5, map_xor, 0, size_map_xor);
                            if (indice != -1)   {
                                for (uint32_t n=0; n<10; n++)   {
                                    set<poly> op;
                                    op.insert(map_xor[indice].second[n][0]);
                                    op.insert(map_xor[indice].second[n][1]);
                                    sol.push_back(op);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ( (a==1) && (b==3) ){
        for (uint8_t i=0; i<op_selec.size() && !stop ; i++) {
            elem1 = x ^ op_selec[i];
            for (uint32_t j=0; j < size_set && !stop ; j++) {
                elem2 = elem1 ^ set_op[j];
                int32_t indice;
                indice = find_map(elem2, map_xor, 0, size_map_xor);
                if (indice != -1)   {
                    for (uint32_t l=0; l<10; l++)   {
                        set<poly> op;
                        op.insert(set_op[j]);
                        op.insert(map_xor[indice].second[l][0]);
                        op.insert(map_xor[indice].second[l][1]);
                        sol.push_back(op);
                    }
                }
            }
        }
    }
    if ( (a==2) && (b==3) ){
        for (uint8_t i=0; i<op_selec.size() && !stop ; i++) {
            elem1 = x ^ op_selec[i];
            for (uint8_t j=i+1; j<op_selec.size(); j++) {
                elem2 = elem1 ^ op_selec[j];
                for (uint32_t k=0; k < size_set && !stop ; k++) {
                    elem3 = elem2 ^ set_op[k];
                    int32_t indice;
                    indice = find_map(elem3, map_xor, 0, size_map_xor);
                    if (indice != -1)   {
                        for (uint32_t l=0; l<10; l++)   {
                            set<poly> op;
                            op.insert(set_op[k]);
                            op.insert(map_xor[indice].second[l][0]);
                            op.insert(map_xor[indice].second[l][1]);
                            sol.push_back(op);
                        }
                    }
                }
            }
        }
    }
    if ( (a==3) && (b==3) ){
        for (uint8_t i=0; i<op_selec.size() && !stop ; i++) {
            elem1 = x ^ op_selec[i];
            for (uint8_t j=i+1; j<op_selec.size(); j++) {
                elem2 = elem1 ^ op_selec[j];
                for (uint8_t k=j+1; k<op_selec.size(); k++) {
                    elem3 = elem2 ^ op_selec[k];
                    for (uint32_t l=0; l < size_set && !stop ; l++) {
                        elem4 = elem3 ^ set_op[l];
                        int32_t indice;
                        indice = find_map(elem4, map_xor, 0, size_map_xor);
                        if (indice != -1)   {
                            for (uint32_t m=0; m<10; m++)   {
                                set<poly> op;
                                op.insert(set_op[l]);
                                op.insert(map_xor[indice].second[m][0]);
                                op.insert(map_xor[indice].second[m][1]);
                                sol.push_back(op);
                            }
                        }
                    }
                }
            }
        }
    }
    if ( (a==4) && (b==3) ){
        for (uint8_t i=0; i<op_selec.size() && !stop ; i++) {
            elem1 = x ^ op_selec[i];
            for (uint8_t j=i+1; j<op_selec.size(); j++) {
                elem2 = elem1 ^ op_selec[j];
                for (uint8_t k=j+1; k<op_selec.size(); k++) {
                    elem3 = elem2 ^ op_selec[k];
                    for (uint8_t l=k+1; l<op_selec.size(); l++) {
                        elem4 = elem3 ^ op_selec[l];
                        for (uint32_t m=0; m < size_set && !stop ; m++) {
                            elem5 = elem4 ^ set_op[m];
                            int32_t indice;
                            indice = find_map(elem5, map_xor, 0, size_map_xor);
                            if (indice != -1)   {
                                for (uint32_t n=0; n<10; n++)   {
                                    set<poly> op;
                                    op.insert(set_op[m]);
                                    op.insert(map_xor[indice].second[n][0]);
                                    op.insert(map_xor[indice].second[n][1]);
                                    sol.push_back(op);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (a==0)   {
        if (b==1)   {
            int32_t indice;
            indice = find_set(x, set_op, 0, size_set);
            if (indice != -1)   {
                sol.push_back({set_op[indice]});
            }
        }
        if (b==2)   {
            int32_t indice;
            indice = find_map(x, map_xor, 0, size_map_xor);
            if (indice != -1)   {
                for (uint32_t i=0; i<10; i++)   {
                    set<poly> op;
                    op.insert(map_xor[indice].second[i][0]);
                    op.insert(map_xor[indice].second[i][1]);
                    sol.push_back(op);
                }
            }
        }
        if (b==3)   {
            for (uint32_t i=0; i < size_set && !stop ; i++) {
                elem1 = x ^ set_op[i];
                int32_t indice;
                indice = find_map(elem1, map_xor, 0, size_map_xor);
                if (indice != -1)   {
                    for (uint32_t j=0; j<10; j++)   {
                        set<poly> op;
                        op.insert(set_op[i]);
                        op.insert(map_xor[indice].second[j][0]);
                        op.insert(map_xor[indice].second[j][1]);
                        sol.push_back(op);
                    }
                }
            }
        }
        /*if (b==4)   {
            for (uint32_t i=0; i < size_map_xor && !stop ; i++) {
                elem1 = x ^ map_xor[i].first;
                int32_t indice;
                indice = find_map(elem1, map_xor, 0, size_map_xor);
                if (indice != -1)   {
                    for (uint32_t j=0; j<10; j++)   {
                        for (uint32_t k=0; k<10; k++)   {
                            set<poly> op;
                            op.insert(map_xor[i].second[k][0]);
                            op.insert(map_xor[i].second[k][1]);
                            op.insert(map_xor[indice].second[j][0]);
                            op.insert(map_xor[indice].second[j][1]);
                            sol.push_back(op);
                        }
                    }
                }
            }
        }*/

    }
    sol = remove_duplicates_set(sol);
    return sol;
}

vector<set<poly>> Test_xor (poly x, set<poly> op_selec, poly set_op [] , uint32_t size_set, pair_xor map_xor[], uint32_t size_map_xor, uint32_t nb_op)   {
    vector<poly> v_op_selec (op_selec.begin(),op_selec.end());
    vector<set<poly>> res;
    for (uint32_t i=0; i<nb_op +1; i++) {
        for (uint32_t j=0; j<op_selec.size() +1 && !stop ; j++) {
            vector<set<poly>> sol = test_xor(x, v_op_selec, j, set_op, size_set, map_xor, size_map_xor, i);
            //If the vector is not empty, return the possibles sets uptated.
            if (sol.empty() != 1) {
                for (uint32_t k=0; k<sol.size(); k++)  {
                    set<poly> op_selec_mis_a_jour = op_selec;
                    for (auto it = sol[k].begin(); it != sol[k].end(); it++)    {
                        op_selec_mis_a_jour.insert(*it);
                    }
                    res.push_back(op_selec_mis_a_jour);
                }
                return res;
            }
        }
    }
    return res;
}

map<uint32_t, vector<poly>> set_to_implem (set<poly> set_op, vector<poly> Y, indexx ind){
    // test_xor allows to obtain an output bit by xoring up to 7 operations, so we need to test until then.
    map<uint32_t, vector<poly>> map_sol; // Contains the position at which the bit must be calculated as the 1st element and a vector containing the bit (poly)at first place and then the non-linear operations to obtain this bit.
    for (uint32_t i=0; i<Y.size(); i++) {
        bool test = false;

        vector<poly> imp;
        poly elem1;
        poly elem2;
        poly elem3;
        poly elem4;
        poly elem5;
        poly elem6;

        auto itt = ind.find(Y[i]);

        for (auto j= set_op.begin(); j != set_op.end() && !test; j++)  {
            if (*j == Y[i])  {
                imp = {Y[i],*j};
                map_sol[(*itt).second] = imp;
                test = true;
                break;
            }
        }

        for (auto j= set_op.begin(); j != set_op.end() && !test; j++)  {
            for (auto k = next(j); k!= set_op.end() && !test; k++)  {
                elem1 = *j ^ *k;
                if (elem1 == Y[i])  {
                    imp = {Y[i],*j,*k};
                    map_sol[(*itt).second] = imp;
                    test = true;
                    break;
                }
            }
        }
        for (auto j= set_op.begin(); j != set_op.end() && !test; j++)  {
            for (auto k = next(j); k!= set_op.end() && !test; k++)  {
                elem1 = *j ^ *k;
                for (auto l = next(k); l!= set_op.end() && !test; l++)  {
                    elem2 = elem1 ^ *l;
                    if (elem2 == Y[i])  {
                        imp = {Y[i],*j,*k,*l};
                        map_sol[(*itt).second] = imp;
                        test = true;
                        break;
                    }
                }
            }
        }
        for (auto j= set_op.begin(); j != set_op.end() && !test; j++)  {
            for (auto k = next(j); k!= set_op.end() && !test; k++)  {
                elem1 = *j ^ *k;
                for (auto l = next(k); l!= set_op.end() && !test; l++)  {
                    elem2 = elem1 ^ *l;
                    for (auto m = next(l); m!= set_op.end() && !test; m++)  {
                        elem3 = elem2 ^ *m;
                        if (elem3 == Y[i])  {
                            imp = {Y[i], *j ,*k ,*l ,*m};
                            map_sol[(*itt).second] = imp;
                            test = true;
                            break;
                        }
                    }
                }
            }
        }
        for (auto j= set_op.begin(); j != set_op.end() && !test; j++)  {
            for (auto k = next(j); k!= set_op.end() && !test; k++)  {
                elem1 = *j ^ *k;
                for (auto l = next(k); l!= set_op.end() && !test; l++)  {
                elem2 = elem1 ^ *l;
                    for (auto m = next(l); m!= set_op.end() && !test; m++)  {
                        elem3 = elem2 ^ *m;
                        for (auto n = next(m); n!= set_op.end() && !test ; n++)  {
                            elem4 = elem3 ^ *n;   
                            if (elem4 == Y[i])  {
                                imp = {Y[i], *j, *k, *l, *m, *n};
                                map_sol[(*itt).second] = imp;
                                test = true;
                                break;
                            }
                        }
                    }
                }
            }
        }
        for (auto j= set_op.begin(); j != set_op.end() && !test; j++)  {
            for (auto k = next(j); k!= set_op.end() && !test; k++)  {
                elem1 = *j ^ *k;
                for (auto l = next(k); l!= set_op.end() && !test; l++)  {
                    elem2 = elem1 ^ *l;
                    for (auto m = next(l); m!= set_op.end() && !test; m++)  {
                        elem3 = elem2 ^ *m;
                        for (auto n = next(m); n!= set_op.end() && !test ; n++)  {
                            elem4 = elem3 ^ *n;
                            for (auto p = next(n); p!= set_op.end() && !test ; p++)  {
                                elem5 = elem4 ^ *p;
                                if (elem5== Y[i])  {
                                    imp = {Y[i], *j, *k, *l, *m, *n, *p};
                                    map_sol[(*itt).second] = imp;
                                    test = true;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
        for (auto j= set_op.begin(); j != set_op.end() && !test; j++)  {
            for (auto k = next(j); k!= set_op.end() && !test; k++)  {
                elem1 = *j ^ *k;
                for (auto l = next(k); l!= set_op.end() && !test; l++)  {
                    elem2 = elem1 ^ *l;
                    for (auto m = next(l); m!= set_op.end() && !test; m++)  {
                        elem3 = elem2 ^ *m;
                        for (auto n = next(m); n!= set_op.end() && !test ; n++)  {
                            elem4 = elem3 ^ *n;
                            for (auto p = next(n); p!= set_op.end() && !test ; p++)  {
                                elem5 = elem4 ^ *p;
                                for (auto q = next(p); q!= set_op.end() && !test ; q++)  {
                                    elem6 = elem5 ^ *q;
                                    if (elem6== Y[i])  {
                                        imp = {Y[i], *j, *k, *l, *m, *n, *p, *q};
                                        map_sol[(*itt).second] = imp;
                                        test = true;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return map_sol;
}

vector<implem_non_lin> remove_duplicates_impl(vector<implem_non_lin> vect_implem) {
    set<set<poly>> set_intermediaire;
    vector<implem_non_lin> res;
    for (uint32_t i=0; i<vect_implem.size(); i++)   {
        uint8_t comp = set_intermediaire.size();
        set_intermediaire.insert(vect_implem[i].op);
        uint8_t taille = set_intermediaire.size();
        if (comp != taille) {
            res.push_back(vect_implem[i]);
        }
    }
    return res;
}

vector<map<uint32_t,vector<poly>>> return_implem (poly set_op[], uint32_t size_set, pair_xor map_xor [], uint32_t size_map_xor, vector<poly> Y, uint8_t nb_and_max, int nb_sol_wanted, uint64_t time_max)    {
    /* Si nb_sol_wanted = -1, on renvoit toutes les implem */
    auto begin = chrono::steady_clock::now();
    stop = 0;
    vector<implem_non_lin> vect_implem;
    int nb_sol = 0;
   
    /* Définit les paramètres initiaux*/
    uint8_t nb_op_init = nb_and_max;
    set<poly> op_selec_init;
    vector<poly> lignes_m_init = Y;

    bool is_fully_lin = true;
    for (uint32_t i=0; i<Y.size(); i++){
        if (Y[i] != 0){
            is_fully_lin = false;
        }
    }

    if (is_fully_lin){
        implem_non_lin imp_null;
        set<poly> set_null;
        indexx i_null;
        imp_null.op = set_null;
        imp_null.i = i_null;
        vect_implem.push_back(imp_null);
        stop = 1;
        cout<<"The s-box is fully linear, no non-linear part needed"<<endl;
    }

    /* STEP 1 :  */
    
    cout<<"Begin step 1"<<endl;
    for (uint32_t i=0; i<lignes_m_init.size() && !stop; i++) {
        int32_t indice = find_set(lignes_m_init[i], set_op, 0, size_set);
        if (indice != -1)   {
            cout<<"We can obtain line "<<i<<" with 0 XOR"<<endl;

            vector<poly> lignes_m;
            lignes_m = supp(lignes_m_init[i], lignes_m_init); // On supprime la i-ème ligne des lignes manquantes

            set<poly> op_selec1 = {set_op[indice]};
            uint8_t nb_op = nb_op_init - 1;
            vector<vector<poly>> vect_perm = Permutations(lignes_m);
            uint8_t nb_lignes = lignes_m.size();

            if (nb_lignes == 3) {
                #pragma omp parallel shared(stop)
                {
                    bool stop_local = false;
                    #pragma omp for schedule(static)

                    for (uint32_t k=0; k<vect_perm.size(); k++)    {

                        auto Now = chrono::steady_clock::now();
                        auto time_spent = chrono::duration_cast<chrono::duration<double>>(Now - begin);
                        if (time_spent.count() > time_max)  {
                            #pragma omp atomic write
                            stop = 1;
                        }

                        if (stop_local) {
                                continue;
                            }
                        if (stop) {
                            stop_local = true;
                            continue;
                        }

                        poly l1 = vect_perm[k][0]; //1ère ligne manquante
                        poly l2 = vect_perm[k][1]; //2ème ligne manquante
                        poly l3 = vect_perm[k][2]; //3ème ligne manquante
                        vector<set<poly>> vect_op_selec2 = Test_xor(l1, op_selec1, set_op, size_set, map_xor, size_map_xor, nb_op);

                        if (vect_op_selec2.empty() == 1)   {
                                continue;
                            }
                        for (uint32_t l=0; l<vect_op_selec2.size() && !stop; l++)    {
                            set<poly> op_selec2 = vect_op_selec2[l];
                            uint8_t nb_op2 = nb_op_init - op_selec2.size();
                            vector<set<poly>> vect_op_selec3 = Test_xor(l2, op_selec2, set_op, size_set, map_xor, size_map_xor, nb_op2);
                            if (vect_op_selec3.empty() == 1)   {
                                    continue;    
                            }
                            for (uint32_t m=0; m<vect_op_selec3.size() && !stop; m++)    {
                                set<poly> op_selec3 = vect_op_selec3[m];
                                uint8_t nb_op3 = nb_op_init - op_selec3.size();
                                vector<set<poly>> vect_op_selec4 = Test_xor(l3, op_selec3, set_op, size_set, map_xor, size_map_xor, nb_op3);
                                if (vect_op_selec4.empty() == 1)   {
                                    continue;
                                }
                                for (uint32_t n=0; n<vect_op_selec4.size() && !stop; n++)    {
                                    set<poly> op_selec4 = vect_op_selec4[n];
                                    implem_non_lin imp;
                                    imp.op = op_selec4;
                                    imp.i[lignes_m_init[i]] = 0;
                                    imp.i[l1] = 1;
                                    imp.i[l2] = 2;
                                    imp.i[l3] = 3;
                                    #pragma omp critical
                                    {
                                        vect_implem.push_back(imp);
                                        cout<<"Solution found with : "<<omp_get_thread_num()<<endl;
                                        vect_implem = remove_duplicates_impl(vect_implem);
                                        nb_sol = vect_implem.size();
                                    }
                                    if (nb_sol_wanted != -1) {
                                        if (nb_sol >= nb_sol_wanted) {
                                            #pragma omp atomic write
                                            stop = 1;
                                            cout<<"Number of wanted solutions reached"<<endl;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (nb_lignes == 4) {
                #pragma omp parallel shared(stop)
                {
                    bool stop_local = false;
                    #pragma omp for schedule(static)

                    for (uint32_t k=0; k<vect_perm.size(); k++)    {

                        auto Now = chrono::steady_clock::now();
                        auto time_spent = chrono::duration_cast<chrono::duration<double>>(Now - begin);
                        if (time_spent.count() > time_max)  {
                            #pragma omp atomic write
                            stop = 1;
                        }

                        if (stop_local) {
                                continue;
                            }
                        if (stop) {
                            stop_local = true;
                            continue;
                        }
                            
                        poly l1 = vect_perm[k][0]; //1ère ligne manquante
                        poly l2 = vect_perm[k][1]; //2ème ligne manquante
                        poly l3 = vect_perm[k][2]; //3ème ligne manquante
                        poly l4 = vect_perm[k][3]; //4ème ligne manquante
                        vector<set<poly>> vect_op_selec2 = Test_xor(l1, op_selec1, set_op, size_set, map_xor, size_map_xor, nb_op);

                        if (vect_op_selec2.empty() == 1)   {
                            continue;
                        }
                        for (uint32_t l=0; l<vect_op_selec2.size() && !stop; l++)    {
                            set<poly> op_selec2 = vect_op_selec2[l];
                            uint8_t nb_op2 = nb_op_init - op_selec2.size();
                            vector<set<poly>> vect_op_selec3 = Test_xor(l2, op_selec2, set_op, size_set, map_xor, size_map_xor, nb_op2);
                            if (vect_op_selec3.empty() == 1)   {
                                continue;    
                            }
                            for (uint32_t m=0; m<vect_op_selec3.size() && !stop; m++)    {
                                set<poly> op_selec3 = vect_op_selec3[m];
                                uint8_t nb_op3 = nb_op_init - op_selec3.size();
                                vector<set<poly>> vect_op_selec4 = Test_xor(l3, op_selec3, set_op, size_set, map_xor, size_map_xor, nb_op3);
                                if (vect_op_selec4.empty() == 1)   {
                                    continue;
                                }
                                for (uint32_t n=0; n<vect_op_selec4.size() && !stop; n++)    {
                                    set<poly> op_selec4 = vect_op_selec4[n];
                                    uint8_t nb_op4 = nb_op_init - op_selec4.size();
                                    vector<set<poly>> vect_op_selec5 = Test_xor(l4, op_selec4, set_op, size_set, map_xor, size_map_xor, nb_op4);
                                    if (vect_op_selec5.empty() == 1)   {
                                        continue;
                                    }
                                    for (uint32_t p=0; p<vect_op_selec5.size() && !stop; p++)    {
                                        set<poly> op_selec5 = vect_op_selec5[p];
                                        implem_non_lin imp;
                                        imp.op = op_selec5;
                                        imp.i[lignes_m_init[i]] = 0;
                                        imp.i[l1] = 1;
                                        imp.i[l2] = 2;
                                        imp.i[l3] = 3;
                                        imp.i[l4] = 4;
                                        #pragma omp critical
                                        {
                                            vect_implem.push_back(imp);
                                            cout<<"Solution found with : "<<omp_get_thread_num()<<endl;
                                            vect_implem = remove_duplicates_impl(vect_implem);
                                            nb_sol = vect_implem.size();
                                        }
                                        if (nb_sol_wanted != -1) {
                                            if (nb_sol >= nb_sol_wanted) {
                                                #pragma omp atomic write
                                                stop = 1;
                                                cout<<"Number of wanted solutions reached"<<endl;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (nb_lignes == 5) {
                #pragma omp parallel shared(stop)
                {
                    bool stop_local = false;
                    #pragma omp for schedule(static)

                    for (uint32_t k=0; k<vect_perm.size(); k++)    {

                        auto Now = chrono::steady_clock::now();
                        auto time_spent = chrono::duration_cast<chrono::duration<double>>(Now - begin);
                        if (time_spent.count() > time_max)  {
                            #pragma omp atomic write
                            stop = 1;
                        }

                        if (stop_local) {
                                continue;
                            }
                        if (stop) {
                            stop_local = true;
                            continue;
                        }

                        poly l1 = vect_perm[k][0]; //1ère ligne manquante
                        poly l2 = vect_perm[k][1]; //2ème ligne manquante
                        poly l3 = vect_perm[k][2]; //3ème ligne manquante
                        poly l4 = vect_perm[k][3]; //4ème ligne manquante
                        poly l5 = vect_perm[k][4]; //5ème ligne manquante
                        vector<set<poly>> vect_op_selec2 = Test_xor(l1, op_selec1, set_op, size_set, map_xor, size_map_xor, nb_op);

                        if (vect_op_selec2.empty() == 1)   {
                            continue;
                        }
                        for (uint32_t l=0; l<vect_op_selec2.size() && !stop; l++)    {
                            set<poly> op_selec2 = vect_op_selec2[l];
                            uint8_t nb_op2 = nb_op_init - op_selec2.size();
                            vector<set<poly>> vect_op_selec3 = Test_xor(l2, op_selec2, set_op, size_set, map_xor, size_map_xor, nb_op2);
                            if (vect_op_selec3.empty() == 1)   {
                                continue;    
                            }
                            for (uint32_t m=0; m<vect_op_selec3.size() && !stop; m++)    {
                                set<poly> op_selec3 = vect_op_selec3[m];
                                uint8_t nb_op3 = nb_op_init - op_selec3.size();
                                vector<set<poly>> vect_op_selec4 = Test_xor(l3, op_selec3, set_op, size_set, map_xor, size_map_xor, nb_op3);
                                if (vect_op_selec4.empty() == 1)   {
                                    continue;
                                }
                                for (uint32_t n=0; n<vect_op_selec4.size() && !stop; n++)    {
                                    set<poly> op_selec4 = vect_op_selec4[n];
                                    uint8_t nb_op4 = nb_op_init - op_selec4.size();
                                    vector<set<poly>> vect_op_selec5 = Test_xor(l4, op_selec4, set_op, size_set, map_xor, size_map_xor, nb_op4);
                                    if (vect_op_selec5.empty() == 1)   {
                                        continue;
                                    }
                                    for (uint32_t p=0; p<vect_op_selec5.size() && !stop; p++)    {
                                        set<poly> op_selec5 = vect_op_selec5[p];
                                        uint8_t nb_op5 = nb_op_init - op_selec5.size();
                                        vector<set<poly>> vect_op_selec6 = Test_xor(l5, op_selec5, set_op, size_set, map_xor, size_map_xor, nb_op5);
                                        if (vect_op_selec5.empty() == 1)   {
                                            continue;
                                        }
                                        for (uint32_t q=0; q<vect_op_selec6.size() && !stop; q++)    {
                                            set<poly> op_selec6 = vect_op_selec6[q];
                                            implem_non_lin imp;
                                            imp.op = op_selec6;
                                            imp.i[lignes_m_init[i]] = 0;
                                            imp.i[l1] = 1;
                                            imp.i[l2] = 2;
                                            imp.i[l3] = 3;
                                            imp.i[l4] = 4;
                                            imp.i[l5] = 5;
                                            #pragma omp critical
                                            {
                                                vect_implem.push_back(imp);
                                                cout<<"Solution found with : "<<omp_get_thread_num()<<endl;
                                                vect_implem = remove_duplicates_impl(vect_implem);
                                                nb_sol = vect_implem.size();
                                            }
                                            if (nb_sol_wanted != -1) {
                                                if (nb_sol >= nb_sol_wanted) {
                                                    #pragma omp atomic write
                                                    stop = 1;
                                                    cout<<"Number of wanted solutions reached"<<endl;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                } 
            }
            if (vect_implem.empty() == 1)   {
                cout<<" No solutions found with line "<<i<<endl;
            }             
        }
        else {
            cout<<"We can not obtain line "<<i<<" with 0 XOR"<<endl;
        }
    }

    /* STEP 2 : */

    if (vect_implem.empty() == 1)   {
        cout<<"Begin step 2"<<endl;
        for (uint32_t i=0; i<lignes_m_init.size() && !stop; i++) {

            int32_t indice = find_map(lignes_m_init[i], map_xor, 0, size_map_xor);
            if (indice != -1)   {

                cout<<"We can obtain line "<<i<<" with 1 XOR"<<endl;
                vector<poly> lignes_m;
                lignes_m = supp(lignes_m_init[i], lignes_m_init); // On supprime la i-ème ligne des lignes manquantes

                vector<set<poly>> set_op_sol;
                for (uint32_t j=0; j<10; j++)   {
                    set<poly> op;
                    op.insert(map_xor[indice].second[j][0]);
                    op.insert(map_xor[indice].second[j][1]);
                    set_op_sol.push_back(op);
                }
                
                cout<<"We have "<<set_op_sol.size()<<" couples to test for line "<<i<<" : "<<lignes_m_init[i]<<endl;

                #pragma omp parallel shared(stop)
                {
                    bool stop_local = false;
                    #pragma omp for schedule(static) 
                    for (uint32_t j=0; j<set_op_sol.size(); j++)   {
                        if (stop_local) {
                            continue;
                        }
                        if (stop) {
                            stop_local = true;
                            continue;
                        }
                        set<poly> op_selec1 = set_op_sol[j];
                        uint8_t nb_op = nb_op_init - 2;
                        
                        uint8_t nb_lignes = lignes_m.size();

                        if (nb_lignes == 3) {

                            vector<vector<poly>> vect_perm = Permutations(lignes_m);

                            for (uint8_t k=0; k<vect_perm.size() && !stop; k++)    {
                                auto Now = chrono::steady_clock::now();
                                auto time_spent = chrono::duration_cast<chrono::duration<double>>(Now - begin);
                                if (time_spent.count() > time_max)  {
                                    #pragma omp atomic write
                                    stop = 1;
                                }
                                poly l1 = vect_perm[k][0]; //1ère ligne manquante
                                poly l2 = vect_perm[k][1]; //2ème ligne manquante
                                poly l3 = vect_perm[k][2]; //3ème ligne manquante
                                vector<set<poly>> vect_op_selec2 = Test_xor(l1, op_selec1, set_op, size_set, map_xor, size_map_xor, nb_op);

                                if (vect_op_selec2.empty() == 1)   {
                                    continue;
                                }
                                for (uint32_t l=0; l<vect_op_selec2.size() && !stop; l++)    {
                                    set<poly> op_selec2 = vect_op_selec2[l];
                                    uint8_t nb_op2 = nb_op_init - op_selec2.size();
                                    vector<set<poly>> vect_op_selec3 = Test_xor(l2, op_selec2, set_op, size_set, map_xor, size_map_xor, nb_op2);
                                    if (vect_op_selec3.empty() == 1)   {
                                        continue;    
                                    }
                                    for (uint32_t m=0; m<vect_op_selec3.size() && !stop; m++)    {
                                        set<poly> op_selec3 = vect_op_selec3[m];
                                        uint8_t nb_op3 = nb_op_init - op_selec3.size();
                                        vector<set<poly>> vect_op_selec4 = Test_xor(l3, op_selec3, set_op, size_set, map_xor, size_map_xor, nb_op3);
                                        if (vect_op_selec4.empty() == 1)   {
                                            continue;
                                        }
                                        for (uint32_t n=0; n<vect_op_selec4.size() && !stop; n++)    {
                                            set<poly> op_selec4 = vect_op_selec4[n];
                                            implem_non_lin imp;
                                            imp.op = op_selec4;
                                            imp.i[lignes_m_init[i]] = 0;
                                            imp.i[l1] = 1;
                                            imp.i[l2] = 2;
                                            imp.i[l3] = 3;
                                            #pragma omp critical
                                            {
                                                vect_implem.push_back(imp);
                                                cout<<"Solution found with : "<<omp_get_thread_num()<<endl;
                                                vect_implem = remove_duplicates_impl(vect_implem);
                                                nb_sol = vect_implem.size();
                                            }
                                            if (nb_sol_wanted != -1) {
                                                if (nb_sol >= nb_sol_wanted) {
                                                    #pragma omp atomic write
                                                    stop = 1;
                                                    cout<<"Number of wanted solutions reached"<<endl;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (nb_lignes == 4) {

                            vector<vector<poly>> vect_perm = Permutations(lignes_m);

                            for (uint8_t k=0; k<vect_perm.size() && !stop; k++)    {
                                auto Now = chrono::steady_clock::now();
                                auto time_spent = chrono::duration_cast<chrono::duration<double>>(Now - begin);
                                if (time_spent.count() > time_max)  {
                                    #pragma omp atomic write
                                    stop = 1;
                                }
                                poly l1 = vect_perm[k][0]; //1ère ligne manquante
                                poly l2 = vect_perm[k][1]; //2ème ligne manquante
                                poly l3 = vect_perm[k][2]; //3ème ligne manquante
                                poly l4 = vect_perm[k][3]; //4ème ligne manquante
                                vector<set<poly>> vect_op_selec2 = Test_xor(l1, op_selec1, set_op, size_set, map_xor, size_map_xor, nb_op);

                                if (vect_op_selec2.empty() == 1)   {
                                    continue;
                                }
                                for (uint32_t l=0; l<vect_op_selec2.size() && !stop; l++)    {
                                    set<poly> op_selec2 = vect_op_selec2[l];
                                    uint8_t nb_op2 = nb_op_init - op_selec2.size();
                                    vector<set<poly>> vect_op_selec3 = Test_xor(l2, op_selec2, set_op, size_set, map_xor, size_map_xor, nb_op2);
                                    if (vect_op_selec3.empty() == 1)   {
                                        continue;    
                                    }
                                    for (uint32_t m=0; m<vect_op_selec3.size() && !stop; m++)    {
                                        set<poly> op_selec3 = vect_op_selec3[m];
                                        uint8_t nb_op3 = nb_op_init - op_selec3.size();
                                        vector<set<poly>> vect_op_selec4 = Test_xor(l3, op_selec3, set_op, size_set, map_xor, size_map_xor, nb_op3);
                                        if (vect_op_selec4.empty() == 1)   {
                                            continue;
                                        }
                                        for (uint32_t n=0; n<vect_op_selec4.size() && !stop; n++)    {
                                            set<poly> op_selec4 = vect_op_selec4[n];
                                            uint8_t nb_op4 = nb_op_init - op_selec4.size();
                                            vector<set<poly>> vect_op_selec5 = Test_xor(l4, op_selec4, set_op, size_set, map_xor, size_map_xor, nb_op4);
                                            if (vect_op_selec5.empty() == 1)   {
                                                continue;
                                            }
                                            for (uint32_t p=0; p<vect_op_selec5.size() && !stop; p++)    {
                                                set<poly> op_selec5 = vect_op_selec5[p];
                                                implem_non_lin imp;
                                                imp.op = op_selec5;
                                                imp.i[lignes_m_init[i]] = 0;
                                                imp.i[l1] = 1;
                                                imp.i[l2] = 2;
                                                imp.i[l3] = 3;
                                                imp.i[l4] = 4;
                                                #pragma omp critical
                                                {
                                                    vect_implem.push_back(imp);
                                                    cout<<"Solution found with : "<<omp_get_thread_num()<<endl;
                                                    vect_implem = remove_duplicates_impl(vect_implem);
                                                    nb_sol = vect_implem.size();
                                                }
                                                if (nb_sol_wanted != -1) {
                                                    if (nb_sol >= nb_sol_wanted) {
                                                        #pragma omp atomic write
                                                        stop = 1;
                                                        cout<<"Number of wanted solutions reached"<<endl;
                                                    }
                                                }
                                            
                                            }
                                        }
                                    }
                                }
                                cout<<"Next permutation for thread "<<omp_get_thread_num()<<endl;
                            }
                        }
                        if (nb_lignes == 5) {

                            vector<vector<poly>> vect_perm = Permutations(lignes_m);

                            for (uint32_t k=0; k<vect_perm.size() && !stop; k++)    {
                                auto Now = chrono::steady_clock::now();
                                auto time_spent = chrono::duration_cast<chrono::duration<double>>(Now - begin);
                                if (time_spent.count() > time_max)  {
                                    #pragma omp atomic write
                                    stop = 1;
                                }
                                poly l1 = vect_perm[k][0]; //1ère ligne manquante
                                poly l2 = vect_perm[k][1]; //2ème ligne manquante
                                poly l3 = vect_perm[k][2]; //3ème ligne manquante
                                poly l4 = vect_perm[k][3]; //4ème ligne manquante
                                poly l5 = vect_perm[k][4]; //5ème ligne manquante

                                vector<set<poly>> vect_op_selec2 = Test_xor(l1, op_selec1, set_op, size_set, map_xor, size_map_xor, nb_op);

                                if (vect_op_selec2.empty() == 1)   {
                                    continue;
                                }
                                for (uint32_t l=0; l<vect_op_selec2.size() && !stop; l++)    {
                                    set<poly> op_selec2 = vect_op_selec2[l];
                                    uint8_t nb_op2 = nb_op_init - op_selec2.size();
                                    vector<set<poly>> vect_op_selec3 = Test_xor(l2, op_selec2, set_op, size_set, map_xor, size_map_xor, nb_op2);
                                    if (vect_op_selec3.empty() == 1)   {
                                        continue;    
                                    }
                                    for (uint32_t m=0; m<vect_op_selec3.size() && !stop; m++)    {
                                        set<poly> op_selec3 = vect_op_selec3[m];
                                        uint8_t nb_op3 = nb_op_init - op_selec3.size();
                                        vector<set<poly>> vect_op_selec4 = Test_xor(l3, op_selec3, set_op, size_set, map_xor, size_map_xor, nb_op3);
                                        if (vect_op_selec4.empty() == 1)   {
                                            continue;
                                        }
                                        for (uint32_t n=0; n<vect_op_selec4.size() && !stop; n++)    {
                                            set<poly> op_selec4 = vect_op_selec4[n];
                                            uint8_t nb_op4 = nb_op_init - op_selec4.size();
                                            vector<set<poly>> vect_op_selec5 = Test_xor(l4, op_selec4, set_op, size_set, map_xor, size_map_xor, nb_op4);
                                            if (vect_op_selec5.empty() == 1)   {
                                                continue;
                                            }
                                            for (uint32_t p=0; p<vect_op_selec5.size() && !stop; p++)    {
                                                set<poly> op_selec5 = vect_op_selec5[p];
                                                uint8_t nb_op5 = nb_op_init - op_selec5.size();
                                                vector<set<poly>> vect_op_selec6 = Test_xor(l5, op_selec5, set_op, size_set, map_xor, size_map_xor, nb_op5);
                                                if (vect_op_selec6.empty() == 1)   {
                                                    continue;
                                                }
                                                for (uint32_t q=0; q<vect_op_selec6.size() && !stop; q++)    {
                                                    set<poly> op_selec6 = vect_op_selec6[q];
                                                    implem_non_lin imp;
                                                    imp.op = op_selec6;
                                                    imp.i[lignes_m_init[i]] = 0;
                                                    imp.i[l1] = 1;
                                                    imp.i[l2] = 2;
                                                    imp.i[l3] = 3;
                                                    imp.i[l4] = 4;
                                                    imp.i[l5] = 5;
                                                    #pragma omp critical
                                                    {
                                                        vect_implem.push_back(imp);
                                                        cout<<"Solution found with : "<<omp_get_thread_num()<<endl;
                                                        vect_implem = remove_duplicates_impl(vect_implem);
                                                        nb_sol = vect_implem.size();
                                                    }
                                                    if (nb_sol_wanted != -1) {
                                                        if (nb_sol >= nb_sol_wanted) {
                                                            #pragma omp atomic write
                                                            stop = 1;
                                                            cout<<"Number of wanted solutions reached"<<endl;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (nb_lignes == 6) {

                            vector<vector<poly>> vect_perm = Permutations(lignes_m);

                            for (uint32_t k=0; k<vect_perm.size() && !stop; k++)    {
                                auto Now = chrono::steady_clock::now();
                                auto time_spent = chrono::duration_cast<chrono::duration<double>>(Now - begin);
                                if (time_spent.count() > time_max)  {
                                    #pragma omp atomic write
                                    stop = 1;
                                }
                                poly l1 = vect_perm[k][0]; //1ère ligne manquante
                                poly l2 = vect_perm[k][1]; //2ème ligne manquante
                                poly l3 = vect_perm[k][2]; //3ème ligne manquante
                                poly l4 = vect_perm[k][3]; //4ème ligne manquante
                                poly l5 = vect_perm[k][4]; //5ème ligne manquante
                                poly l6 = vect_perm[k][5]; //6ème ligne manquante
                                vector<set<poly>> vect_op_selec2 = Test_xor(l1, op_selec1, set_op, size_set, map_xor, size_map_xor, nb_op);
                                if (vect_op_selec2.empty() == 1)   {
                                    continue;
                                }
                                for (uint32_t l=0; l<vect_op_selec2.size() && !stop; l++)    {
                                    set<poly> op_selec2 = vect_op_selec2[l];
                                    uint8_t nb_op2 = nb_op_init - op_selec2.size();
                                    vector<set<poly>> vect_op_selec3 = Test_xor(l2, op_selec2, set_op, size_set, map_xor, size_map_xor, nb_op2);
                                    if (vect_op_selec3.empty() == 1)   {
                                        continue;
                                    }
                                    for (uint32_t m=0; m<vect_op_selec3.size() && !stop; m++)    {
                                        set<poly> op_selec3 = vect_op_selec3[m];
                                        uint8_t nb_op3 = nb_op_init - op_selec3.size();
                                        vector<set<poly>> vect_op_selec4 = Test_xor(l3, op_selec3, set_op, size_set, map_xor, size_map_xor, nb_op3);
                                        if (vect_op_selec4.empty() == 1)   {
                                            continue;
                                        }
                                        for (uint32_t n=0; n<vect_op_selec4.size() && !stop; n++)    {
                                            set<poly> op_selec4 = vect_op_selec4[n];
                                            uint8_t nb_op4 = nb_op_init - op_selec4.size();
                                            vector<set<poly>> vect_op_selec5 = Test_xor(l4, op_selec4, set_op, size_set, map_xor, size_map_xor, nb_op4);
                                            if (vect_op_selec5.empty() == 1)   {
                                                continue;
                                            }
                                            for (uint32_t p=0; p<vect_op_selec5.size() && !stop; p++)    {
                                                set<poly> op_selec5 = vect_op_selec5[p];
                                                uint8_t nb_op5 = nb_op_init - op_selec5.size();
                                                vector<set<poly>> vect_op_selec6 = Test_xor(l5, op_selec5, set_op, size_set, map_xor, size_map_xor, nb_op5);
                                                if (vect_op_selec6.empty() == 1)   {
                                                    continue;
                                                }
                                                for (uint32_t q=0; q<vect_op_selec6.size() && !stop; q++)    {
                                                    set<poly> op_selec6 = vect_op_selec6[q];
                                                    uint8_t nb_op6 = nb_op_init - op_selec6.size();
                                                    vector<set<poly>> vect_op_selec7 = Test_xor(l6, op_selec6, set_op, size_set, map_xor, size_map_xor, nb_op6);
                                                    if (vect_op_selec7.empty() == 1)   {
                                                        continue;
                                                    }
                                                    for (uint32_t r=0; r<vect_op_selec7.size() && !stop; r++)    {
                                                        set<poly> op_selec7 = vect_op_selec7[r];
                                                        implem_non_lin imp;
                                                        imp.op = op_selec7;
                                                        imp.i[lignes_m_init[i]] = 0;
                                                        imp.i[l1] = 1;
                                                        imp.i[l2] = 2;
                                                        imp.i[l3] = 3;
                                                        imp.i[l4] = 4;
                                                        imp.i[l5] = 5;
                                                        imp.i[l6] = 6;
                                                        #pragma omp critical
                                                        {
                                                        vect_implem.push_back(imp);
                                                        cout<<"Solution found with : "<<omp_get_thread_num()<<endl;
                                                        int comp = vect_implem.size();
                                                        vect_implem = remove_duplicates_impl(vect_implem);
                                                        nb_sol = vect_implem.size();
                                                        if (comp == nb_sol) {
                                                                cout<<"New solution"<<endl;
                                                            }
                                                            else {
                                                                cout<<"Not a new one"<<endl;
                                                            }
                                                        }
                                                        if (nb_sol_wanted != -1) {
                                                            if (nb_sol >= nb_sol_wanted)  {
                                                                #pragma omp atomic write
                                                                stop = 1;
                                                                cout<<"Number of wanted solutions reached"<<endl;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (nb_lignes == 7) {

                            random_device rd;  // a seed source for the random number engine
                            mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()

                            vector<vector<poly>> vect_perm;
                            for (uint32_t j=0; j< NB_PERM_MAX_8; j++) {
                                ranges::shuffle(lignes_m, gen);
                                vect_perm.push_back(lignes_m);
                            }

                            for (uint32_t k=0; k<vect_perm.size() && !stop; k++)    {
                                auto Now = chrono::steady_clock::now();
                                auto time_spent = chrono::duration_cast<chrono::duration<double>>(Now - begin);
                                if (time_spent.count() > time_max)  {
                                    #pragma omp atomic write
                                    stop = 1;
                                }
                                poly l1 = vect_perm[k][0]; //1ère ligne manquante
                                poly l2 = vect_perm[k][1]; //2ème ligne manquante
                                poly l3 = vect_perm[k][2]; //3ème ligne manquante
                                poly l4 = vect_perm[k][3]; //4ème ligne manquante
                                poly l5 = vect_perm[k][4]; //5ème ligne manquante
                                poly l6 = vect_perm[k][5]; //6ème ligne manquante
                                poly l7 = vect_perm[k][6]; //7ème ligne manquante
                                vector<set<poly>> vect_op_selec2 = Test_xor(l1, op_selec1, set_op, size_set, map_xor, size_map_xor, nb_op);
                                if (vect_op_selec2.empty() == 1)   {
                                    continue;
                                }
                                for (uint32_t l=0; l<vect_op_selec2.size() && !stop; l++)    {
                                    set<poly> op_selec2 = vect_op_selec2[l];
                                    uint8_t nb_op2 = nb_op_init - op_selec2.size();
                                    vector<set<poly>> vect_op_selec3 = Test_xor(l2, op_selec2, set_op, size_set, map_xor, size_map_xor, nb_op2);
                                    if (vect_op_selec3.empty() == 1)   {
                                        continue;
                                    }
                                    for (uint32_t m=0; m<vect_op_selec3.size() && !stop; m++)    {
                                        set<poly> op_selec3 = vect_op_selec3[m];
                                        uint8_t nb_op3 = nb_op_init - op_selec3.size();
                                        vector<set<poly>> vect_op_selec4 = Test_xor(l3, op_selec3, set_op, size_set, map_xor, size_map_xor, nb_op3);
                                        if (vect_op_selec4.empty() == 1)   {
                                            continue;
                                        }                                            
                                        for (uint32_t n=0; n<vect_op_selec4.size() && !stop; n++)    {
                                            set<poly> op_selec4 = vect_op_selec4[n];
                                            uint8_t nb_op4 = nb_op_init - op_selec4.size();
                                            vector<set<poly>> vect_op_selec5 = Test_xor(l4, op_selec4, set_op, size_set, map_xor, size_map_xor, nb_op4);
                                            if (vect_op_selec5.empty() == 1)   {
                                                continue;
                                            }
                                            for (uint32_t p=0; p<vect_op_selec5.size() && !stop; p++)    {
                                                set<poly> op_selec5 = vect_op_selec5[p];
                                                uint8_t nb_op5 = nb_op_init - op_selec5.size();
                                                vector<set<poly>> vect_op_selec6 = Test_xor(l5, op_selec5, set_op, size_set, map_xor, size_map_xor, nb_op5);
                                                if (vect_op_selec6.empty() == 1)   {
                                                    continue;
                                                }
                                                for (uint32_t q=0; q<vect_op_selec6.size() && !stop; q++)    {
                                                    set<poly> op_selec6 = vect_op_selec6[q];
                                                    uint8_t nb_op6 = nb_op_init - op_selec6.size();
                                                    vector<set<poly>> vect_op_selec7 = Test_xor(l6, op_selec6, set_op, size_set, map_xor, size_map_xor, nb_op6);
                                                    if (vect_op_selec7.empty() == 1)   {
                                                        continue;
                                                    }
                                                    for (uint32_t r=0; r<vect_op_selec7.size() && !stop; r++)    {
                                                        set<poly> op_selec7 = vect_op_selec7[r];
                                                        uint8_t nb_op7 = nb_op_init - op_selec7.size();
                                                        vector<set<poly>> vect_op_selec8 = Test_xor(l7, op_selec7, set_op, size_set, map_xor, size_map_xor, nb_op7);
                                                        if (vect_op_selec8.empty() == 1)   {
                                                             continue;
                                                        }
                                                        for (uint32_t s=0; s<vect_op_selec8.size() && !stop; s++)    {
                                                            set<poly> op_selec8 = vect_op_selec8[s];
                                                            implem_non_lin imp;
                                                            imp.op = op_selec8;
                                                            imp.i[lignes_m_init[i]] = 0;
                                                            imp.i[l1] = 1;
                                                            imp.i[l2] = 2;
                                                            imp.i[l3] = 3;
                                                            imp.i[l4] = 4;
                                                            imp.i[l5] = 5;
                                                            imp.i[l6] = 6;
                                                            imp.i[l7] = 7;
                                                            #pragma omp critical
                                                            {
                                                            vect_implem.push_back(imp);
                                                            cout<<"Solution found with : "<<omp_get_thread_num()<<endl;
                                                            vect_implem = remove_duplicates_impl(vect_implem);
                                                            }
                                                            nb_sol = vect_implem.size();
                                                            if (nb_sol_wanted != -1) {
                                                                if (nb_sol >= nb_sol_wanted)  {
                                                                    #pragma omp atomic write
                                                                    stop = 1;
                                                                    cout<<"Number of wanted solutions reached"<<endl;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (nb_lignes == 8) {

                            random_device rd;  // a seed source for the random number engine
                            mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()

                            vector<vector<poly>> vect_perm;
                            for (uint32_t j=0; j< NB_PERM_MAX_9; j++) {
                                ranges::shuffle(lignes_m, gen);
                                vect_perm.push_back(lignes_m);
                            }

                            for (uint32_t k=0; k<vect_perm.size() && !stop; k++)    {
                                auto Now = chrono::steady_clock::now();
                                auto time_spent = chrono::duration_cast<chrono::duration<double>>(Now - begin);
                                if (time_spent.count() > time_max)  {
                                    #pragma omp atomic write
                                    stop = 1;
                                }
                                poly l1 = vect_perm[k][0]; //1ère ligne manquante
                                poly l2 = vect_perm[k][1]; //2ème ligne manquante
                                poly l3 = vect_perm[k][2]; //3ème ligne manquante
                                poly l4 = vect_perm[k][3]; //4ème ligne manquante
                                poly l5 = vect_perm[k][4]; //5ème ligne manquante
                                poly l6 = vect_perm[k][5]; //6ème ligne manquante
                                poly l7 = vect_perm[k][6]; //7ème ligne manquante
                                poly l8 = vect_perm[k][7]; //8ème ligne manquante
                                vector<set<poly>> vect_op_selec2 = Test_xor(l1, op_selec1, set_op, size_set, map_xor, size_map_xor, nb_op);
                                if (vect_op_selec2.empty() == 1)   {
                                    continue;
                                }
                                for (uint32_t l=0; l<vect_op_selec2.size() && !stop; l++)    {
                                    set<poly> op_selec2 = vect_op_selec2[l];
                                    uint8_t nb_op2 = nb_op_init - op_selec2.size();
                                    vector<set<poly>> vect_op_selec3 = Test_xor(l2, op_selec2, set_op, size_set, map_xor, size_map_xor, nb_op2);
                                    if (vect_op_selec3.empty() == 1)   {
                                        continue;
                                    }
                                    for (uint32_t m=0; m<vect_op_selec3.size() && !stop; m++)    {
                                        set<poly> op_selec3 = vect_op_selec3[m];
                                        uint8_t nb_op3 = nb_op_init - op_selec3.size();
                                        vector<set<poly>> vect_op_selec4 = Test_xor(l3, op_selec3, set_op, size_set, map_xor, size_map_xor, nb_op3);
                                        if (vect_op_selec4.empty() == 1)   {
                                            continue;
                                        }                                            
                                        for (uint32_t n=0; n<vect_op_selec4.size() && !stop; n++)    {
                                            set<poly> op_selec4 = vect_op_selec4[n];
                                            uint8_t nb_op4 = nb_op_init - op_selec4.size();
                                            vector<set<poly>> vect_op_selec5 = Test_xor(l4, op_selec4, set_op, size_set, map_xor, size_map_xor, nb_op4);
                                            if (vect_op_selec5.empty() == 1)   {
                                                continue;
                                            }
                                            for (uint32_t p=0; p<vect_op_selec5.size() && !stop; p++)    {
                                                set<poly> op_selec5 = vect_op_selec5[p];
                                                uint8_t nb_op5 = nb_op_init - op_selec5.size();
                                                vector<set<poly>> vect_op_selec6 = Test_xor(l5, op_selec5, set_op, size_set, map_xor, size_map_xor, nb_op5);
                                                if (vect_op_selec6.empty() == 1)   {
                                                    continue;
                                                }
                                                for (uint32_t q=0; q<vect_op_selec6.size() && !stop; q++)    {
                                                    set<poly> op_selec6 = vect_op_selec6[q];
                                                    uint8_t nb_op6 = nb_op_init - op_selec6.size();
                                                    vector<set<poly>> vect_op_selec7 = Test_xor(l6, op_selec6, set_op, size_set, map_xor, size_map_xor, nb_op6);
                                                    if (vect_op_selec7.empty() == 1)   {
                                                        continue;
                                                    }
                                                    for (uint32_t r=0; r<vect_op_selec7.size() && !stop; r++)    {
                                                        set<poly> op_selec7 = vect_op_selec7[r];
                                                        uint8_t nb_op7 = nb_op_init - op_selec7.size();
                                                        vector<set<poly>> vect_op_selec8 = Test_xor(l7, op_selec7, set_op, size_set, map_xor, size_map_xor, nb_op7);
                                                        if (vect_op_selec8.empty() == 1)   {
                                                             continue;
                                                        }
                                                        for (uint32_t s=0; s<vect_op_selec8.size() && !stop; s++)    {
                                                            set<poly> op_selec8 = vect_op_selec8[s];
                                                            uint8_t nb_op8 = nb_op_init - op_selec8.size();
                                                            vector<set<poly>> vect_op_selec9 = Test_xor(l8, op_selec8, set_op, size_set, map_xor, size_map_xor, nb_op8);
                                                            if (vect_op_selec9.empty() == 1)   {
                                                                continue;
                                                            }
                                                            for (uint32_t t=0; t<vect_op_selec9.size() && !stop; t++)    {
                                                                set<poly> op_selec9 = vect_op_selec9[t];
                                                                implem_non_lin imp;
                                                                imp.op = op_selec9;
                                                                imp.i[lignes_m_init[i]] = 0;
                                                                imp.i[l1] = 1;
                                                                imp.i[l2] = 2;
                                                                imp.i[l3] = 3;
                                                                imp.i[l4] = 4;
                                                                imp.i[l5] = 5;
                                                                imp.i[l6] = 6;
                                                                imp.i[l7] = 7;
                                                                imp.i[l8] = 8;
                                                                #pragma omp critical
                                                                {
                                                                vect_implem.push_back(imp);
                                                                cout<<"Solution found with : "<<omp_get_thread_num()<<endl;
                                                                vect_implem = remove_duplicates_impl(vect_implem);
                                                                }
                                                                nb_sol = vect_implem.size();
                                                                if (nb_sol_wanted != -1) {
                                                                    if (nb_sol >= nb_sol_wanted)  {
                                                                        #pragma omp atomic write
                                                                        stop = 1;
                                                                        cout<<"Number of wanted solutions reached"<<endl;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if (vect_implem.empty() == 1)   {
                    cout<<" No solutions found with line "<<i<<endl;
                }
            }
            else {
                cout<<" We can not obtain line "<<i<<" with only 1 xor"<<endl;
            }
        }
    }
    /*STEP 3 : */
    if (vect_implem.empty() == 1)   {
        cout<<"Begin step 3 "<<endl;

        for (uint32_t i=0 ; i<lignes_m_init.size() && !stop; i++) {   
            vector<set<poly>> set_op_sol;          
            for (uint32_t j=0 ; j < size_set && !stop; j++)    {
                poly elem = lignes_m_init[i] ^ set_op[j];
                int32_t indice = find_map(elem, map_xor, 0, size_map_xor);
                if (indice != -1)   {
                    for (uint32_t k=0; k<10; k++)   {
                        set<poly> op;
                        op.insert(set_op[j]);
                        op.insert(map_xor[indice].second[k][0]);
                        op.insert(map_xor[indice].second[k][1]);
                        set_op_sol.push_back(op);
                    }
                }
            }

            set_op_sol = remove_duplicates_set(set_op_sol);

            if (set_op_sol.empty() != 1){

                cout<<"We can obtain line "<<i<<" : "<<lignes_m_init[i]<<" with 2 xor"<<endl;

                random_device rd;  // a seed source for the random number engine
                mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
                shuffle (set_op_sol.begin(), set_op_sol.end(), gen);

                cout<<"We have "<<set_op_sol.size()<<" triplets to test for line " <<i<<" : "<<lignes_m_init[i]<<endl;
                /*Pour chaque trio, on calcule les permutations des lignes manquantes et on procède comme précédemment*/
                        
                time_t now = chrono::system_clock::to_time_t(chrono::system_clock::now());
                cout << "Time is " << ctime(&now) << endl;

                vector<poly> lignes_m;
                lignes_m = supp(lignes_m_init[i], lignes_m_init); // On supprime la i-ème ligne des lignes manquantes    
                uint8_t nb_op = nb_op_init - 3;

                uint8_t nb_lignes = lignes_m.size();

                #pragma omp parallel shared(stop)
                {
                    bool stop_local = false;
                    #pragma omp for schedule (dynamic)

                    for (uint32_t j=0; j<set_op_sol.size(); j++)   {
                        if (stop_local) {
                            continue;
                        }
                        if (stop) {
                            stop_local = true;
                            continue;
                        }

                        set<poly> op_selec1 = set_op_sol[j];

                        if (nb_lignes == 4) {

                            vector<vector<poly>> vect_perm = Permutations(lignes_m);

                            for (uint8_t k=0; k<vect_perm.size() && !stop; k++)    {

                                auto Now = chrono::steady_clock::now();
                                auto time_spent = chrono::duration_cast<chrono::duration<double>>(Now - begin);
                                if (time_spent.count() > time_max)  {
                                    #pragma omp atomic write
                                    stop = 1;
                                }
                                poly l1 = vect_perm[k][0]; //1ère ligne manquante
                                poly l2 = vect_perm[k][1]; //2ème ligne manquante  
                                poly l3 = vect_perm[k][2]; //3ème ligne manquante
                                poly l4 = vect_perm[k][3]; //4ème ligne manquante
                                        
                                vector<set<poly>> vect_op_selec2 = Test_xor(l1, op_selec1, set_op, size_set, map_xor, size_map_xor, nb_op);
                                if (vect_op_selec2.empty() == 1)   {
                                    continue;
                                }
                                for (uint32_t l=0; l<vect_op_selec2.size() && !stop; l++)    {
                                    set<poly> op_selec2 = vect_op_selec2[l];
                                    uint8_t nb_op2 = nb_op_init - op_selec2.size();
                                    vector<set<poly>> vect_op_selec3 = Test_xor(l2, op_selec2, set_op, size_set, map_xor, size_map_xor, nb_op2);
                                    if (vect_op_selec3.empty() == 1)   {
                                        continue;
                                    }
                                    for (uint32_t m=0; m<vect_op_selec3.size() && !stop; m++)    {
                                        set<poly> op_selec3 = vect_op_selec3[m];
                                        uint8_t nb_op3 = nb_op_init - op_selec3.size();
                                        vector<set<poly>> vect_op_selec4 = Test_xor(l3, op_selec3, set_op, size_set, map_xor, size_map_xor, nb_op3);
                                        if (vect_op_selec4.empty() == 1)   {
                                            continue;
                                        }
                                        for (uint32_t n=0; n<vect_op_selec4.size() && !stop; n++)    {
                                            set<poly> op_selec4 = vect_op_selec4[n];
                                            uint8_t nb_op4 = nb_op_init - op_selec4.size();
                                            vector<set<poly>> vect_op_selec5 = Test_xor(l4, op_selec4, set_op, size_set, map_xor, size_map_xor, nb_op4);
                                            if (vect_op_selec5.empty() == 1)   {
                                                continue;
                                            }
                                            for (uint32_t p=0; p<vect_op_selec5.size() && !stop; p++)    {
                                                set<poly> op_selec5 = vect_op_selec5[p];
                                                implem_non_lin imp;
                                                imp.op = op_selec5;
                                                imp.i[lignes_m_init[i]] = 0;
                                                imp.i[l1] = 1;
                                                imp.i[l2] = 2;
                                                imp.i[l3] = 3;
                                                imp.i[l4] = 4;
                                                #pragma omp critical
                                                {
                                                    vect_implem.push_back(imp);
                                                    cout<<"Solution found with : "<<omp_get_thread_num()<<endl;
                                                    vect_implem = remove_duplicates_impl(vect_implem);
                                                }                                                    
                                                nb_sol = vect_implem.size();
                                                if (nb_sol_wanted != -1) {
                                                    if (nb_sol >= nb_sol_wanted) {
                                                        #pragma omp atomic write
                                                        stop = 1;
                                                        cout<<"Number of wanted solutions reached"<<endl;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (nb_lignes == 5) {

                            vector<vector<poly>> vect_perm = Permutations(lignes_m);

                            for (uint8_t k=0; k<vect_perm.size() && !stop; k++)   {

                                auto Now = chrono::steady_clock::now();
                                auto time_spent = chrono::duration_cast<chrono::duration<double>>(Now - begin);
                                if (time_spent.count() > time_max)  {
                                    #pragma omp atomic write
                                        stop = 1;
                                }
                                poly l1 = vect_perm[k][0]; //1ère ligne manquante
                                poly l2 = vect_perm[k][1]; //2ème ligne manquante
                                poly l3 = vect_perm[k][2]; //3ème ligne manquante
                                poly l4 = vect_perm[k][3]; //4ème ligne manquante
                                poly l5 = vect_perm[k][4]; //5ème ligne manquante
                                    
                                vector<set<poly>> vect_op_selec2 = Test_xor(l1, op_selec1, set_op, size_set, map_xor, size_map_xor, nb_op);
                                if (vect_op_selec2.empty() == 1)   {
                                    continue;
                                }
                                for (uint32_t l=0; l<vect_op_selec2.size() && !stop; l++)    {
                                    set<poly> op_selec2 = vect_op_selec2[l];
                                    uint8_t nb_op2 = nb_op_init - op_selec2.size();
                                    vector<set<poly>> vect_op_selec3 = Test_xor(l2, op_selec2, set_op, size_set, map_xor, size_map_xor, nb_op2);
                                    if (vect_op_selec3.empty() == 1)   {   
                                        continue;
                                    }
                                    for (uint32_t m=0; m<vect_op_selec3.size() && !stop; m++)    {
                                        set<poly> op_selec3 = vect_op_selec3[m];
                                        uint8_t nb_op3 = nb_op_init - op_selec3.size();
                                        vector<set<poly>> vect_op_selec4 = Test_xor(l3, op_selec3, set_op, size_set, map_xor, size_map_xor, nb_op3);
                                        if (vect_op_selec4.empty() == 1)   {
                                            continue;
                                        }
                                        for (uint32_t n=0; n<vect_op_selec4.size() && !stop; n++)    {
                                            set<poly> op_selec4 = vect_op_selec4[n];
                                            uint8_t nb_op4 = nb_op_init - op_selec4.size();
                                            vector<set<poly>> vect_op_selec5 = Test_xor(l4, op_selec4, set_op, size_set, map_xor, size_map_xor, nb_op4);
                                            if (vect_op_selec5.empty() == 1)   {
                                                continue;
                                            }
                                            for (uint32_t p=0; p<vect_op_selec5.size() && !stop; p++)    {
                                                set<poly> op_selec5 = vect_op_selec5[p];
                                                uint8_t nb_op5 = nb_op_init - op_selec5.size();
                                                vector<set<poly>> vect_op_selec6 = Test_xor(l5, op_selec5, set_op, size_set, map_xor, size_map_xor, nb_op5);
                                                if (vect_op_selec5.empty() == 1)   {
                                                    continue;
                                                }
                                                for (uint32_t q=0; q<vect_op_selec6.size() && !stop; q++)    {
                                                    set<poly> op_selec6 = vect_op_selec6[q];
                                                    implem_non_lin imp;
                                                    imp.op = op_selec6;
                                                    imp.i[lignes_m_init[i]] = 0;
                                                    imp.i[l1] = 1;
                                                    imp.i[l2] = 2;
                                                    imp.i[l3] = 3;
                                                    imp.i[l4] = 4;
                                                    imp.i[l5] = 5;
                                                    #pragma omp critical
                                                    {
                                                        vect_implem.push_back(imp);
                                                        cout<<"Solution found with : "<<omp_get_thread_num()<<endl;
                                                        vect_implem = remove_duplicates_impl(vect_implem);
                                                    }
                                                    nb_sol = vect_implem.size();
                                                    if (nb_sol_wanted != -1) {
                                                        if (nb_sol >= nb_sol_wanted) {
                                                            #pragma omp atomic write
                                                            stop = 1;
                                                            cout<<"Number of wanted solutions reached"<<endl;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (nb_lignes == 6) {

                            vector<vector<poly>> vect_perm = Permutations(lignes_m);

                            for (uint32_t k=0; k<vect_perm.size() && !stop ; k++)    {
                                auto Now = chrono::steady_clock::now();
                                auto time_spent = chrono::duration_cast<chrono::duration<double>>(Now - begin);
                                if (time_spent.count() > time_max)  {
                                    #pragma omp atomic write
                                    stop = 1;
                                }
                                poly l1 = vect_perm[k][0]; //1ère ligne manquante
                                poly l2 = vect_perm[k][1]; //2ème ligne manquante
                                poly l3 = vect_perm[k][2]; //3ème ligne manquante
                                poly l4 = vect_perm[k][3]; //4ème ligne manquante
                                poly l5 = vect_perm[k][4]; //5ème ligne manquante
                                poly l6 = vect_perm[k][5]; //6ème ligne manquante
                            
                                vector<set<poly>> vect_op_selec2 = Test_xor(l1, op_selec1, set_op, size_set, map_xor, size_map_xor, nb_op);
                                if (vect_op_selec2.empty() == 1)   {
                                    continue;
                                }
                                for (uint32_t l=0; l<vect_op_selec2.size() && !stop; l++)    {
                                    set<poly> op_selec2 = vect_op_selec2[l];
                                    uint8_t nb_op2 = nb_op_init - op_selec2.size();
                                    vector<set<poly>> vect_op_selec3 = Test_xor(l2, op_selec2, set_op, size_set, map_xor, size_map_xor, nb_op2);
                                    if (vect_op_selec3.empty() == 1)   {
                                        continue;
                                    }
                                    for (uint32_t m=0; m<vect_op_selec3.size() && !stop; m++)    {
                                        set<poly> op_selec3 = vect_op_selec3[m];
                                        uint8_t nb_op3 = nb_op_init - op_selec3.size();
                                        vector<set<poly>> vect_op_selec4 = Test_xor(l3, op_selec3, set_op, size_set, map_xor, size_map_xor, nb_op3);
                                        if (vect_op_selec4.empty() == 1)   {
                                            continue;
                                        }
                                        for (uint32_t n=0; n<vect_op_selec4.size() && !stop; n++)    {
                                            set<poly> op_selec4 = vect_op_selec4[n];
                                            uint8_t nb_op4 = nb_op_init - op_selec4.size();
                                            vector<set<poly>> vect_op_selec5 = Test_xor(l4, op_selec4, set_op, size_set, map_xor, size_map_xor, nb_op4);
                                            if (vect_op_selec5.empty() == 1)   {
                                                continue;
                                            }
                                            for (uint32_t p=0; p<vect_op_selec5.size() && !stop; p++)    {
                                                set<poly> op_selec5 = vect_op_selec5[p];
                                                uint8_t nb_op5 = nb_op_init - op_selec5.size();
                                                vector<set<poly>> vect_op_selec6 = Test_xor(l5, op_selec5, set_op, size_set, map_xor, size_map_xor, nb_op5);
                                                if (vect_op_selec6.empty() == 1)   {
                                                    continue;
                                                }
                                                for (uint32_t q=0; q<vect_op_selec6.size() && !stop; q++)    {
                                                    set<poly> op_selec6 = vect_op_selec6[q];
                                                    uint8_t nb_op6 = nb_op_init - op_selec6.size();
                                                    vector<set<poly>> vect_op_selec7 = Test_xor(l6, op_selec6, set_op, size_set, map_xor, size_map_xor, nb_op6);
                                                    if (vect_op_selec7.empty() == 1)   {
                                                        continue;
                                                    }
                                                    for (uint32_t r=0; r<vect_op_selec7.size() && !stop; r++)    {
                                                        set<poly> op_selec7 = vect_op_selec7[r];
                                                        implem_non_lin imp;
                                                        imp.op = op_selec7;
                                                        imp.i[lignes_m_init[i]] = 0;
                                                        imp.i[l1] = 1;
                                                        imp.i[l2] = 2;
                                                        imp.i[l3] = 3;
                                                        imp.i[l4] = 4;
                                                        imp.i[l5] = 5;
                                                        imp.i[l6] = 6;
                                                        #pragma omp critical
                                                        {
                                                            vect_implem.push_back(imp);
                                                            cout<<"Solution found with : "<<omp_get_thread_num()<<" and permutation "<<l1<<" "<<l2<<" "<<l3<<" "<<l4<<" "<<l5<<" "<<l6<<" and k="<<k<<endl;
                                                            int comp = vect_implem.size();
                                                            vect_implem = remove_duplicates_impl(vect_implem);
                                                            nb_sol = vect_implem.size();
                                                            if (comp == nb_sol) {
                                                                cout<<"New solution"<<endl;
                                                            }
                                                            else {
                                                                cout<<"Not a new one"<<endl;
                                                            }
                                                        }
                                                        if (nb_sol_wanted != -1) {
                                                            if (nb_sol >= nb_sol_wanted)  {
                                                                #pragma omp atomic write
                                                                stop = 1;
                                                                cout<<"Number of wanted solutions reached"<<endl;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (nb_lignes == 7) {

                            vector<vector<poly>> vect_perm;

                            #pragma omp critical
                            {
                                for (uint32_t k=0; k< NB_PERM_MAX_8; k++) {
                                    ranges::shuffle(lignes_m, gen);
                                    vect_perm.push_back(lignes_m);
                                }
                            }

                            for (uint32_t k=0; k<vect_perm.size() && !stop ; k++)    {
                                poly l1 = vect_perm[k][0]; //1ère ligne manquante
                                poly l2 = vect_perm[k][1]; //2ème ligne manquante
                                poly l3 = vect_perm[k][2]; //3ème ligne manquante
                                poly l4 = vect_perm[k][3]; //4ème ligne manquante
                                poly l5 = vect_perm[k][4]; //5ème ligne manquante
                                poly l6 = vect_perm[k][5]; //6ème ligne manquante
                                poly l7 = vect_perm[k][6]; //7ème ligne manquante
                                auto Now = chrono::steady_clock::now();
                                auto time_spent = chrono::duration_cast<chrono::duration<double>>(Now - begin);
                                if (time_spent.count() > time_max)  {
                                    #pragma omp atomic write
                                    stop = 1;
                                }
                                vector<set<poly>> vect_op_selec2 = Test_xor(l1, op_selec1, set_op, size_set, map_xor, size_map_xor, nb_op);
                                if (vect_op_selec2.empty() == 1)   {
                                    continue;
                                }
                                for (uint32_t l=0; l<vect_op_selec2.size() && !stop; l++)    {
                                    set<poly> op_selec2 = vect_op_selec2[l];
                                    uint8_t nb_op2 = nb_op_init - op_selec2.size();
                                    vector<set<poly>> vect_op_selec3 = Test_xor(l2, op_selec2, set_op, size_set, map_xor, size_map_xor, nb_op2);
                                    if (vect_op_selec3.empty() == 1)   {
                                        continue;
                                    }
                                    for (uint32_t m=0; m<vect_op_selec3.size() && !stop; m++)    {
                                        set<poly> op_selec3 = vect_op_selec3[m];
                                        uint8_t nb_op3 = nb_op_init - op_selec3.size();
                                        vector<set<poly>> vect_op_selec4 = Test_xor(l3, op_selec3, set_op, size_set, map_xor, size_map_xor, nb_op3);
                                        if (vect_op_selec4.empty() == 1)   {
                                            continue;
                                        }
                                        for (uint32_t n=0; n<vect_op_selec4.size() && !stop; n++)    {
                                            set<poly> op_selec4 = vect_op_selec4[n];
                                            uint8_t nb_op4 = nb_op_init - op_selec4.size();
                                            vector<set<poly>> vect_op_selec5 = Test_xor(l4, op_selec4, set_op, size_set, map_xor, size_map_xor, nb_op4);
                                            if (vect_op_selec5.empty() == 1)   {
                                                continue;
                                            }
                                            for (uint32_t p=0; p<vect_op_selec5.size() && !stop; p++)    {
                                                Now = chrono::steady_clock::now();
                                                time_spent = chrono::duration_cast<chrono::duration<double>>(Now - begin);
                                                if (time_spent.count() > time_max)  {
                                                    #pragma omp atomic write
                                                    stop = 1;
                                                }
                                                set<poly> op_selec5 = vect_op_selec5[p];
                                                uint8_t nb_op5 = nb_op_init - op_selec5.size();
                                                vector<set<poly>> vect_op_selec6 = Test_xor(l5, op_selec5, set_op, size_set, map_xor, size_map_xor, nb_op5);
                                                if (vect_op_selec6.empty() == 1)   {
                                                    continue;
                                                }
                                                for (uint32_t q=0; q<vect_op_selec6.size() && !stop; q++)    {
                                                    set<poly> op_selec6 = vect_op_selec6[q];
                                                    uint8_t nb_op6 = nb_op_init - op_selec6.size();
                                                    vector<set<poly>> vect_op_selec7 = Test_xor(l6, op_selec6, set_op, size_set, map_xor, size_map_xor, nb_op6);
                                                    if (vect_op_selec7.empty() == 1)   {
                                                        continue;
                                                    }
                                                    for (uint32_t r=0; r<vect_op_selec7.size() && !stop; r++)    {
                                                        set<poly> op_selec7 = vect_op_selec7[r];
                                                        uint8_t nb_op7 = nb_op_init - op_selec7.size();
                                                        vector<set<poly>> vect_op_selec8 = Test_xor(l7, op_selec7, set_op, size_set, map_xor, size_map_xor, nb_op7);
                                                        if (vect_op_selec8.empty() == 1)   {
                                                            continue;
                                                        }
                                                        for (uint32_t s=0; s<vect_op_selec8.size() && !stop; s++)    {
                                                            set<poly> op_selec8 = vect_op_selec8[s];
                                                            implem_non_lin imp;
                                                            imp.op = op_selec8;
                                                            imp.i[lignes_m_init[i]] = 0;
                                                            imp.i[l1] = 1;
                                                            imp.i[l2] = 2;
                                                            imp.i[l3] = 3;
                                                            imp.i[l4] = 4;
                                                            imp.i[l5] = 5;
                                                            imp.i[l6] = 6;
                                                            imp.i[l7] = 7;
                                                            #pragma omp critical
                                                            {
                                                                vect_implem.push_back(imp);
                                                                cout<<"Solution found with : "<<omp_get_thread_num()<<" and permutation "<<l1<<" "<<l2<<" "<<l3<<" "<<l4<<" "<<l5<<" "<<l6<<" "<<l7<<" and k="<<k<<endl;
                                                                int comp = vect_implem.size();
                                                                vect_implem = remove_duplicates_impl(vect_implem);
                                                                nb_sol = vect_implem.size();
                                                                if (comp == nb_sol) {
                                                                    cout<<"New solution"<<endl;
                                                                }
                                                                else {
                                                                    cout<<"Not a new one"<<endl;
                                                                }
                                                            }
                                                            if (nb_sol_wanted != -1) {
                                                                if (nb_sol >= nb_sol_wanted)  {
                                                                    #pragma omp atomic write
                                                                    stop = 1;
                                                                    cout<<"Number of wanted solutions reached"<<endl;
                                                                }
                                                            }
                                                        }
                                                    }                                                
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (nb_lignes == 8) {

                            vector<vector<poly>> vect_perm;
                            #pragma omp critical
                            {
                                for (uint32_t k=0; k< NB_PERM_MAX_9; k++) {
                                    ranges::shuffle(lignes_m, gen);
                                    vect_perm.push_back(lignes_m);
                                }
                            }

                            for (uint32_t k=0; k<vect_perm.size() && !stop ; k++)    {
                                auto Now = chrono::steady_clock::now();
                                auto time_spent = chrono::duration_cast<chrono::duration<double>>(Now - begin);
                                if (time_spent.count() > time_max)  {
                                    #pragma omp atomic write
                                    stop = 1;
                                }
                                poly l1 = vect_perm[k][0]; //1ère ligne manquante
                                poly l2 = vect_perm[k][1]; //2ème ligne manquante
                                poly l3 = vect_perm[k][2]; //3ème ligne manquante
                                poly l4 = vect_perm[k][3]; //4ème ligne manquante
                                poly l5 = vect_perm[k][4]; //5ème ligne manquante
                                poly l6 = vect_perm[k][5]; //6ème ligne manquante
                                poly l7 = vect_perm[k][6]; //7ème ligne manquante
                                poly l8 = vect_perm[k][7]; //8ème ligne manquante
                                if (time_spent.count() > time_max)  {
                                    #pragma omp atomic write
                                    stop = 1;
                                }
                                    vector<set<poly>> vect_op_selec2 = Test_xor(l1, op_selec1, set_op, size_set, map_xor, size_map_xor, nb_op);
                                    if (vect_op_selec2.empty() == 1)   {
                                        continue;
                                    }
                                    for (uint32_t l=0; l<vect_op_selec2.size() && !stop; l++)    {
                                    set<poly> op_selec2 = vect_op_selec2[l];
                                    uint8_t nb_op2 = nb_op_init - op_selec2.size();
                                    vector<set<poly>> vect_op_selec3 = Test_xor(l2, op_selec2, set_op, size_set, map_xor, size_map_xor, nb_op2);
                                    if (vect_op_selec3.empty() == 1)   {
                                        continue;
                                    }
                                    for (uint32_t m=0; m<vect_op_selec3.size() && !stop; m++)    {
                                        set<poly> op_selec3 = vect_op_selec3[m];
                                        uint8_t nb_op3 = nb_op_init - op_selec3.size();
                                        vector<set<poly>> vect_op_selec4 = Test_xor(l3, op_selec3, set_op, size_set, map_xor, size_map_xor, nb_op3);
                                        if (vect_op_selec4.empty() == 1)   {
                                            continue;
                                        }
                                        for (uint32_t n=0; n<vect_op_selec4.size() && !stop; n++)    {
                                            set<poly> op_selec4 = vect_op_selec4[n];
                                            uint8_t nb_op4 = nb_op_init - op_selec4.size();
                                            vector<set<poly>> vect_op_selec5 = Test_xor(l4, op_selec4, set_op, size_set, map_xor, size_map_xor, nb_op4);
                                            if (vect_op_selec5.empty() == 1)   {
                                                continue;
                                            }
                                            for (uint32_t p=0; p<vect_op_selec5.size() && !stop; p++)    {
                                                Now = chrono::steady_clock::now();
                                                time_spent = chrono::duration_cast<chrono::duration<double>>(Now - begin);
                                                if (time_spent.count() > time_max)  {
                                                    #pragma omp atomic write
                                                    stop = 1;
                                                }
                                                set<poly> op_selec5 = vect_op_selec5[p];
                                                uint8_t nb_op5 = nb_op_init - op_selec5.size();
                                                vector<set<poly>> vect_op_selec6 = Test_xor(l5, op_selec5, set_op, size_set, map_xor, size_map_xor, nb_op5);
                                                if (vect_op_selec6.empty() == 1)   {
                                                    continue;
                                                }
                                                for (uint32_t q=0; q<vect_op_selec6.size() && !stop; q++)    {
                                                    set<poly> op_selec6 = vect_op_selec6[q];
                                                    uint8_t nb_op6 = nb_op_init - op_selec6.size();
                                                    vector<set<poly>> vect_op_selec7 = Test_xor(l6, op_selec6, set_op, size_set, map_xor, size_map_xor, nb_op6);
                                                    if (vect_op_selec7.empty() == 1)   {
                                                        continue;
                                                    }
                                                    for (uint32_t r=0; r<vect_op_selec7.size() && !stop; r++)    {
                                                        set<poly> op_selec7 = vect_op_selec7[r];
                                                        uint8_t nb_op7 = nb_op_init - op_selec7.size();
                                                        vector<set<poly>> vect_op_selec8 = Test_xor(l7, op_selec7, set_op, size_set, map_xor, size_map_xor, nb_op7);
                                                        if (vect_op_selec8.empty() == 1)   {
                                                            continue;
                                                        }
                                                        for (uint32_t s=0; s<vect_op_selec8.size() && !stop; s++)    {
                                                            set<poly> op_selec8 = vect_op_selec8[s];
                                                            uint8_t nb_op8 = nb_op_init - op_selec8.size();
                                                            vector<set<poly>> vect_op_selec9 = Test_xor(l8, op_selec8, set_op, size_set, map_xor, size_map_xor, nb_op8);
                                                            if (vect_op_selec9.empty() == 1)   {
                                                                continue;
                                                            }
                                                            for (uint32_t t=0; t<vect_op_selec9.size() && !stop; t++)    {
                                                                set<poly> op_selec9 = vect_op_selec9[t];
                                                                implem_non_lin imp;
                                                                imp.op = op_selec9;
                                                                imp.i[lignes_m_init[i]] = 0;
                                                                imp.i[l1] = 1;
                                                                imp.i[l2] = 2;
                                                                imp.i[l3] = 3;
                                                                imp.i[l4] = 4;
                                                                imp.i[l5] = 5;
                                                                imp.i[l6] = 6;
                                                                imp.i[l7] = 7;
                                                                imp.i[l8] = 8;
                                                                #pragma omp critical
                                                                {
                                                                    vect_implem.push_back(imp);
                                                                    cout<<"Solution found with : "<<omp_get_thread_num()<<" and permutation "<<l1<<" "<<l2<<" "<<l3<<" "<<l4<<" "<<l5<<" "<<l6<<" "<<l7<<" "<<l8<<" and k="<<k<<endl;
                                                                    int comp = vect_implem.size();
                                                                    vect_implem = remove_duplicates_impl(vect_implem);
                                                                    nb_sol = vect_implem.size();
                                                                    if (comp == nb_sol) {
                                                                        cout<<"New solution"<<endl;
                                                                        for (auto it = op_selec9.begin(); it != op_selec9.end(); it++){
                                                                            cout<<*it<<" ";
                                                                        }
                                                                        cout<<endl;
                                                                    }
                                                                    else {
                                                                        cout<<"Not a new one"<<endl;
                                                                    }
                                                                }
                                                                nb_sol = vect_implem.size();
                                                                if (nb_sol_wanted != -1) {
                                                                    if (nb_sol >= nb_sol_wanted)  {
                                                                        #pragma omp atomic write
                                                                        stop = 1;
                                                                        cout<<"Number of wanted solutions reached"<<endl;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }                                     
                                }
                            }
                        }
                        //cout<<"Next triplet for thread "<< omp_get_thread_num()<<endl;
                    }
                }
                if (vect_implem.empty() == 1)   {
                    cout<<" No solutions found with line "<<i<<endl;
                }
            }
            else {
                cout<<"We can not obtain line "<<i<<" with 2 xor"<<endl;
            }
        }
    }
    /*  STEP 4 : */
    if (vect_implem.empty() == 1)   {
        cout<<"Begin step 4"<<endl;

       for (uint32_t i=0 ; i<lignes_m_init.size() && !stop; i++) {   
            vector<set<poly>> set_op_sol;          
            for (uint32_t j=0 ; j < size_map_xor && !stop; j++)    {
                poly elem = lignes_m_init[i] ^ map_xor[j].first;
                int32_t indice = find_map(elem, map_xor, 0, size_map_xor);
                if (indice != -1)   {

                    random_device rd;  // a seed source for the random number engine
                    mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
                    uniform_int_distribution<int> distrib(0, 9);
                    int random_indice = distrib(gen);
                    int random_indice2 = distrib(gen);

                    set<poly> op;
                    op.insert(map_xor[j].second[random_indice][0]);
                    op.insert(map_xor[j].second[random_indice][1]);
                    op.insert(map_xor[indice].second[random_indice2][0]);
                    op.insert(map_xor[indice].second[random_indice2][1]);
                    set_op_sol.push_back(op);
                }
            }

            set_op_sol = remove_duplicates_set(set_op_sol);

            if (set_op_sol.empty() != 1){

                cout<<"We can obtain line "<<i<<" : "<<lignes_m_init[i]<<" with 3 xor"<<endl;

                random_device rd;  // a seed source for the random number engine
                mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
                shuffle (set_op_sol.begin(), set_op_sol.end(), gen);
                cout<<"We have "<<set_op_sol.size()<<" quadruplets to test for line " <<i<<" : "<<lignes_m_init[i]<<endl;

                time_t now = chrono::system_clock::to_time_t(chrono::system_clock::now());
                cout << "Time is " << ctime(&now) << endl;

                vector<poly> lignes_m;
                lignes_m = supp(lignes_m_init[i], lignes_m_init); // On supprime la i-ème ligne des lignes manquantes

                uint8_t nb_op = nb_op_init - 4;
                uint8_t nb_lignes = lignes_m.size();

                #pragma omp parallel shared(stop)
                {
                    bool stop_local = false;
                    #pragma omp for schedule (dynamic)

                    for (uint32_t j=0; j<set_op_sol.size(); j++)   {
                        if (stop_local) {
                            continue;
                        }
                        if (stop) {
                            stop_local = true;
                            continue;
                        }

                        set<poly> op_selec1 = set_op_sol[j];
                        if (nb_lignes == 7) {

                            vector<vector<poly>> vect_perm;
                            
                            #pragma omp critical
                            {
                                for (uint32_t k=0; k< NB_PERM_MAX_8; k++) {
                                    ranges::shuffle(lignes_m, gen);
                                    vect_perm.push_back(lignes_m);
                                }
                            }

                            for (uint32_t k=0; k<NB_PERM_MAX_8 && !stop ; k++)    {
                                auto Now = chrono::steady_clock::now();
                                auto time_spent = chrono::duration_cast<chrono::duration<double>>(Now - begin);
                                if (time_spent.count() > time_max)  {
                                    #pragma omp atomic write
                                    stop = 1;
                                }
                                poly l1 = vect_perm[k][0]; //1ère ligne manquante
                                poly l2 = vect_perm[k][1]; //2ème ligne manquante
                                poly l3 = vect_perm[k][2]; //3ème ligne manquante
                                poly l4 = vect_perm[k][3]; //4ème ligne manquante
                                poly l5 = vect_perm[k][4]; //5ème ligne manquante
                                poly l6 = vect_perm[k][5]; //6ème ligne manquante
                                poly l7 = vect_perm[k][6]; //7ème ligne manquante
                                if (time_spent.count() > time_max)  {
                                    #pragma omp atomic write
                                    stop = 1;
                                }
                                vector<set<poly>> vect_op_selec2 = Test_xor(l1, op_selec1, set_op, size_set, map_xor, size_map_xor, nb_op);
                                if (vect_op_selec2.empty() == 1)   {
                                    continue;
                                }
                                for (uint32_t l=0; l<vect_op_selec2.size() && !stop; l++)    {
                                    set<poly> op_selec2 = vect_op_selec2[l];
                                    uint8_t nb_op2 = nb_op_init - op_selec2.size();
                                    vector<set<poly>> vect_op_selec3 = Test_xor(l2, op_selec2, set_op, size_set, map_xor, size_map_xor, nb_op2);
                                    if (vect_op_selec3.empty() == 1)   {
                                        continue;
                                    }
                                    for (uint32_t m=0; m<vect_op_selec3.size() && !stop; m++)    {
                                        set<poly> op_selec3 = vect_op_selec3[m];
                                        uint8_t nb_op3 = nb_op_init - op_selec3.size();
                                        vector<set<poly>> vect_op_selec4 = Test_xor(l3, op_selec3, set_op, size_set, map_xor, size_map_xor, nb_op3);
                                        if (vect_op_selec4.empty() == 1)   {
                                            continue;
                                        }
                                        for (uint32_t n=0; n<vect_op_selec4.size() && !stop; n++)    {
                                            set<poly> op_selec4 = vect_op_selec4[n];
                                            uint8_t nb_op4 = nb_op_init - op_selec4.size();
                                            vector<set<poly>> vect_op_selec5 = Test_xor(l4, op_selec4, set_op, size_set, map_xor, size_map_xor, nb_op4);
                                            if (vect_op_selec5.empty() == 1)   {
                                                continue;
                                            }
                                            for (uint32_t p=0; p<vect_op_selec5.size() && !stop; p++)    {
                                                Now = chrono::steady_clock::now();
                                                time_spent = chrono::duration_cast<chrono::duration<double>>(Now - begin);
                                                if (time_spent.count() > time_max)  {
                                                    #pragma omp atomic write
                                                    stop = 1;
                                                }
                                                set<poly> op_selec5 = vect_op_selec5[p];
                                                uint8_t nb_op5 = nb_op_init - op_selec5.size();
                                                vector<set<poly>> vect_op_selec6 = Test_xor(l5, op_selec5, set_op, size_set, map_xor, size_map_xor, nb_op5);
                                                if (vect_op_selec6.empty() == 1)   {
                                                    continue;
                                                }
                                                for (uint32_t q=0; q<vect_op_selec6.size() && !stop; q++)    {
                                                    set<poly> op_selec6 = vect_op_selec6[q];
                                                    uint8_t nb_op6 = nb_op_init - op_selec6.size();
                                                    vector<set<poly>> vect_op_selec7 = Test_xor(l6, op_selec6, set_op, size_set, map_xor, size_map_xor, nb_op6);
                                                    if (vect_op_selec7.empty() == 1)   {
                                                        continue;
                                                    }
                                                    for (uint32_t r=0; r<vect_op_selec7.size() && !stop; r++)    {
                                                        set<poly> op_selec7 = vect_op_selec7[r];
                                                        uint8_t nb_op7 = nb_op_init - op_selec7.size();
                                                        vector<set<poly>> vect_op_selec8 = Test_xor(l7, op_selec7, set_op, size_set, map_xor, size_map_xor, nb_op7);
                                                        if (vect_op_selec8.empty() == 1)   {
                                                            continue;
                                                        }
                                                        for (uint32_t s=0; s<vect_op_selec8.size() && !stop; s++)    {
                                                            set<poly> op_selec8 = vect_op_selec8[s];
                                                            implem_non_lin imp;
                                                            imp.op = op_selec8;
                                                            imp.i[lignes_m_init[i]] = 0;
                                                            imp.i[l1] = 1;
                                                            imp.i[l2] = 2;
                                                            imp.i[l3] = 3;
                                                            imp.i[l4] = 4;
                                                            imp.i[l5] = 5;
                                                            imp.i[l6] = 6;
                                                            imp.i[l7] = 7;
                                                            #pragma omp critical
                                                            {
                                                                vect_implem.push_back(imp);
                                                                cout<<"Solution found with : "<<omp_get_thread_num()<<" and permutation "<<l1<<" "<<l2<<" "<<l3<<" "<<l4<<" "<<l5<<" "<<l6<<" "<<l7<<" and k="<<k<<endl;
                                                                int comp = vect_implem.size();
                                                                vect_implem = remove_duplicates_impl(vect_implem);
                                                                nb_sol = vect_implem.size();
                                                                if (comp == nb_sol) {
                                                                    cout<<"New solution"<<endl;
                                                                    for (auto it = op_selec8.begin(); it != op_selec8.end(); it++){
                                                                        cout<<*it<<" ";
                                                                    }
                                                                    cout<<endl;
                                                                }
                                                                else {
                                                                    cout<<"Not a new one"<<endl;
                                                                }
                                                            }
                                                            nb_sol = vect_implem.size();
                                                            if (nb_sol_wanted != -1) {
                                                                if (nb_sol >= nb_sol_wanted)  {
                                                                    #pragma omp atomic write
                                                                    stop = 1;
                                                                    cout<<"Number of wanted solutions reached"<<endl;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }                                     
                                }
                            }
                        }
                        if (nb_lignes == 8) {

                            vector<vector<poly>> vect_perm;
                            
                            #pragma omp critical
                            {
                                for (uint32_t k=0; k< NB_PERM_MAX_9; k++) {
                                    ranges::shuffle(lignes_m, gen);
                                    vect_perm.push_back(lignes_m);
                                }
                            }

                            for (uint32_t k=0; k<NB_PERM_MAX_9 && !stop ; k++)    {
                                auto Now = chrono::steady_clock::now();
                                auto time_spent = chrono::duration_cast<chrono::duration<double>>(Now - begin);
                                if (time_spent.count() > time_max)  {
                                    #pragma omp atomic write
                                    stop = 1;
                                }
                                poly l1 = vect_perm[k][0]; //1ère ligne manquante
                                poly l2 = vect_perm[k][1]; //2ème ligne manquante
                                poly l3 = vect_perm[k][2]; //3ème ligne manquante
                                poly l4 = vect_perm[k][3]; //4ème ligne manquante
                                poly l5 = vect_perm[k][4]; //5ème ligne manquante
                                poly l6 = vect_perm[k][5]; //6ème ligne manquante
                                poly l7 = vect_perm[k][6]; //7ème ligne manquante
                                poly l8 = vect_perm[k][7]; //8ème ligne manquante
                                if (time_spent.count() > time_max)  {
                                    #pragma omp atomic write
                                    stop = 1;
                                }
                                    vector<set<poly>> vect_op_selec2 = Test_xor(l1, op_selec1, set_op, size_set, map_xor, size_map_xor, nb_op);
                                    if (vect_op_selec2.empty() == 1)   {
                                        continue;
                                    }
                                    for (uint32_t l=0; l<vect_op_selec2.size() && !stop; l++)    {
                                    set<poly> op_selec2 = vect_op_selec2[l];
                                    uint8_t nb_op2 = nb_op_init - op_selec2.size();
                                    vector<set<poly>> vect_op_selec3 = Test_xor(l2, op_selec2, set_op, size_set, map_xor, size_map_xor, nb_op2);
                                    if (vect_op_selec3.empty() == 1)   {
                                        continue;
                                    }
                                    for (uint32_t m=0; m<vect_op_selec3.size() && !stop; m++)    {
                                        set<poly> op_selec3 = vect_op_selec3[m];
                                        uint8_t nb_op3 = nb_op_init - op_selec3.size();
                                        vector<set<poly>> vect_op_selec4 = Test_xor(l3, op_selec3, set_op, size_set, map_xor, size_map_xor, nb_op3);
                                        if (vect_op_selec4.empty() == 1)   {
                                            continue;
                                        }
                                        for (uint32_t n=0; n<vect_op_selec4.size() && !stop; n++)    {
                                            set<poly> op_selec4 = vect_op_selec4[n];
                                            uint8_t nb_op4 = nb_op_init - op_selec4.size();
                                            vector<set<poly>> vect_op_selec5 = Test_xor(l4, op_selec4, set_op, size_set, map_xor, size_map_xor, nb_op4);
                                            if (vect_op_selec5.empty() == 1)   {
                                                continue;
                                            }
                                            for (uint32_t p=0; p<vect_op_selec5.size() && !stop; p++)    {
                                                Now = chrono::steady_clock::now();
                                                time_spent = chrono::duration_cast<chrono::duration<double>>(Now - begin);
                                                if (time_spent.count() > time_max)  {
                                                    #pragma omp atomic write
                                                    stop = 1;
                                                }
                                                set<poly> op_selec5 = vect_op_selec5[p];
                                                uint8_t nb_op5 = nb_op_init - op_selec5.size();
                                                vector<set<poly>> vect_op_selec6 = Test_xor(l5, op_selec5, set_op, size_set, map_xor, size_map_xor, nb_op5);
                                                if (vect_op_selec6.empty() == 1)   {
                                                    continue;
                                                }
                                                for (uint32_t q=0; q<vect_op_selec6.size() && !stop; q++)    {
                                                    set<poly> op_selec6 = vect_op_selec6[q];
                                                    uint8_t nb_op6 = nb_op_init - op_selec6.size();
                                                    vector<set<poly>> vect_op_selec7 = Test_xor(l6, op_selec6, set_op, size_set, map_xor, size_map_xor, nb_op6);
                                                    if (vect_op_selec7.empty() == 1)   {
                                                        continue;
                                                    }
                                                    for (uint32_t r=0; r<vect_op_selec7.size() && !stop; r++)    {
                                                        set<poly> op_selec7 = vect_op_selec7[r];
                                                        uint8_t nb_op7 = nb_op_init - op_selec7.size();
                                                        vector<set<poly>> vect_op_selec8 = Test_xor(l7, op_selec7, set_op, size_set, map_xor, size_map_xor, nb_op7);
                                                        if (vect_op_selec8.empty() == 1)   {
                                                            continue;
                                                        }
                                                        for (uint32_t s=0; s<vect_op_selec8.size() && !stop; s++)    {
                                                            set<poly> op_selec8 = vect_op_selec8[s];
                                                            uint8_t nb_op8 = nb_op_init - op_selec8.size();
                                                            vector<set<poly>> vect_op_selec9 = Test_xor(l8, op_selec8, set_op, size_set, map_xor, size_map_xor, nb_op8);
                                                            if (vect_op_selec9.empty() == 1)   {
                                                                continue;
                                                            }
                                                            for (uint32_t t=0; t<vect_op_selec9.size() && !stop; t++)    {
                                                                set<poly> op_selec9 = vect_op_selec9[t];
                                                                implem_non_lin imp;
                                                                imp.op = op_selec9;
                                                                imp.i[lignes_m_init[i]] = 0;
                                                                imp.i[l1] = 1;
                                                                imp.i[l2] = 2;
                                                                imp.i[l3] = 3;
                                                                imp.i[l4] = 4;
                                                                imp.i[l5] = 5;
                                                                imp.i[l6] = 6;
                                                                imp.i[l7] = 7;
                                                                imp.i[l8] = 8;
                                                                #pragma omp critical
                                                                {
                                                                    vect_implem.push_back(imp);
                                                                    cout<<"Solution found with : "<<omp_get_thread_num()<<" and permutation "<<l1<<" "<<l2<<" "<<l3<<" "<<l4<<" "<<l5<<" "<<l6<<" "<<l7<<" "<<l8<<" and k="<<k<<endl;
                                                                    int comp = vect_implem.size();
                                                                    vect_implem = remove_duplicates_impl(vect_implem);
                                                                    nb_sol = vect_implem.size();
                                                                    if (comp == nb_sol) {
                                                                        cout<<"New solution"<<endl;
                                                                        for (auto it = op_selec9.begin(); it != op_selec9.end(); it++){
                                                                            cout<<*it<<" ";
                                                                        }
                                                                        cout<<endl;
                                                                    }
                                                                    else {
                                                                        cout<<"Not a new one"<<endl;
                                                                    }
                                                                }
                                                                nb_sol = vect_implem.size();
                                                                if (nb_sol_wanted != -1) {
                                                                    if (nb_sol >= nb_sol_wanted)  {
                                                                        #pragma omp atomic write
                                                                        stop = 1;
                                                                        cout<<"Number of wanted solutions reached"<<endl;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }                                     
                                }
                            }
                        }
                        //cout<<"Next quadruplet for thread "<< omp_get_thread_num()<<endl;
                    }
                }
                if (vect_implem.empty() == 1)   {
                    cout<<" No solutions found with line "<<i<<endl;
                }
            }
            else {
                cout<<"We can not obtain line "<<i<<" : "<<lignes_m_init[i]<<" with 3 xor"<<endl;
            }
        }
    }
    cout<<"Begin recovery part"<<endl;
    vect_implem = remove_duplicates_impl(vect_implem);
    vector<map<uint32_t,vector<poly>>> res;
    #pragma omp parallel
    {
        #pragma omp for schedule(dynamic)
        for (uint32_t i=0; i<vect_implem.size(); i++)   {
            map<uint32_t,vector<poly>> implem;
            implem = set_to_implem (vect_implem[i].op, Y, vect_implem[i].i );
            /*if (implem.size() != Y.size())  {
                cout<<"Error in recovery part : size of implem = "<<implem.size()<<endl;
            }*/
            #pragma omp critical 
            {
                res.push_back(implem);
            }
        }
    }
    cout<<"End of the non-linear part" <<endl;
    auto now = chrono::system_clock::to_time_t(chrono::system_clock::now());
    cout << "Time is " << ctime(&now) << endl;
    return res;
}