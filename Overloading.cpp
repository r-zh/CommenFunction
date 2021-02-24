//
//  Overloading.cpp
//  CommenFunction
//
//  Created by Rui Zhou on 2021-02-23.
// Operator overloading: Class Rational

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

            void setRational(int, int);
                void print() const;

                const Rational& operator= (const Rational&);
        Rational operator+ (const Rational&) const;
        Rational operator- (const Rational&) const;
        Rational operator* (const Rational&) const;
        Rational operator/ (const Rational&) const;
        bool operator== (const Rational&) const;
        bool operator< (const Rational&) const;
        bool operator> (const Rational&) const;
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

const Rational& Rational::operator= (const Rational &x) {
      n = x.n;
      d = x.d;
      return *this;
}
Rational Rational::operator+ (const Rational &x) const {
    return Rational (n*x.d + x.n*d, d*x.d);
}
Rational Rational::operator- (const Rational &x) const {
    return Rational(n*x.d - x.n*d, d*x.d);
}
Rational Rational::operator* (const Rational &x) const {
    return Rational(n*x.n, d*x.d);
}
Rational Rational::operator/ (const Rational &x) const {
    return Rational(n*x.d, d*x.n);
}

bool Rational::operator== (const Rational &x) const {
    return (n*x.d == d*x.n);
}

bool Rational::operator< (const Rational &x) const {
    return (n*x.d < d*x.n);
}

bool Rational::operator> (const Rational &x) const {
    return (n*x.d > d*x.n);
}



int main() {
          Rational a(1, 4), b(3, 2), c;
          c = a + b;  //equivalent to c.operator=(a.operator+(b))
          a.print();
          cout << " + " ;
          b.print();
          cout << " = ";
          c.print();
          cout << endl;

    if (a < b) { //equivalent to a.operator<(b)
          a.print();
          cout << " < ";
              b.print();
          cout << endl;
    }

    return 0;
} 
