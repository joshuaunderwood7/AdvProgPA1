AdvProgPA1
==========

Advanced Programming Assignment 1

Program objectives
The objectives of this assignment are as follows.
An ability to use current techniques, skills, and tools necessary for computing practice (ABET
i).

Value
This program is worth 15 points. The distribution of points will be as follows.
Criterion Value
Templates 2
Inclusion model 1
Program style (see below) 3
Annotated output 8
Usage of pseudocode 1

Problem
You are to use the secant method and Newton’s method to find the root(s) of non-linear
equations. That is, you are to find a value for which f(x) = 0 where f is a real-valued function.

Input
A non-linear function, e^x – 1.5 – tan^-1(x), δ=10^-6, ε=10^-6, M=100, x0=1 for Newton’s method and
x^3 – sinh(x) + 4x^2 + 6x + 9, a=0, b=9, δ=10-6, ε=10-6, M=100 for the Secant method.

Output
A table of values for each algorithm corresponding to iterations k, x, and f(x) or k, a and fa as
computed by the algorithms.
Program requirements
1. Display a greeting explaining the nature of the program.
2. Separate your function templates from your non-templates. You must have at least two
templates, one for each method.
3. The compilation of the function templates should follow the inclusion model.
4. The output should be formatted as per the example below.
5. Specify a precision of 8 places for computed values.
CSCI 3320 Program Assignment 1 Spring 2013
-2-
Here is an example of the expected output for the Newton method
k x (a for Secant) f(x) (fa for Secant)
0 0.00044038 1.23004343
1 0.23011031 1.01103292

Newton(x0, M, sigma, eps)
v ← f(x0)
 //output: 0, x0, v
 if |v| <eps then stop
 for k=1 to M
   x1 ← x0 – v/df/dx(x0)
   v ← f(x1)
   // output: k, x1, v
   if |x1 – x0| <sigma or |v| <eps then stop
   x0 ← x1

Secant(a, b, M, δ, ε)
fa ← f(a)
fb ← f(b)
// output: 0, a, fa
// output: 1, b, fb
for k=2 to M
  if |fa| > |fb|
    ca ↔ cb
    fa ↔ fb
  s ← (cb-ca)/(fb-fa)
  cb ← ca
  fb ← fa
  ca ← ca – fa*s
  fa ← f(ca)
  //output: k, ca, fa
  if |fa| < ε or |cb-ca| < δ then stop

Notes
1. You may use the cmath library.
2. Do not use classes in the assigment.
3. Be sure to use program style (pre/post, header comments, sparse code comments, selfdocumenting
names, whitespace, indentation, etc.). Also, make sure the output is formatted
and labeled correctly. Keep the ‘main’ function as short as possible. Try to limit ‘main’ to
calls to top-level functions.
4. A grading rubric will be completed and emailed back to you at the address from which you
submitted the assignment. This should be done no later than one week after the due date.
