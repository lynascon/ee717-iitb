/*
 * =====================================================================================
 *
 *       Filename:  linear_feedback_shift_register.h
 *
 *    Description:   Implementation of Linear Feedback Shift Register in C++.
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


#ifndef  linear_feedback_shift_register_INC
#define  linear_feedback_shift_register_INC

#include	<iostream>
#include	<cstdlib>
#include	<vector>
#include	<bitset>

#define SIZE_REGISTER		64     /* size of the registers. */



/*
 * =====================================================================================
 *        Class:  LFSR
 *  Description:  This class represent Linear Feedback Shift Registers. It's 
 *  INPUT bit is dependent on previous states. It is a LINEAR function of it
 *  previous states. Since XOR is the only possible linear operation on bits (
 *  Can you verify that!), it is used over some of its bits to generate the
 *  input.
 *
 *  NOTE : We'll use STL bitset here. 
 * =====================================================================================
 */

class LFSR
{
	public:

		/* ====================  LIFECYCLE     ======================================= */
		LFSR ();                             /* constructor      */
		LFSR ( const LFSR &other );   /* copy constructor */
		~LFSR ();                            /* destructor       */

		/* ====================  ACCESSORS     ======================================= */


		/* 
		 * ===  FUNCTION  ======================================================================
		 *         Name:  getClockBit
		 *  Description:  This will get the Clock bit.
		 * =====================================================================================
		 */
		std::bitset<1> getClockBit();


		/* ====================  MUTATORS      ======================================= */
		
		/* 
		 * ===  FUNCTION  ======================================================================
		 *         Name:  setClockBit
		 *  Description:  This will set the clock bit of this register.
		 * =====================================================================================
		 */
		bool setClockBit(size_t pos);
	 
		/* 
		 * ===  FUNCTION  ======================================================================
		 *         Name:  setSecretKey
		 *  Description:  This will set the public member secretKey which can be used as a
		 *  initial  state after mixing it with the content of the register. This is
		 *  optional but we are going to use is anyway in our implementation.
		 * =====================================================================================
		 */
		void setSecretKey(std::vector<bool> key);


		/* 
		 * ===  FUNCTION  ======================================================================
		 *         Name:  initializeRegister
		 *  Description:  This function will initialize a register for some clocks
		 *  cycles. Typically in this case, this register will be initialized for 64
		 *  times.
		 * =====================================================================================
		 */
		void initializeRegister(std::size_t num);

		
		/* 
		 * ===  FUNCTION  ======================================================================
		 *         Name:  mixSecretKey
		 *  Description:  This function will mix a 64 bit secret key with the
		 *  content of a register. This is optional for our application.
		 * =====================================================================================
		 */

		void mixSecretKey(void);

		/* ====================  OPERATORS     ======================================= */

		const LFSR& operator = ( const LFSR &other ); /* assignment operator */

		/* ====================  DATA MEMBERS  ======================================= */
	protected:

	private:

		std::size_t posClockBit; 											//! position of the clock bit.
		std::bitset<SIZE_REGISTER> Register; 					//! A register.
		std::vector<bool> secretKey;									/**! A secret key to mix with the content
																										 of the register.*/


}; /* -----  end of class LFSR  ----- */


#endif   /* ----- #ifndef linear_feedback_shift_register_INC  ----- */
