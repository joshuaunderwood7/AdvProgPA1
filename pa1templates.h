﻿//#ifndef PA1_TEMPLATES
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

//------------cut this into the pa1template.tem----------------

    //f(x) = e^x – 1.5 – tan^-1(x)
    template <typename T>
    T underwood::aNonLinearFunction(const T& input)
    {
	    return (std::exp(input) - T(1.5) - std::atan(input));
    }

    //d/dx(f(x)) = e^x-1/(x^2+1)
    template <typename T>
    T underwood::DDXaNonLinearFunction(const T& input)
    {
	    return (std::exp(input-1) - (T(1)/(std::pow(input, T(2)) + T(1))));
    }


    //f(x) = x^3 – sinh(x) + 4x^2 + 6x + 9
    template <typename T>
    T underwood::anotherNonLinearFunction(const T& input)
    {
	    return (std::pow(input, T(3)) 
            - std::sinh(input) 
            + (T(4) * std::pow(input, T(2))) 
            + (T(6) * input)
            + T(9) );
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
    
    //Newton(x0, M, sigma, eps)
    // v ← f(x0)
    // output: 0, x0, v
    // if |v| < eps then stop
    ////create copy of x0 as cx0
    //// not as part of algo, but to maintain data input const
    // for k=1 to M
    //   x1 ← cx0 – v/df/dx(cx0)
    //   v ← f(x1)
    //   // output: k, x1, v
    //   if |x1 – x0| <sigma or |v| <eps then stop
    //   cx0 ← x1

    template <typename T>
    T underwood::Newton(const T& x0, 
                    const T& M, 
                    const T& sigma,
                    const T& eps)
    {
       T v = T(underwood::aNonLinearFunction<T>(x0));
       underwood::DISPLAY_ROW<T>(T(0), x0, v); //output: 0, x0, v
       
       if(std::abs(v) < sigma)
       { return v; }
       
       T cx0 = x0;
       int lineNumber = 0; //counter for line breaks
       
       for(T k = T(1); k <= M; ++k)
       {
           T x1 = cx0 - (v/T(underwood::DDXaNonLinearFunction<T>(cx0)));
           v = T(aNonLinearFunction(x1));
           underwood::DISPLAY_ROW<T>(k, x1, v); //output: k, x1, v
           if( ( (x1-cx0)>sigma ) || ( std::abs(v) < eps ) )
           { 
               underwood::FINISH_TABLE(); //finish drawing table
               return v;
           }
           cx0 = x1;
         
           //breakup the output into 20 line segments
           if( lineNumber > 20 )
           { 
               underwood::ENTER_TO_CONTINUE();
               lineNumber = 0; 
           }
         
       } 
       underwood::FINISH_TABLE();
       std::cout << "Reached M" << std::endl;
       return v;
    }

    //Secant(a, b, M, δ, ε)
    //fa ← f(a)
    //fb ← f(b)
    //// output: 0, a, fa
    //// output: 1, b, fb
    ////create copys of a,b as ca, cb
    //// not as part of algo, but to maintain data input const
    //for k=2 to M
    //  if |fa| > |fb|
    //    ca ↔ cb
    //    fa ↔ fb
    //  s ← (cb-ca)/(fb-fa)
    //  cb ← ca
    //  fb ← fa
    //  ca ← ca – fa*s
    //  fa ← f(ca)
    //  //output: k, ca, fa
    //  if |fa| < ε or |cb-ca| < δ then stop
    template <typename T>
    T underwood::Secant(const T& a,
                    const T& b,
                    const T& M,
                    const T& sigma,
                    const T& eps)
    {
        T ca = a; //"copy of a"
        T cb = a; //"copy of b"
        T fa = underwood::anotherNonLinearFunction(a);
        T fb = underwood::anotherNonLinearFunction(b);
        underwood::DISPLAY_ROW<T>(T(0), a, fa); //output: 0, a, fa
        underwood::DISPLAY_ROW<T>(T(1), b, fb); //output: 1, b, fb
        for(T k=T(2); k <= M; ++k)
        {
            if(std::abs(fa) > std::abs(fb))
            {
                std::swap<T>(ca, cb);
                std::swap<T>(fa, fb);
            }
            T s  = ( (cb-ca)/(fb-fa) );
            cb = ca;
            fb = fa;
            ca = ( ca - (fa*s) );
            fa = underwood::anotherNonLinearFunction(ca);
            underwood::DISPLAY_ROW<T>(k, ca, fa); //output: k, ca, fa
            if( (std::abs(fa) < eps) || (std::abs(cb-ca) < sigma) )
            {
                underwood::FINISH_TABLE(); //finish drawing table
                return fa;
            }
        }
        underwood::FINISH_TABLE();
        std::cout << "Reached M" << std::endl;
        return fa;
    }




//#endif
