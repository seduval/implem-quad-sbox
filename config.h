#ifndef CONFIG_H
#define CONFIG_H

/*!
 * \file config.h
 * \brief This file contains the set up of the global parameters.
 */

/*!
* \def  NB_PERM_MAX_8
* \def  NB_PERM_MAX_9
* \brief NB_PERM_MAX_8 and NB_PERM_MAX_9 represents the number of permutations of the output bits that will be tested for size 8 and 9.
*/
#define NB_PERM_MAX_8 100
#define NB_PERM_MAX_9 15

/*!
* \def TIME_LIN
* \brief TIME_LIN represents the time limit in seconds for the linear part.
*/
#define TIME_LIN 60

#endif