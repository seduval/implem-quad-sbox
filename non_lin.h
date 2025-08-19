#ifndef NONLIN_H
#define NONLIN_H

#include "precalcul.h"

/*!
 * \file non_lin.h
 * \brief This file contains the functions related to the optimisation of the non-linear part.
 */

/*!
* \var indexx
* \brief Type defined to match an operation (non-linear or linear) with a number in order to know in which order operations have to be proceed 
*/
typedef map<poly,uint32_t> indexx; 

/*!
* \struct implem_non_lin
* \brief Structure used to represent the implementation of the non-linear part
*/
struct implem_non_lin{
    set<poly> op; /*!< Sets of operations needed in the implementation. */
    indexx i; /*!< Contains the order in which the output bits have to be implemented.*/ 
};

/*!
 * Test if a non-linear operation x can be obtained by xoring a operations of op_selec and b operations of set_op.
*/
vector<set<poly>> test_xor(poly x/*!<Quadratic operation(poly) we want to implement*/,
 vector<poly> op_selec/*!< Set of selected quadratic operations already used in previous step of the implementation*/, 
 uint8_t a/*!< Number of operations taken in op_selec*/,
 poly set_op []/*!< Set of quadratic operations(poly) which can be obtained by performing one AND gate between 2 linear operations. These operations are truncated from their linear part.*/, 
 uint32_t size_set /*!< Size of set_op as it is a static array*/, 
 pair_xor map_xor [] /*!< Set of quadratic operations(poly) that are obtained by XORing two elements of set_op. Each of these operations is followed by the possible couples to obtain it.*/, 
 uint32_t size_map_xor/*!< Size of map_xor as it is a static array*/, 
 uint8_t b/*!< Number of operations taken in set_op*/);

/*!
* Return a vector of sets in which each set has been uptated to get the operation x adding the fewest operations from set_op in op_selec. 
*/
vector<set<poly>> Test_xor (poly x/*!<Quadratic operation(poly) we want to implement*/,
 set<poly> op_selec/*!< Set of selected quadratic operations already used in previous step of the implementation*/,
 poly set_op []/*!< Set of quadratic operations(poly) which can be obtained by performing one AND gate between 2 linear operations. These operations are truncated from their linear part.*/ , 
 uint32_t size_set/*!< Size of set_op as it is a static array*/,
 pair_xor map_xor[]/*!< Set of quadratic operations(poly) that are obtained by XORing two elements of set_op. Each of these operations is followed by the possible couples to obtain it.*/,
 uint32_t size_map_xor/*!< Size of map_xor as it is a static array*/, 
 uint32_t nb_op/*!< Number of AND gate we add*/);

/*!
* Compute from Op_selec which quadratic operations will produce each output bit and save in ind the order to proceed the quadratic operations.
*/
map<uint32_t, vector<poly>> set_to_implem (set<poly> set_op, vector<poly> Y, indexx ind);

/*!
* Return the possible implementations of the non-linear part with at maximum nb_and_max AND gates. 
*/
vector<map<uint32_t,vector<poly>>> return_implem (poly set_op[]/*!< Set of quadratic operations(poly) which can be obtained by performing one AND gate between 2 linear operations. These operations are truncated from their linear part.*/,
 uint32_t size_set/*!< Size of set_op as it is a static array*/,
 pair_xor map_xor []/*!< Set of quadratic operations(poly) that are obtained by XORing two elements of set_op. Each of these operations is followed by the possible couples to obtain it.*/,
 uint32_t size_map_xor/*!< Size of map_xor as it is a static array*/,
 vector<poly> Y/*!<Each element of this vector represents an output bit of the s-box we want to implements*/, 
 uint8_t nb_and_max/*!<Maximum AND gates wanted on the final implementation*/, 
 int nb_sol_wanted/*!<Number of wanted solutions*/, 
 uint64_t time_max/*!<Bound on the running time in minutes*/);

#endif