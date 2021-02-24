//
//  ExceptionHandl.cpp
//  CommenFunction
//
//  Created by Rui Zhou on 2021-02-23.

#include <iostream>
#include <exception>
using namespace std;

// DivideByZeroException objects should be thrown by functions
// upon detecting division-by-zero exceptions
class DivideByZeroException : public runtime_error {
    public:
          // constructor specifies default error message
          DivideByZeroException():runtime_error( "attempted to divide by zero" ) {}
};  // end class DivideByZeroException

// perform division and throw DivideByZeroException object if
// divide-by-zero exception occurs

// user-defined function quotient to manipulate the data
double quotient( int num, int den ) {
    if ( den == 0 )
        throw DivideByZeroException();    // terminate function
    return num / den;
}

int main() {
   int number1;    // user-specified numerator
   int number2;    // user-specified denominator
   double result;    // result of division
       
   cout << "Enter two integers: ";
   cin >> number1 >> number2;
   
    // try block contains code that might throw exception
    // and code that should not execute if an exception occurs
    try {
        result = quotient(number1, number2);
        cout << "The quotient is: " << result << endl;
    }
    catch ( DivideByZeroException& a) {
        cout << "Exception occurred: " <<
        a.what() << endl;
    }

    return 0;
}
