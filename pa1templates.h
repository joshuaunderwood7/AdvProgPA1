//#ifndef PA1_TEMPLATES
//#define PA1_TEMPLATES
#include "pa1functions.h"
#include <cmath>
#include <iostream>
#include <iomanip>

namespace underwood
{
    //e^x – 1.5 – tan^-1(x)
    template <typename T>
	T aNonLinearFunction(const T& input);

    //d/dx(f(x)) = e^x-1/(x^2+1)
    template <typename T>
    T DDXaNonLinearFunction(const T& input);

    //x^3 – sinh(x) + 4x^2 + 6x + 9
    template <typename T>
	T anotherNonLinearFunction(const T& input);

    //pre: pass three objects
    //post: have them displayed in console in "pretty" rows
    template <typename T>
    bool DISPLAY_ROW(const T& a, const T& b, const T& c);

    template <typename T>
    T Newton(const T& x0, 
                    const T& M, 
                    const T& sigma,
                    const T& eps);

    template <typename T>
    T Secant(const T& a,
                    const T& b,
                    const T& M,
                    const T& sigma,
                    const T& eps);
}
        #include "pa1templates.tem"




//#endif
