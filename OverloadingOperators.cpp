//
//  OverloadingOperators.cpp
//  CommenFunction
//
//  Created by Rui Zhou on 2021-02-23.
//  Operator overloading: Overriding << and >> operators

#include <iostream>
#include <iomanip>
using namespace std;


class Date  {
   friend ostream& operator<<( ostream&, const Date& );
   friend istream& operator>>( istream&, Date& );

   public:
    Date() {}     // Constructor does nothing
    ~Date() {}    // Destructor does nothing
   
   private:
     int year;
     int month;
     int day;
};

// Overloading << stream operator to allow cout << someDate;
ostream& operator<<(ostream& output, const Date& d1 ) {
   output << d1.year << "-" << d1.month << "-" << d1.day;
   return output;  // enables cout << d1 << d2 << d3;
}

// Overloading >> stream operator to allow cin >> someDate;
istream& operator>>( istream& input, Date& d1) {
   input >> d1.year;
   input.ignore();               // skip dash (-)
   input >> d1.month;
   input.ignore();                  // skip dash (-)
   input >> d1.day;
   return input;      // enables cin >> d1 >> d2 >> d2;
}


int main() {

   Date d; // create object Date
   cout << "Enter a date in the form yyyy-mm-dd :\n";
 
   cin >> d; // cin >> date invokes operator>>( cin, d )
 
    cout << "The date entered was: ";
    cout << d << endl; // cout << date invokes operator<<( cout, phone )
   
    return 0;
}
