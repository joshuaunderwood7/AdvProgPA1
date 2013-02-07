#include "pa1functions.h"


//f(x) = e^x – 1.5 – tan^-1(x)
template <typename T>
const T& underwood::aNonLinearFunction(const T& input)
{
	return (std::exp(input) - T(1.5) - std::atan(input));
}

//d/dx(f(x)) = e^x-1/(x^2+1)
template <typename T>
const T& underwood::DDXaNonLinearFunction(const T& input)
{
	return (std::exp(input-1) - (T(1)/(std::pow(input, T(2)) + T(1))));
}


//f(x) = x^3 – sinh(x) + 4x^2 + 6x + 9
template <typename T>
const T& underwood::anotherNonLinearFunction(const T& input)
{
	return (std::pow(input, T(3)) 
        - std::sinh(input) 
        + (T(4) * std::pow(input, T(2))) 
        + (T(6) * input)
        + T(9) );
}

//d/dx(f(x)) = 3 x^2 + 8 x - cosh(x) + 6
template <typename T>
const T& underwood::DDXanotherNonLinearFunction(const T& input)
{
	return ((T(3) * std::pow(input, T(2))) 
        + T(8) * input
        - std::cosh(input)
        + T(6) );
}

/* moved to pa1templates
template <typename T>
bool underwood::DISPLAY_ROW(const T& a, const T& b, const T& c) {...}
*/

bool underwood::FINISH_TABLE(void)
{
    std::cout << std::setfill('-') << std::setw(39) << "-" << std::endl;
    return true;
}