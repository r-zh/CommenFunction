//
//  overriding.cpp
//  CommenFunction
//
//  Created by Rui Zhou on 2021-02-23.
//  Function overriding

#include<iostream>
#include<string>
using namespace std;

class Student {
    private:
        int id;
        string name;

    public:
        Student() {
            id = 0;
            name = "";
        }
        
        Student(int id1, string n) {
            id = id1;
            name = n;
        }
        
        int getID() const { return id; }
        string getName() const { return name; }
        void setName(string n) { name = n; }
        void print() const {
            cout << "Student::print() is called." << endl;
            cout << id << " " << name << endl;
            
        }
};

// Derived class
class UndergradStudent : public Student {
    private:
        float assignment;
        float midterm;
        float final;
        
    public:
        UndergradStudent();
        UndergradStudent(int, string, float, float, float);
        void setAssignment(float);
        float getAssignment() const;
        void setMidterm(float);
        float getMidterm() const;
        void setFinal(float);
        float getFinal() const;
        void print() const; // THis function overrides the print() function of Student
};

UndergradStudent::UndergradStudent() : Student() {
    assignment = 0;
    midterm = 0;
    final = 0;
}


UndergradStudent::UndergradStudent (int id1, string n, float a, float m, float f): Student(id1, n) {
    assignment = a;
    midterm = m;
    final = f;
}

void UndergradStudent::setAssignment(float a) { assignment = a; }
float UndergradStudent::getAssignment() const { return assignment; }
void UndergradStudent::setMidterm(float m) { midterm = m; }
float UndergradStudent::getMidterm() const { return midterm;}
void UndergradStudent::setFinal(float f) { final = f; }
float UndergradStudent::getFinal() const { return final; }

void UndergradStudent::print() const {
    cout << "UndergradStudent::print() is called." << endl;
    Student::print();
    cout << "Grades: " << endl;
    cout << "Assignment: " << assignment <<  endl;
    cout << "Midterm   : " << midterm <<  endl;
    cout << "Final     : " << final <<  endl;
}

int main() {
    UndergradStudent s1(2, "John", 100, 90, 90);
    s1.print();
}
