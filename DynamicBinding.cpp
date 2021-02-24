//
//  DynamicBinding.cpp
//  CommenFunction
//
//  Created by Rui Zhou on 2021-02-23.
//  Example of  the use of dynamic binding

#include<iostream>
using namespace std;

class Shape {
 protected:
       int x;  // x part of coordinate pair
       int y;  // y part of coordinate pair
       
  public:
       Shape (int = 0, int = 0 );      // default constructor
       void setX(int);                 // set x in coordinate pair
       int getX() const;               // return x from coordinate pair
       void setY( int );               // set y in coordinate pair
       int getY() const;               // return y from coordinate pair
       virtual void print() const;     // output Shape object
};

// constructor
Shape::Shape(int xValue, int yValue) {
   x = xValue;
   y = yValue ;
}

// set x in coordinate pair
void Shape::setX(int xValue) {
   x = xValue;
}

// return x from coordinate pair
int Shape::getX() const {
   return x;
}

// set y in coordinate pair
void Shape::setY(int yValue) {
   y = yValue;
}

// return y from coordinate pair
int Shape::getY() const {
   return y;
}
 
// output Shape object
void Shape::print() const {
   cout << "Point::print() is called" << endl;
   cout << '[' << getX() << ", " << getY() << ']';
}

class Circle : public Shape {
  private:
   double radius;
   
  public:
    // Default constructor
    Circle( int = 0, int = 0, double = 0.0 );
    void setRadius( double );               // set radius
    double getRadius() const;               // return radius
    double getDiameter() const;             // return diameter
    double getCircumference() const;        // return circumference
    double getArea() const;                 // return area
    virtual void print() const;                     // output Circle object
};

// Constructor
Circle::Circle(int xValue, int yValue, double radiusValue) : Shape(xValue, yValue) {
  radius = radiusValue;
}

// set radius
void Circle::setRadius(double radiusValue) {
   radius = radiusValue;
}

// return radius
double Circle::getRadius() const {
   return radius;
}

// calculate and return diameter
double Circle::getDiameter() const {
   return 2 * getRadius();
}

// calculate and return circumference
double Circle::getCircumference() const {
   return 3.14159 * getDiameter();
}
// calculate and return area
double Circle::getArea() const {
   return 3.14159 * getRadius() * getRadius();
}

// output Circle object
void Circle::print() const {
   cout << "Circle::print() is called" << endl;
   cout << "Center = " << getX() << ", " << getY() << endl;
   cout << "Radius = " << getRadius();
}

int main() {
   Shape* shape = nullptr;
   Circle*  circle = nullptr;

   shape = new Shape(10.0, 20.5);
   shape->print();  // invokes Shape's print
   cout << endl;
   
   circle = new Circle(30.0, 10.5, 12.5);
   circle->print();  // invokes Circle's print
   cout << endl;
   
   shape = circle;
   shape->print();  // Print() of Circle that is called

   return 0;
}
