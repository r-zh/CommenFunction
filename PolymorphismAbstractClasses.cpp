//
//  PolymorphismAbstractClasses.cpp
//  CommenFunction
//
//  Created by Rui Zhou on 2021-02-23.
//  Class inheritance - polymorphism - abstract classes

#include<iostream>
#include<string>
using namespace std;

class Employee {
    protected:
        int id;
        string name;
    string address;
    string tel;
    string email;
    int vacation;

    public:
        /* Constructors */

        Employee();
        Employee(int, string);
        
        /* Getters and Setters */
        /* Note: The implementation of these functons is given here to */
        /* save space. It is better to provided the implementation outside */
        /* the class definition */

        int getID() const { return id; }
        string getName() const { return name; }
        void setName(string name1) { name = name1; }
        string getAddress() const { return address; }
        void setAddress(string address1) { address = address1; }
        string getEmail() const { return email; }
        void setEmail(string email1) { email = email1; }
        int getVacation() const { return vacation; }
        void setVacation(int vacation1) { vacation = vacation1; }

        /* Print function */
        virtual void print() const;

        /* Pure virtual function */
    virtual double getPay() const = 0; // This makes the class abstract - we can't create objects from it
};

Employee::Employee() {
        id = 0;
    name = "";
        address = "";
    tel =  "";
    email = "";
    vacation = 0;
}
        
Employee::Employee(int id1, string name1) {
        id = id1;
        name = name1;
}

void Employee::print() const {
        cout << "Employee: " << id << " " << name << endl;
}

// Derived Class: Class Manager
class Manager : public Employee {
    private:
        double salary;
        int numSupervisedEmp;
    
    public:
            /* Construcors */

            Manager();
            Manager(int, string, double, int);

            /* Getters and Setters */

            void setAssignment(float);
            void setSalary(double salary1) { salary = salary1; }
        double getSalary() const { return salary; }
            void setNumSupervisedEmp(int num) { numSupervisedEmp = num; }
        double getNumSupervisedEmp() const { return numSupervisedEmp; }

            /* Get pay and print functions */
            virtual double getPay() const;
            virtual void print() const;  // This function overrides the print() function of Employee
};

Manager::Manager() : Employee() {
    salary = 0;
    numSupervisedEmp = 0;
    vacation = 30;
}

Manager::Manager(int id1, string name1, double salary1, int num1) : Employee(id1, name1) {
    salary = salary1;
    numSupervisedEmp = num1;
    vacation = 30;
}

double Manager::getPay() const {
    return salary;
}

void Manager::print() const {
    Employee::print();  // calls the print of Employee
    cout << "Salary: " << salary <<  endl;
    cout << "Number of employees supervised: " << numSupervisedEmp <<  endl;
}

// Derived Class: Class SalesRep

class SalesRep : public Employee {
    private:
            int hoursWorked;
        float hourlyRate;
        float commission;
    
    public:
            /* Constructors */

        SalesRep();
            SalesRep(int, string, int, float, float);

        /*Getters and Setters */

            void setHoursWorked(int hw) { hoursWorked = hw; }
            int getHoursWorked() const { return hoursWorked; }
        void setHourlyRate(float hr) { hourlyRate = hr; }
            float getHourlyRate() const { return hourlyRate; }
        void setCommission(float comm) { commission = comm; }
        float getCommission() const { return commission; }

            /* Get pay and print functions */

            virtual double getPay() const;
            virtual void print() const;  // This function overrides the print() function of Employee
};

SalesRep::SalesRep() : Employee() {
    hoursWorked = 0;
    hourlyRate = 0.0;
    commission = 0.0;
    vacation = 20;
}

SalesRep::SalesRep(int id1, string name1, int hw, float hr, float comm) : Employee(id1, name1) {
    hoursWorked = hw;
    hourlyRate = hr;
    commission = comm;
    vacation = 20;
}

double SalesRep::getPay() const {
    return hoursWorked*hourlyRate + commission;
}

void SalesRep::print() const {
    Employee::print();  // calls the print of Employee
    cout << "Hours Worked: " << hoursWorked <<  endl;
    cout << "Hourly Rate: " << hourlyRate <<  endl;
    cout << "Commission: " << commission <<  endl;
    cout << "Salary: " << getPay() <<  endl;
}

// Derived Class: AdminStaff

class AdminStaff : public Employee {
    private:
            int hoursWorked;
        float hourlyRate;
    
    public:
        /* Constructors */

            AdminStaff();
            AdminStaff(int, string, int, float);

        /* Getters and Setters */

            void setHoursWorked(int hw) { hoursWorked = hw; }
            int getHoursWorked() const { return hoursWorked; }
        void setHourlyRate(float hr) { hourlyRate = hr; }
            float getHourlyRate() const { return hourlyRate; }

            /* Get pay and print functions */

            virtual double getPay() const;
            virtual void print() const;  // This function overrides the print() function of Employee
};

AdminStaff::AdminStaff() : Employee() {
    hoursWorked = 0;
    hourlyRate = 0.0;
    vacation = 20;
}

AdminStaff::AdminStaff(int id1, string name1, int hw, float hr) : Employee(id1, name1) {
    hoursWorked = hw;
    hourlyRate = hr;
   vacation = 20;
}

double AdminStaff::getPay() const {
    return hoursWorked*hourlyRate;
}

void AdminStaff::print() const {
    Employee::print();  // calls the print of Employee
    cout << "Hours Worked: " << hoursWorked <<  endl;
    cout << "Hourly Rate: " << hourlyRate <<  endl;
    cout << "Salary: " << getPay() <<  endl;
}

// Driver

int main() {
   Manager m1(1, "Foo", 60000, 5);
   m1.print();
   
   SalesRep s1(2, "Lee", 150, 15, 5000);
   s1.print();
   
   AdminStaff a1(3, "Jin", 250, 25);
   a1.print();
   
   Employee p(4, "Karl"); // This returns a compile error
}
