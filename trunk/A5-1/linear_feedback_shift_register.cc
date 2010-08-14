/*
 * =====================================================================================
 *
 *       Filename:  linear_feedback_shift_register.cc
 *
 *    Description:  Implementation of Linear Feedback Shift Register in C++.
 *    							Clock bit and polynomial which represents which are the bits
 *    							to be xor-ed should be modifiable. These private variables
 *    							can be modified by using public methods given in this
 *    							implementation.
 *
 *        Version:  1.0
 *        Created:  Saturday 14 August 2010 01:17:05  IST
 *       Revision:  none
 *       Compiler:  g++/gcc 
 *
 *         Author:  Dilawar (nuts), dilawar[AT]ee[dot]iitb[dot]ac[dot]in
 *      Institute:  Indian Institute of Technology, Bombay
 *
 * This material is released under GNU Lesser Public License.	
 * You are free to copy, distribute or use it for any non-commercial activity.
 * But you are not allowed to modify it. If you are a student, you can use its
 * part in your work with or without mentioning it.
 * 
 * For additional details, please see the GNU Lesser Public license.
 *
 * NOTE : No propriety software is used in this material.
 * Almost all of the code is written and modified in VIM editor with c-support 
 * plugin which is more awesome than Kung Fu Panda. Just kidding, no one is more
 * awesome than Kung Fu Panda with or without a light saber.
 * 
 * This program is made using a bit for here,  a bit from there under the influence
 *  of a lot of burnt out neurons.
 * Report bugs : dilawar.in@gmail.com
 * =====================================================================================
 */


#include	"linear_feedback_shift_register.h"
#include	<iostream>
#include	<bitset>
#include	<cstdlib>

/* Constructor and destructor. */

LFSR::LFSR()
{
	
#ifdef  DEBUG
	std::cout<<"\nLFSR::Entering the Constructor... \n";
#else      /* -----  not DEBUG  ----- */

#endif     /* -----  not DEBUG  ----- */
}

LFSR::~LFSR()
{

#ifdef  DEBUG
	std::cout<<"\nEntering the destructor ... \n";
#else      /* -----  not DEBUG  ----- */

#endif     /* -----  not DEBUG  ----- */
}
