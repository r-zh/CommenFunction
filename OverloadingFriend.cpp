//
//  OverloadingFriend.cpp
//  CommenFunction
//
//  Created by Rui Zhou on 2021-02-23.
//  Operator overloading: Class Rational using friend functions

#include <iostream>
using namespace std;


class Rational {
    private:
        int n;  // numerator
        int d; // denominator
        
    public:
        // Constructor
        Rational (int n1=0, int d1=1) {
            if (d1 == 0) {
                   cout << "division by zero";
                       exit(1);
                }
                   n = n1;
            d = d1;
        }

        friend Rational operator+ (const Rational &x, const Rational &y);
        friend Rational operator- (const Rational &x, const Rational &y);
        friend Rational operator* (const Rational &x, const Rational &y);
        friend Rational operator/ (const Rational &x, const Rational &y);
        friend bool operator== (const Rational &x, const Rational &y);
        friend bool operator< (const Rational &x, const Rational &y);
        friend bool operator> (const Rational &x, const Rational &y);
        
        void setRational (int, int);
          void print() const;
             
} ;

void Rational::setRational(int n1, int d1) {
    if (d1 == 0) {
        cout << "division by zero";
               exit(1);
        }
           n = n1;
    d = d1;
}

void Rational::print() const {
    cout << " " << n << "/" << d;
}

Rational operator+ (const Rational &x, const Rational &y) {
    return Rational (y.n*x.d + x.n*y.d, y.d*x.d);
}

Rational operator- (const Rational &x, const Rational &y) {
    return Rational(x.n*y.d - y.n*x.d, x.d*y.d);
}

Rational operator* (const Rational &x, const Rational &y) {
    return Rational(x.n * y.n, x.d * y.d);
}

Rational operator/ (const Rational &x, const Rational &y) {
    return Rational(x.n * y.d, x.d * y.n);
}

bool operator== (const Rational &x, const Rational &y) {
    return (x.n * y.d == x.d * y.n);
}

bool operator< (const Rational &x, const Rational &y) {
    return (x.n * y.d < x.d * y.n);
}

bool operator> (const Rational &x, const Rational &y) {
    return (x.n * y.d > x.d * y.n);
}


int main() {
          Rational a(1, 4), b(3, 2), c;
          c = a + b;  //equivalent to operator=(c, operator+(a, b))
          a.print();
          cout << " + " ;
          b.print();
          cout << " = ";
          c.print();
          cout << endl;

    if (a < b) { //equivalent to operator<(a, b)
          a.print();
          cout << " < ";
              b.print();
          cout << endl;
    }

    return 0;
}
