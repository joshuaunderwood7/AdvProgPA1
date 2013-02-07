//#ifndef PA1_TEMPLATES
//#define PA1_TEMPLATES
#include "pa1functions.h"
#include <cmath>
#include <iostream>
#include <iomanip>

template <typename T>
const T& Newton(const T& x0, 
                const T& M, 
                const T& sigma,
                const T& eps);


#include "pa1templates.tem"
//cut this into the pa1template.tem

//Newton(x0, M, sigma, eps)
//v ← f(x0)
// output: 0, x0, v
// if |v| <eps then stop
// for k=1 to M
// x1 ← x0 – v/df/dx(x0)
// v ← f(x1)
// // output: k, x1, v
// if |x1 – x0| <sigma or |v| <eps then stop
// x0 ← x1

template <typename T>
const T& Newton(const T& x0, 
                const T& M, 
                const T& sigma,
                const T& eps)
{
   T v = T(underwood::aNonLinearFunction<T>(x0));
   underwood::DISPLAY_ROW<T>(T(0), x0, v); //output: 0, x0, v
   if(cmath::abs(v) < sigma)
   {
      for(T k = T(1); k <= M; ++k)
      {
          T x1 = x0 - (v/T(underwood::DDXaNonLinearFunction<T>(x0)));
          v = T(aNonLinearFunction(x1));
          underwood::DISPLAY_ROW<T>(k, x1, v); //output: k, x1, v
          if( ( (x1-x0)>sigma ) || ( std::abs(v) < esp ) )
          { 
              underwood::FINISH_TABLE(); //finish drawing table
              //to break from loop, set k to M
              k=M;
          }
          x0 = x1;
          
          //breakup the output into 20 line segments
          if( (k % 20) == 0 )
          { std::cout << "Press ENTER to continue.\n"; std::getchar(); }
          
      } 
   }
}

template <typename T>
bool underwood::DISPLAY_ROW(const T& a, const T& b, const T& c)
{
    std::cout << std::setfill('-') << std::setw(39) << "-" << std::endl;
    std::cout << std::setfill(' ') << std::fixed;
    std::cout << "|"  << std::setw(10) << std::setprecision(0) << a;
    std::cout << " | " << std::setw(10) << std::setprecision(8) << b;
    std::cout << " | " << std::setw(10) << std::setprecision(8) << c;
    std::cout << " | " << std::endl;
    
    return true;
}

//#endif