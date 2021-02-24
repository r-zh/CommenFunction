//
//  ArrayOfObject.cpp
//  CommenFunction
//
//  Created by Rui Zhou on 2021-02-23.
//  Class composition practice. Class Course contains array of objects of class Student, created statically.

#include <iostream>
#include <string>
using namespace std;

class Student {
    private:
        int id;          // Student id
        string name;    // Student name
    // other data members can be added here

    public:
        Student();                     // Default constructor
        Student(int, string);            // Regular constructor
       
    int getID() const;             // Returns student id
    string getName() const;         // Returns student name
    void setName(string);         // Changes student name
    void print() const;         // Prints student info
};

// Default constructor
Student::Student() {
    id = 0;
    name = "";
}

// Regular constructor
Student::Student(int id1, string name1) {
    id = id1;
    name = name1;
}

// Returns student id
int Student::getID() const {
    return id;
}

// Returns student name
string Student::getName() const  {
     return name;
}

// Changes student name
void Student::setName(string name1)  {
     name = name1;
}

// Prints student info
void Student::print() const {
     cout << "Student: " << name << " " << id <<  endl;
}
 
// Class Course

class Course {
    private:
        string code;          // Course code
        string name;         // Course name
    Student* students;     // Array of students
    int numStudents;     // Number of students

    public:
        Course();             // Default constructor
        Course(string, string);     // Regular constructor
        Course(const Course&);    // Copy constructor
        ~Course();               // Destructor
        
        /* Getters and Setters */

        string getCode() const;
        string getName() const;
    void setName(string);

        /* Subsystem that manages array of students */

        void addStudent(const Student&);        // Registers a student in the course
        void removeStudent(int);                // Removes a student
        void listAllStudents() const;            // Displays all registered students
        bool searchStudent(int) const;          // Searches if student is registered in the course
};


// Default constructor
Course::Course() {
     code = "";
     name = "";
     students = new Student[20];  // We assume a maximum of 20 students; This value could be declared as a constant
     numStudents = 0;
}

// Regular constructor
Course::Course(string code1, string name1) {
     code = code1;
     name = name1;
     students = new Student[20];
     numStudents = 0;
}

// Copy constructor
Course::Course(const Course& c) {
    code = c.code;
    name = c.name;
    students = new Student[20];
    numStudents = c.numStudents;
    for (int i = 0; i < numStudents; i++)
     students[i] = c.students[i];
}

// Destructor
Course::~Course() {
    delete[] students;
}

string Course::getCode() const {
    return code;
}

string Course::getName() const {
    return name;
}
 
// Register a student in a course
void Course::addStudent(const Student& s) {
    if (numStudents < 20) {
        students[numStudents] = s;
        numStudents++;
    }
    else {
        cout << "Student: " << s.getID() << " cannot be added � number of students exceeded " << endl;
    }
    return;
}

// Removes a student from a course
void Course::removeStudent(int studID) {
    // We need to search for studID first
    for (int i = 0; i < numStudents; i++)    {
       if (students[i].getID() == studID)  {
        // We need to shift the  elements of the array
                for (int j = i; j < numStudents-1; j++) {
                    students[j] = students[j+1]; //shifts the elements of the array
                }
                numStudents--;
        return;
       }
    }
    cout << "Student " << studID << " cannot be found!" << endl;
}

// Displays all students of a course
void Course::listAllStudents()  const {
   for (int i = 0; i < numStudents; i++)
         students[i].print();
}

// Searches if a student is registered
bool Course::searchStudent(int studID) const {
       for (int i = 0; i < numStudents; i++) {
           if (students[i].getID() == studID)
                return true;
       }
       return false;
}


int main() {

    // Sample students
    Student s1(1, "Ric");
    Student s2(2, "Karen");
    Student s3(3, "Lee");

    // A course object
    Course c("COEN244", "Programming in C++");

    // Register students in the course c
    c.addStudent(s1);
    c.addStudent(s2);
    c.addStudent(s3);

    // List students
    c.listAllStudents();
    
    if (c.searchStudent(1))
        cout << "Student with id = 1 " << " is registered in " << c.getCode() << " " << c.getName() <<  endl;
    else
        cout << "Student with id = 1 " << " is not registered in " << c.getCode() << " " << c.getName() <<  endl;
   
    cout << endl;
    
    // Student 1 drops the course
    c.removeStudent(1);
    cout << endl;
    
    // List students
    c.listAllStudents();

    return 0;
}
