#ifndef PRECALCUL_H
#define PRECALCUL_H

#include <fstream>
#include "poly.h"

/*!
 * \file precalcul.h
 * \brief This file contains the functions related to the precomputation.
 */

/*!
* \var pair_xor
* \brief Type defined to represent Map_xor. It matches an operation x with 10 couples (y1,y2) such as x = y1 ^ y2.
*/
typedef pair<poly, poly [10][2]> pair_xor;

/*!
* \var pair_lin
* \brief Type defined to represent the correspondance beetween elements of set_op and linear operations. It matches an operation x with a couple (l1,l2) such as x = l1 & l2.
*/
typedef pair<poly, poly [2]> pair_lin; 

/*!
*For computing the precomputation data : 
*Create a matrix with 3 columns where each row contains 2 linear operations and the quadratic operation obtained by performing a AND beetween these 2 functions. For example, the line 10|13|61 means : (10 = Ob1010 = x0+x2) * (13 = Ob1101 = x0+x1+x3) = (x0 + x0x1 + x0x3 + x0x2 + x1x2 + x2x3 = Ob111101 = 61).
*/
vector<vector<poly>> create_mat_op(int nb_bits);

/*!
*For computing the precomputation data : 
*Create set_op from the 3-column matrix.
*/
set<poly> create_set_op( vector<vector<poly>> * Mat_op);

/*!
*For computing the precomputation data : 
*Create map_xor from set_op.
*/
map<poly,set<set<poly>>> create_map (set<poly> * set_op);

/*!
*For computing the precomputation data : 
*Create a map to associate one quadratic operation x with only one couple (l1,l2) such as x = l1 ^ l2.
*/
map<poly,pair<poly,poly>> create_map_lin (vector<vector<poly>> Mat_op, set<poly> set_op, uint8_t nb_bits);

/*!
*As precomutation data are stored as static arrays : To associate a size in bits to the size of the corresponding set_op.
*/
uint32_t nb_bits_to_size_set (uint32_t size);

/*!
*As precomutation data are stored as static arrays : To associate a size in bits to the size of the corresponding map_xor.
*/
uint32_t nb_bits_to_size_map_xor (uint32_t size);

/*!
*Create the static array representing set_op.
*/
void parse_file_and_create_set(uint32_t size, poly set_op []);

/*!
*Create the static array representing map_lin.
*/
void parse_file_and_create_map_lin(uint32_t size, pair_lin map_lin []);

/*!
*Create the static array representing map_xor.
*/
void parse_file_and_create_map_xor(uint32_t size, pair_xor map_xor []);

/*!
*Find the position of the value val in set_op.
*/
int64_t find_set (poly val, poly set_op [], uint64_t look_start, uint64_t look_end);

/*!
*Find the position of the value val in map_xor.
*/
int64_t find_map (poly val, pair_xor v [], uint64_t look_start, uint64_t look_end);

/*!
*Find the position of the value val in map_lin.
*/
int64_t find_map_lin (poly val, pair_lin v [], uint64_t look_start, uint64_t look_end);

/*!
*Create the map_lin associated to the quadratic operations in set_op
*/
map<poly,pair<poly,poly>> create_map_lin_tab (uint32_t size, pair_lin map_lin [], uint32_t size_map_lin, set<poly> set_op);

#endif 