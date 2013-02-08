#include "pa1functions.h"
#include <cstdio>


/* moved to pa1templates
template <typename T>
bool underwood::DISPLAY_ROW(const T& a, const T& b, const T& c) {...}
*/

bool underwood::FINISH_TABLE(void)
{
    std::cout << std::setfill('-') << std::setw(54) << "-" << std::endl;
    return true;
}

bool underwood::ENTER_TO_CONTINUE(void)
{
    std::cout << "Press ENTER to continue.\n"; std::getchar();
    return true;   
}
