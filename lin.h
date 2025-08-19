#ifndef LIN_H
#define LIN_H

#include "non_lin.h"

/*!
 * \file lin.h
 * \brief This file contains the functions related to the optimisation of the linear part.
 */

/*!
* \var implem
* \brief Type defined in order to save in which order linear expressions have to be proceeded
*/
typedef vector<map<poly, vector<poly>>> implem;

/*!
* \struct implem_lin
* \brief Structure used to represent the implementation of the linear part
*/
struct implem_lin   {
    set<poly> op_set; /*!< Set of poly that contains the linear perations we need to add in op_selec. */
    map<poly, vector<poly>> map_op; /*!< Map that matches a wanted linear operation with all the intermediate linear operations needed to obtain it. For example: x0 ^ x1 ^ x2 ^ x3 can be matched with x0 ^ x1 and x2 ^ x3.*/
    uint8_t nb_xor; /*!< Number of xor we will to get the operation. */
};

/*!
* Compute the set containing the linear monomials(poly) such as x0
*/
set<poly> create_set_op_lin (uint8_t nb_bits);

/*!
* Compute the set containing the XOR of 2 linear monomials(poly) such as x0 ^ x1
*/
set<poly> create_set_op_lin2 (set<poly> * set_op1);

/*!
* Test if a linear operation x can be obtained by xoring a operations of op_selec.
*/
implem_lin test_xor_lin(poly x/*!<Linear operation(poly) we want to implement*/, 
 set<poly> * op_selec /*!< Set of selected linear operations already used in previous step of the implementation*/, 
 uint8_t a/*!< Maximum XOR gates we want to add*/);

/*!
* Return the implem_lin to implement using the fewest XOR.
*/
implem_lin Test_xor_lin (poly x/*!<Linear operation(poly) we want to implement*/, 
set<poly> * op_selec/*!< Set of selected linear operations already used in previous step of the implementation*/);

/*!
* Return a possible implementation of the linear part using at maximum nb_xor_max XOR gates. 
*/
implem return_implem_lin (set<poly> * set_op/*!< Set containing the linear monomials(poly) such as x0*/,
 set<poly> * set_op2/*!< Set containing the XOR of 2 linear monomials(poly) such as x0 ^ x1*/,
 vector<poly> imp/*!<Vector containing all the linear expressions(poly) required in the implementation */, 
 int nb_xor_max/*!< Maximum XOR gates wanted in the final implementation*/, 
 uint64_t time_max/*!<Bound on the running time in minutes*/);

#endif