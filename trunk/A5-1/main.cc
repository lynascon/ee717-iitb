/*
 * =====================================================================================
 *
 *       Filename:  main.cc
 *
 *    Description:  This is main file for implementation of A5/1. This
 *    							implementation is not complete. Do not use it in
 *    							applications.
 *
 *        Version:  0.1
 *        Created:  Saturday 14 August 2010 06:07:20  IST
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


#include	<iostream>
#include	<cstdlib>
#include	<bitset>
#include	<getopt.h>
#include	"linear_feedback_shift_register.h"

int main(int argc, char** argv)
{
	
#ifdef  DEBUG
	std::cout<<"\nEntering the main function...\n";
#else      /* -----  not DEBUG  ----- */

#endif     /* -----  not DEBUG  ----- */
	if(argc < 1)
	{
		std::cout<<""
			<<"\nHowdy! Fellow Human." // You need to specify 3 keys values."
			<<"\nFor sake of your safety, you should give me your 64"
			<<"\nSECRET key. Ok! We are not cool enough to provide you a secret interface."
			<<"\nBut still !"
			<<"\nUse --key or -k followed by key_value (e.g. 101001010101...)."
			<<"\n";
	}

	int c;
	std::string strKey;
	//const char* strCKey;
	//unsigned long long int ulKey;
	std::string poly1;
	std::string poly2;
	std::string poly3;

	int do_help;
	bool ifInvalid = false;
	bool ifKey = false; // check if secret key is provided.
	while(1)
	{
		int option_index = 0;
		static struct option long_options[] = {
			{"key", 		required_argument,		NULL,			'k'},
			{"poly1", 		required_argument,		NULL,			'a'},
			{"poly2", 		required_argument,		NULL,			'b'},
			{"poly3", 		required_argument,		NULL,			'c'},
			{"help", 		no_argument,					&do_help,	 1},
			{0, 0, 0, 0}
		};

		c = getopt_long(argc, argv, "k:a:b:c:h", long_options, &option_index);
		if(c == -1)
			break;

		switch(c) 
		{
			case 'k':
				
#ifdef  DEBUG
				std::cout<<"\nFrom main() : -Option --key with value '"<<optarg<<"'\n";
#else      /* -----  not DEBUG  ----- */

#endif     /* -----  not DEBUG  ----- */
				strKey = optarg;
				//strCKey = strKey.c_str(); // convert into C type string.
				//ulKey = strtoul(strCKey, NULL, 16); // convert key into unsigned long.
				ifKey = true;
				break;
			
			case 'a':
				poly1 = optarg;
				break;

			case 'b':
				poly2 = optarg;
				break;

			case 'c':
				poly3 = optarg;
				break;

			case 'h':
				do_help =1;
				break;

			case 0:
				break;

			case ':':
				std::cerr<<"option "<<argv[1]<<" requires an argument.\n";
				ifInvalid = true;
				break;

			case '?':
				break;
			
			default:
				std::cerr<<"option "<<argv[1]<<" is invalid : ignored\n";
				ifInvalid = true;
				break;
		}

		/* we are asked to help this creature, so be it! */
		if(ifInvalid == true || 1 == do_help)
		{
			std::cout<<""
				<<"-------------------------------------------------------------------"
				<<"\nUSAGE : "
				<<"\n\t --key <key>"
				<<"\n\t\tValue of the secret key (64 bit). Sorry, you have to type it here."
#if 0
				<<"\n\t --poly1 poly1 e.g. 1 4 5 (in commas)"
				<<"\n\t\tValue of the first polynomial."
				<<"\n\t --poly2 poly2 e.g. 2 3 4 (in commas)"
				<<"\n\t\tValue of the second polynomial."
				<<"\n\t --poly3 poly3 e.g. 11 21 9 (in commas)"
				<<"\n\t\tValue of the third polynomial."
#endif
				<<"\n\t --help"
				<<"\n\t\tIf need help, you need to ask. Right?"
				<<"\n-----------------------------------------------------------------";
			return EXIT_FAILURE;
			
			/* Enough chatter! Let's fight. Said Alice to Jebberwalky . */

		}
		std::cout<<"i am here\n";
	}

	/* create three registers. */
	LFSR r1;
	LFSR r2;
	LFSR r3;

	/* set the polynomial. */
	std::cout<<"\n=========== Set the coefficient of polynomial of register 1 ===\n";
	r1.setPoly();
	std::cout<<"\n=========== Set the coefficient of polynomial of register 2 ===\n";
	r2.setPoly();
	std::cout<<"\n=========== Set the coefficient of polynomial of register 3 ===\n";
	r3.setPoly();

	/* set the clock bit. */
	int clockBitR1 = 0;
	int clockBitR2 = 0;
	int clockBitR3 = 0;
	while((clockBitR1 <= 0 || clockBitR1 >= 64) 
				|| (clockBitR2 <= 0 || clockBitR2 >= 64) 		  
				|| (clockBitR3 <= 0 || clockBitR3 >= 64))
	{
		std::cout <<"\n========== Setting the clock bit ====================================" 
		 					<<"\n= Non-zero positive less than 64. Else I'll keep asking. Roger that?\n";
		std::cout << "\nEnter the clock bit for first register :";
		std::cin >> clockBitR1;
		std::cout << "\nEnter the clock bit for second register :";
		std::cin >> clockBitR2;
		std::cout << "\nEnter the clock bit for third register :";
		std::cin >> clockBitR3;
	}

	/* initialize the registers. */
	r1.initializeRegister();
	r2.initializeRegister();
	r3.initializeRegister();
  
	/* set the clock bit. */
	r1.setClockBit(clockBitR1);
	r2.setClockBit(clockBitR2);
	r3.setClockBit(clockBitR3);

#ifdef  DEBUG
	r1.getClockBitPos();
	r2.getClockBitPos();
	r3.getClockBitPos();
#endif     /* -----  not DEBUG  ----- */

#ifdef  DEBUG
	std::cout<<"\nGiven values are :"<<clockBitR1<<'\t'<<clockBitR2<<'\t'<<clockBitR3;
#endif     /* -----  not DEBUG  ----- */

	/* if secret key is given. Do the mixing.*/
	if(ifKey == true)
	{
		std::bitset<SIZE_REGISTER> key(strKey);
		std::cout<<"\nThe secret key is :"<<key;
		/* set the secret key */
		r1.setSecretKey(key);
		r2.setSecretKey(key);
		r3.setSecretKey(key);

		/* Mix the secret key with the register. */
		r1.mixSecretKey();
		r2.mixSecretKey();
		r3.mixSecretKey();
	}
#if 1
	/* Checking, if clock is working fine. */
	//bool isThisClockHigh = r1.getClockBit();
	//std::cout<<"\nPloy 1 :"<<poly1<<'\t'<<poly1[0]<<'\t'<<poly1[1]
	//		<<'\t'<<poly1[2]<<'\t'<<poly1[3];
#endif
	
	return EXIT_SUCCESS;
}


