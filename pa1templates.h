/* CSCI 3320 PA 1
 * By Joshua Underwood
 *
 * Here the definitions for the templates
 * this is to show themplates and inclusion
 * model.  
 *
*/

//#ifndef PA1_TEMPLATES
//#define PA1_TEMPLATES
#include "pa1functions.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>

namespace underwood
{
    //pre: template must be of type that cmath can compute
    //post: the equation e^x – 1.5 – tan^-1(x)
    //      is computed and returned
    template <typename T>
	T aNonLinearFunction(const T& input);

    //pre: template must be of type that cmath can compute
    //post: the equation d/dx(f(x)) = e^x-1/(x^2+1)
    //      is computed and returned
    template <typename T>
    T DDXaNonLinearFunction(const T& input);

    //pre: template must be of type that cmath can compute
    //post: the equation x^3 – sinh(x) + 4x^2 + 6x + 9
    //      is computed and returned
    template <typename T>
	T anotherNonLinearFunction(const T& input);

    //pre: pass three objects that std::cout can display to screen
    //post: have them displayed in console in "pretty" rows
    template <typename T>
    bool DISPLAY_ROW(const T& a, const T& b, const T& c);

    //pre: template must be of type that cmath can compute
    //     x0 is starting x value (user's guess)
    //     M is the number of iterations that Newton() will make 
    //      in it's attempt to find f(x) = 0
    //     sigma is minimum change in x
    //     eps is the tolerence for error
    //post: a table is displayed to the screen this table 
    //      shows each step and the values: loop count (k)
    //      x value, and f(x) value 
    template <typename T>
    T Newton(const T& x0, 
                    const T& M, 
                    const T& sigma,
                    const T& eps);

    //pre: template must be of type that cmath can compute
    //     a is the fist point
    //     b is the second point
    //     M is the number of iterations that Newton() will make 
    //      in it's attempt to find f(x) = 0
    //     sigma is minimum change in x
    //     eps is the tolerence for error
    //post: a table is displayed to the screen this table 
    //      shows each step and the values: loop count (k)
    //      x value, and f(x) value 
    template <typename T>
    T Secant(const T& a,
                    const T& b,
                    const T& M,
                    const T& sigma,
                    const T& eps);
}

#include "pa1templates.tem"




//#endif
