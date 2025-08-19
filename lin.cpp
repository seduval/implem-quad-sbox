#include "config.h"
#include "poly.h"
#include "precalcul.h"
#include "non_lin.h"
#include "lin.h"

using namespace std;

set<poly> create_set_op_lin (uint8_t nb_bits)   {
    // Compute the set of linear monomials. The set of linear monomials on n bits corresponds to all the powers of 2 between 1 and 2^n -1.
    set<poly> set_op;
    for (poly i=0; i<nb_bits; i++)  {
        set_op.insert(1ul<<i);
    }
    return set_op;
}

set<poly> create_set_op_lin2 (set<poly> * set_op1)   {
    set<poly> set_op;
    for (auto it = (*set_op1).begin(); it != (*set_op1).end(); it++) {
        for (auto it2 = next(it); it2 != (*set_op1).end(); it2++) {
            set_op.insert(*it ^ *it2);
        }
    }
    return set_op;
}

implem_lin test_xor_lin(poly x, set<poly> * op_selec, uint8_t a) {
    implem_lin sol;
    sol.nb_xor = a - 1 ;
    poly elem1;
    poly elem2;
    poly elem3;
    if (a==1) {
        auto it = (*op_selec).find(x);
        if (it != (*op_selec).end()) {
            sol.op_set.insert(x);           
        }
    }
    if (a==2) {
        for (auto i = (*op_selec).begin() ; i != (*op_selec).end(); i++) {
            elem1 = x ^ *i;
            auto it = (*op_selec).find(elem1);
            if (it != (*op_selec).end()) {
                sol.op_set.insert(x);
                sol.map_op[x].push_back(*i);
                sol.map_op[x].push_back(*it);
                break;                
            }
        }
    }
    if (a==3){
        bool test = false;
        for (auto i = (*op_selec).begin() ; i != (*op_selec).end() && !test; i++) {
            elem1 = x ^ *i;
            for (auto j = next(i) ; j != (*op_selec).end() && !test; j++) {
                elem2 = elem1 ^ *j;
                auto it = (*op_selec).find(elem2);
                if (it != (*op_selec).end()) {
                    sol.op_set.insert(*i ^ *j);
                    sol.op_set.insert(x);
                    sol.map_op[*i ^ *j].push_back(*i);
                    sol.map_op[*i ^ *j].push_back(*j);
                    sol.map_op[x].push_back(*i ^ *j);
                    sol.map_op[x].push_back(*it);
                    test = true;
                    break;      
                }
            }
        }
    }
    if (a==4){
        bool test = false;
        for (auto i = (*op_selec).begin() ; i != (*op_selec).end() && !test; i++) {
            elem1 = x ^ *i;
            for (auto j = next(i) ; j != (*op_selec).end() && !test; j++) {
                elem2 = elem1 ^ *j;
                for (auto k = next(j); k != (*op_selec).end() && !test; k++) {
                    elem3 = elem2 ^ *k;
                    auto it = (*op_selec).find(elem3);
                    if (it != (*op_selec).end()) {
                        sol.op_set.insert(*i ^ *j);
                        sol.op_set.insert(*k ^ *it);
                        sol.op_set.insert(x);
                        sol.map_op[*i ^ *j].push_back(*i);
                        sol.map_op[*i ^ *j].push_back(*j);
                        sol.map_op[*k ^ *it].push_back(*k);
                        sol.map_op[*k ^ *it].push_back(*it);
                        sol.map_op[x].push_back(*i ^ *j);
                        sol.map_op[x].push_back(*k ^ *it);
                        test = true;
                        break;      
                    }
                }
            }
        }
    }
    return sol;
}

implem_lin Test_xor_lin (poly x, set<poly> * op_selec)   {
    implem_lin sol;
    sol = test_xor_lin(x, op_selec, 1);
    if (sol.op_set.empty() != 1) {
        return sol;
    }
    sol = test_xor_lin(x, op_selec, 2);
    if (sol.op_set.empty() != 1) {
        return sol;
    }
    sol = test_xor_lin(x, op_selec, 3);
    if (sol.op_set.empty() != 1) {
        return sol;
    }
    sol = test_xor_lin(x, op_selec, 4);
    if (sol.op_set.empty() != 1) {
        return sol;
    }
    return sol;
}

implem return_implem_lin (set<poly> * set_op, set<poly> * set_op2, vector<poly> imp, int nb_xor_max, uint64_t time_max)   {
    auto begin = chrono::steady_clock::now();

    int stop_lin = 0;
   
    // Define initial parameters
    set<poly> sol_init;
    int nb_op_init = nb_xor_max;
    set<poly> op_selec_init = (*set_op);
    vector<poly> op_lin_init;
    for (auto it = (*set_op).begin(); it != (*set_op).end(); it ++)   {
        sol_init.insert(*it);
    }

    // STEP 1 : Test if an element of imp is equal to the XOR of two linear monomials 

    implem vect_map_init;
    vector<poly> perm_init;
    for (uint32_t i=0; i<imp.size(); i++) {
        auto it = (*set_op2).find(imp[i]);
        if (it != (*set_op2).end()) {
            op_selec_init.insert(*it);
            nb_op_init = nb_op_init - 1;
            perm_init.push_back(*it);
            map<poly,vector<poly>> map_init;
            map_init[*it].push_back(*it);
            vect_map_init.push_back(map_init);
        }
        else op_lin_init.push_back(imp[i]);
    }

    if (op_lin_init.empty()){
        return vect_map_init;
    }

    implem vect_sol;
    #pragma omp parallel shared (stop_lin)
    {
        bool stop_local = false;
        #pragma omp for schedule(static)
        for (uint64_t i=0; i<1000000000; i++)   {
            if (stop_local) {
                    continue;
                }
            if (stop_lin) {
                stop_local = true;
                continue;
            }
            auto Now = chrono::steady_clock::now();
            auto time_spent = chrono::duration_cast<chrono::duration<double>>(Now - begin);
            if (time_spent.count() > time_max)  {
                stop_lin = 1;
            }
            // Initial parameters
            vector<poly> perm = op_lin_init;
            implem vect_sol_local = vect_map_init;
            
            set<poly> op_selec_p = op_selec_init;
            set<poly> * op_selec;
            op_selec = &op_selec_p;
            int nb_op = nb_op_init;

            // Compute a random permutation of the linear operations to implement
            random_device rd;  // a seed source for the random number engine
            mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
            shuffle (perm.begin(), perm.end(), gen); 

            for (uint32_t j=0; j<perm.size() && !stop_lin ; j++) {
                implem_lin imp_lin = Test_xor_lin(perm[j], op_selec);

                if (imp_lin.op_set.empty() == 1)   {
                    //If Test_xor does not add any operation, we go to the next permutation.
                    break;
                }

                nb_op = nb_op - imp_lin.nb_xor;

                if (nb_op < 0)  {
                    // If we exceed the bound of XOR, we go to the next permutation.
                    break;
                }

                // Else we update op_selec and the vector of map. 
                for (auto it = imp_lin.op_set.begin(); it != imp_lin.op_set.end(); it++) {
                    (*op_selec).insert(*it);
                }
                vect_sol_local.push_back(imp_lin.map_op);

                if( j == perm.size() -1)    {
                    #pragma omp critical 
                    {
                        vect_sol = vect_sol_local;
                        stop_lin = 1;
                    }
                }
            }
        }
    }
    return vect_sol;
}