//
//  LibrarySystem.cpp
//  CommenFunction
//
//  Created by Rui Zhou on 2021-02-23.
//  Library management system practice

#include<iostream>
using namespace std;

// Class Book
class Book {
    private:
        int bookNum;        // book number
        string title;       // book title
        bool available;        // flag indicating availability of the book

    public:
        Book();                            // default constructor
        Book(int, string);              // regular constructor
        int getBookNumber() const;        // returns book number
        string getBookTitle() const;    // returns book title
        bool isAvailable() const;       // returns book availability
        void setAvailability(bool);     // sets book availability
        void print() const;             // prints book info
};

Book::Book() {
    bookNum = 0;
    title = "";
    available =  true;
}

Book::Book(int n, string t) {
    bookNum = n;
    title = t;
    available =  true;
}

int Book::getBookNumber() const {
  return bookNum;
}

string Book::getBookTitle() const {
  return title;
}

bool Book::isAvailable() const {
  return available;
}

void Book::setAvailability(bool a) {
  available = a;
}

void Book::print() const {
  cout << bookNum << " " << title << " " << available;
}

class Person {
     protected:
        int id;               // id of a person
        string name;       // name of a person
        Book* books;       // list of books
        int numBooks;      // number of books borrowed by a person
        int limit;         // limit  number of books a person can borrow
        int duration;      // borrowing duration in weeks

    public:
        Person (int, int);                    // default constructor
        Person(int, string, int, int);        // regular constructor
        Person(const Person&);                 // copy constructor
        virtual ~Person();                  // destructor

       int getID() const;               // returns id
       string getName() const;            // returns name
       void setLimit(int);                // sets the limit on the number of books
       int getLimit() const;            // returns the limit
       void setDuration(int);            // sets the maximum duration in weeks
       int getDuration() const;            // returns the duration

       // Subsystem dealing with books

       void borrowBook(Book&);               // adds a book
       void returnBook(Book&);              // removes a book
       void listAllBooks() const;            // lists all books borrowed by a person
       bool searchBook(int) const;          // searches if a person borrowed a book using id
       bool searchBook(string) const;       // searches if a person borrowed a book using title

       // pure virtual function
       virtual void print() const = 0;        // pure virtual function
};

Person::Person(int l = 20, int d = 6) {
        id = 0;
        name = "";
        limit = l;
        duration = d;
        books = new Book[limit];
        numBooks = 0;
}
    
Person::Person(int i, string n, int l, int d) {
        id = i;
        name = n;
        limit = l;
        duration = d;
        books = new Book[limit];
        numBooks = 0;
}

Person::Person(const Person& p) {
        id = p.id;
        name = p.name;
        limit = p.limit;
        duration = p.duration;
        numBooks = p.numBooks;
        books = new Book[limit];
        for(int i = 0; i < limit; i++)
            books[i] = p.books[i];
}

Person::~Person() {
    delete[] books;
}

int Person::getID() const {
    return id;
}

string Person::getName() const {
    return name;
}

void Person::setLimit(int l) {
    limit = l;
}

int Person::getLimit() const {
    return limit;
}

void Person::setDuration(int d) {
    duration = d;
}
    
int Person::getDuration() const {
    return duration;
}

void Person::borrowBook(Book& b) {
   if (b.isAvailable())  {
        if (numBooks < limit) {
                b.setAvailability(false); // the book becomes unavailable
                books[numBooks] = b;
                numBooks++;
     }
        else {
            cout << "Book limit exceeded." << endl;
         }
    }
    else {
        cout << "Book " << b.getBookNumber() << " is not available" << endl;
    }
}

void Person::returnBook(Book& b) {
    // We need to search for the book first
    for (int i = 0; i < numBooks; i++)    {
       if (books[i].getBookNumber() == b.getBookNumber())  {
        // we need to shift the elements of the array to maintain order
        // of books
        for (int j = i; j < numBooks-1; j++) {
                books[j] = books[j+1]; //shifts the elements of the array
        }
        b.setAvailability(true); // the book becomes available
        numBooks--;
        return;
       }
    }
    cout << "Book " << b.getBookNumber() << " cannot be found " << endl;
}

void Person::listAllBooks()  const {
   for (int i = 0; i < numBooks; i++)
         cout << "Book:  " << books[i].getBookNumber() << " " <<
                books[i].getBookTitle() << endl;
}

bool Person::searchBook(int bookNum) const {
       for (int i = 0; i < numBooks; i++) {
           if (books[i].getBookNumber() == bookNum)
              return true;
       }
       return false;
}

bool Person::searchBook(string bookTitle) const {
       for (int i = 0; i < numBooks; i++) {
           if (books[i].getBookTitle() == bookTitle)
              return true;
       }
       return false;
}

// Class Undergrad students
class UndergradStudent: public Person {
    /*
       No data members.
       The class inherits everything from Person.
   */

    public:
        UndergradStudent();                     // default constructor
        UndergradStudent(int, string);       // regular constructor
        virtual void print() const;               // overrides print of Person
};

UndergradStudent::UndergradStudent(): Person(10, 4) {
    // Nothing to do
}

UndergradStudent::UndergradStudent(int id1, string name1): Person(id1, name1,  10, 4)  {
    // Nothing to do
}

void UndergradStudent::print() const {
    cout << "Undergrad student: " << getName() << " borrowed the following books: " << endl;
    listAllBooks();
}

// Class Grad Students
class GradStudent: public Person {
   /*
        No data members.
       The class inherits everything from Person.
   */

    public:
        GradStudent();                     // default constructor
        GradStudent(int, string);        // regular constructor
        virtual void print() const;      // overrides print of Person
};

GradStudent::GradStudent(): Person(20, 6)  {
    // Nothing to do
}


GradStudent::GradStudent(int id1, string name1): Person(id1, name1,  20, 6)  {
    // Nothing to do
}

void GradStudent::print() const {
    cout << "Grad student:" << getName() << " borrowed the following books: " << endl;
    listAllBooks();
}

// Main functions
int main() {
    Book b1(100, "Practice C++");
    Book b2(200, "Practice Java");

    UndergradStudent s1(234543, "Jon S.");
    GradStudent s2(984838, "Karen L.");
   
    s1.borrowBook(b1);
    s1.borrowBook(b2);
    
    s1.listAllBooks();
    cout << endl;

    cout << s2.getName() << " wants to borrow book: " << b1.getBookNumber() << endl;
    s2.borrowBook(b1);    // can�t because Jon has already borrowed the book b1
    
    cout << endl;
    cout << s1.getName() << " returns book: " << b1.getBookNumber()  << endl;
    s1.returnBook(b1);    // Jon returns the book
    cout << endl;
    
    cout << s2.getName() << " wants to borrow book: " << b1.getBookTitle()  << endl;
    s2.borrowBook(b1);    // Karen can now have the book b1
    cout << endl;
    
    s1.print();           // Jon still has b2
    cout <<  endl;
    
    s2.print();     // Karen has b1
    
    return 0;
}
