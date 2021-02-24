//
//  inheritance.cpp
//  CommenFunction
//
//  Created by Rui Zhou on 2021-02-23.
//  Class inheritance

#include<iostream>
#include<string>
using namespace std;

class Student {
    private:
        int id;
        string name;

    public:
        Student() {
            cout << "Student() is called." << endl;
            id = 0;
            name = "";
        }
        
        Student(int id1, string n) {
            cout << "Student(int, string) is called." << endl;
            id = id1;
            name = n;
        }
        
        int getID() const { return id; }
        string getName() const { return name; }
        void setName(string n) { name = n; }
        void print() const {
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
};

UndergradStudent::UndergradStudent() : Student() {
    cout << "UndergradStudent() is called." << endl;
    assignment = 0;
    midterm = 0;
    final = 0;
}


UndergradStudent::UndergradStudent (int id1, string n, float a, float m, float f): Student(id1, n) {
    cout << "UndergradStudent(int, string, float, float, float) is called." << endl;
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

int main() {
    UndergradStudent s1(1, "Ric", 100, 85, 90);
    
    cout << "Student: ";
    s1.print();
    cout << "Assignment: " << s1.getAssignment() <<  endl;
    cout << "Midterm   : " << s1.getMidterm() <<  endl;
    cout << "Final     : " << s1.getFinal() <<  endl;
}
