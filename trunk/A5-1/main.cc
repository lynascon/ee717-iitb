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
	if(argc < 2)
	{
		std::cout<<""
			<<"\nHowdy! Fellow Human. For sake of your safety, you should give me your 64"
			<<"\nSECRET key. Ok! We are not cool enough to provide you a secret interface."
			<<"\nBut still !"
			<<"\nUse --key or -k followed by key_value (e.g. 213412)."
			<<"\n";
	}

	int c;
	std::string strKey;
	const char* strCKey;
	unsigned long long int ulKey;
	int do_help;
	bool ifInvalid = false;
	bool ifKey = false; // check if secret key is provided.
	while(1)
	{
		int option_index = 0;
		static struct option long_options[] = {
			{"key", 		required_argument,		NULL,			'k'},
			{"help", 		no_argument,					&do_help,	 1},
			{0, 0, 0, 0}
		};

		c = getopt_long(argc, argv, "k:h", long_options, &option_index);
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
				strCKey = strKey.c_str(); // convert into C type string.
				ulKey = strtoul(strCKey, NULL, 16); // convert key into unsigned long.
				ifKey = true;
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
				<<"\n\t --help"
				<<"\n\t\tIf need help, you need to ask. Right?"
				<<"\n-----------------------------------------------------------------";
			return EXIT_FAILURE;
			
			/* Enough chatter! Let's fight. Like Alice and Jebberwalky . */

		}
		std::cout<<"i am here\n";
	}
	LFSR r1;

	if(ifKey == true)
	{
		std::bitset<SIZE_REGISTER> key(ulKey);
		std::cout<<"\nThe secret key is :"<<key;
	}
	
	return EXIT_SUCCESS;
}


