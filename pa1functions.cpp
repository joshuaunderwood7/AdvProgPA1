#include "pa1functions.h"




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