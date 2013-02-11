/* CSCI 3320 PA 1
 * By Joshua Underwood
 *
 * these are the support functions for PA1
 * (the pa1template.h is where all the action is)
 *
 *
*/

#ifndef PA1_FUNCTIONS
#define PA1_FUNCTIONS
#include <cmath>
#include <iostream>
#include <iomanip>

namespace underwood
{
	// GREETING() 
    //pre: none
    //post: The user is shown a greeting that explains the program
    bool GREETING(void);

    //FINISH_TABLE()
    //pre: none
    //post a line of "-" are printed to the screen
    bool FINISH_TABLE(void);

    //ENTER_TO_CONTINUE
    //pre: none
    //post: The program is suspended
    //      The user is prompted to "Press Enter to continue"
    bool ENTER_TO_CONTINUE(void);

}

#endif
