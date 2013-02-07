#ifndef PA1_FUNCTIONS
#define PA1_FUNCTIONS

namespace underwood
{
	//e^x – 1.5 – tan^-1(x)
    template <typename T>
	const T& aNonLinearFunction(const T& input);

    //d/dx(f(x)) = e^x-1/(x^2+1)
    template <typename T>
    const T& DDXaNonLinearFunction(const T& input);

    //x^3 – sinh(x) + 4x^2 + 6x + 9
    template <typename T>
	const T& anotherNonLinearFunction(const T& input);

    //d/dx(f(x)) = 3 x^2+8 x-cosh(x)+6
    template <typename T>
    const T& DDXanotherNonLinearFunction(const T& input);

    //pre: pass three objects
    //post: have them displayed in console in "pretty" rows
    template <typename T>
    bool DISPLAY_ROW(const T& a, const T& b, const T& c);

    bool FINISH_TABLE(void);
}

#endif
