#ifndef POLY_H
#define POLY_H

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <set>
#include <iterator>
#include <vector>
#include <unordered_set>
#include <bitset>
#include <functional>
#include <omp.h>
#include <map>
#include <chrono>
#include <ctime>
#include <cmath>
#include <random>
#include <unistd.h>
#include <getopt.h>
#include <sstream>

#include "config.h"

/*!
 * \file poly.h
 * \brief This file contains the function related to operations on poly.
 */

using namespace std;

/*!
* \var poly
* \brief Type defined to represent a poly. Each bits of this integrer reflects the presence or absence of a quadratic monomial. The quadratic monomials are lexicographically ordered. 
*/
typedef uint64_t poly;

/*!
* Make the match between the AND of 2 linear monomials and the quadratic monomial obtained.
*/
uint64_t corres(uint32_t b1, uint32_t b2, int n);

/*!
*Return the hamming weight of the integrer representing the poly x.
*/
int hammingWeight(poly x);

/*!
* Return the element of a set having the lowest hamming weight and delete it from the initial set.
*/
poly lowest_hw(set<poly> * set_op,int nb_bits);

/*!
* Compute the ANF of a boolean function from its LUT.
*/
void lut_to_anf (uint32_t ** anf, uint32_t * lut, uint32_t size_in, uint32_t size_out);

/*!
* Transform the non-linear part of the ANF of an S_box to a vector of poly.
*/
vector<poly> anf_to_poly_non_lin(uint32_t ** anf, uint32_t size_in, uint32_t size_out);

/*!
* Transform the linear part of the ANF of an S_box to a vector of poly.
*/
vector<poly> anf_to_poly_lin(uint32_t ** anf, uint32_t size_in, uint32_t size_out);

vector<poly> anf_to_poly_neg(uint32_t ** anf, uint32_t size_in, uint32_t size_out);

/*!
* Delete the poly value in a vector.
*/
vector<poly> supp(poly value, vector<poly> Y);

/*!
* Compute all the permutations of the elements of a vector.
*/
vector<vector<poly>> Permutations(const vector<poly>& v);

/*!
* Remove identical sets in a vector of sets.
*/
vector<set<poly>> remove_duplicates_set(vector<set<poly>> vect_set);

/*!
* Print the monomials in a poly x.
*/
void print_monom(poly x, uint32_t nb_bits);

/*!
* Print the linear monomials that appear when the AND of 2 linear operations is performed and return the number of XOR that are added. 
* If we do (x0 + x1)*(x1 + x2), we need to add x1.
*/
uint32_t print_bit_lin_sup(poly x1 ,poly x2 ,uint32_t nb_bits);

#endif