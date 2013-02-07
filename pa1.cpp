#include "pa1functions.h"
#include "pa1templates.h"

int main(void)
{
    double a,b,c;
    a = 1.1;
    b = 2.31213213452345;
    c = 3.342134123541234;

    underwood::DISPLAY_ROW<double>(a,b,c);
    underwood::DISPLAY_ROW<double>(a,b,c);
    underwood::FINISH_TABLE();

    std::cout << "Press ENTER to continue.\n"; std::getchar();
    return 0;
}