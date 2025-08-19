#ifndef GET_AND_PRINT_IMPLEM_H
#define GET_AND_PRINT_IMPLEM_H

#include "lin.h"

/*!
 * \file get_and_print_implem.h
 * \brief This file contains the functions to get the final implementation anf to print it.
 */

/*!
* Main function that takes in input the LUT of an s-box, compute a implementation using at maximum nb_and_max AND gates and print the implementation.
*/
void lut_to_implems (uint32_t lut[]/*!< Look-up-table of the wanted s-box*/,
 uint32_t size_in/*!<Size in input*/,
 uint32_t size_out/*!<Size in output*/, 
 int nb_sol/*!<Number of wanted solutions*/, 
 uint32_t nb_and_max/*!<Maximum AND gates wanted on the final implementation*/, 
 uint64_t time_max/*!<Bound on the running time in minutes*/, 
 uint8_t precomputed_files/*!<To precise if the precomputation is used or not*/);

#endif