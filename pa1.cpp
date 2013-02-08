#include "pa1functions.h"
#include "pa1templates.h"

int main(void)
{
    //δ=10-6, ε=10-6, M=100, x0=1 for Newton’s method
    underwood::Newton<double>(1,100,std::pow(10,-6),std::pow(10,-6));

    //a=0, b=9, δ=10-6, ε=10-6, M=100 for the Secant method

    underwood::ENTER_TO_CONTINUE();
    return 0;
}
