//
//  TemplateClass.cpp
//  CommenFunction
//
//  Created by Rui Zhou on 2021-02-23.
#include <iostream>
using namespace std;

template<class T>
class Stack {
  public:
     Stack();
     Stack(int);
     ~Stack();

     void push( const T& );     // push an element onto the stack
     bool pop(T& value);        // pop an element off the stack
     bool isEmpty() const;      // determine whether Stack is empty {
     bool isFull() const;

  private:
     int size;                   // number of elements in the stack
     int top;                    // location of the top element
     T *stackPtr;                // pointer to the stack
};

// default constructor
template<class T>
Stack< T >::Stack() {
   size = 10;  // we assume a default stack size is 10
   top = -1;  // stack initially empty
   stackPtr = new T[ size ]; // allocate memory for elements
}

// constructor
template<class T>
Stack< T >::Stack(int s) {
   size = s;
   top = -1;  // stack initially empty
   stackPtr = new T[ size ]; // allocate memory for elements
}

// destructor
template<class T>
Stack< T >::~Stack() {
    delete [] stackPtr;
}

// push element onto stack;
template<class T>
void Stack< T >::push( const T &value ) {
   if ( !isFull() )
      stackPtr[ ++top ] = value;
   else
      cout << "Stack is full" << endl;
}

// pop element off stack;
template<class T>
bool Stack< T >::pop( T& value ) {
    if ( !isEmpty() ) {
      value = stackPtr[ top-- ];  // pops top element from the stack
      return true;
    }
   
    cout << "Stack is empty.";
    return false;
}

// check if stack is empty
template<class T>
bool Stack< T >::isEmpty() const {
   return top == -1;
}

// check if stack is full
template<class T>
bool Stack< T >::isFull() const {
    return top == size - 1;
}

int main() {

   // Creates a stack of doubles, which is class-template specialization of the Stack template class
   Stack< double > doubleStack( 5 );
   doubleStack.push( 10.5 );
   doubleStack.push( 35.0 );
   doubleStack.push( 45.5 );

   // Pops elements from doubleStack
   cout << "Stack of type double contains:" << endl;
   double element;
   
   if (doubleStack.pop(element))
           cout << element << endl;
   if (doubleStack.pop(element))
           cout << element << endl;
   if (doubleStack.pop(element))
           cout << element << endl;

   // Creates a stack of integer, which is class-template specialization of the Stack template class
   Stack< int > intStack;
   intStack.push(10);
   
   intStack.push(5);
   intStack.push(15);

   cout << "\nStack of type int contains:" << endl;
   int value;
   if (intStack.pop(value) )
     cout << value << endl;

   if (intStack.pop(value) )
     cout << value <<endl;


   return 0;
}    
