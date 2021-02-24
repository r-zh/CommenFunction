//
//  ClassPractice.cpp
//  CommenFunction
//
//  Init the class and describe the function how it works
//
//  Created by Rui Zhou on 2021-02-10.
//

#include <iostream>
#include <stdio.h>
#include <string.h>

using std::cout;
using std::endl;
     
class Account {
                                                                    
 public:
     Account();
     Account(double, char*);
     Account(const Account&);
     
     int getBalance() const;
     void setBalance(double);
     char* getOwner() const;
     void setOwner(char* ow);
     ~Account();

 private:
      double balance;
      char* owner;
};

Account::Account() {
    cout << "Constructor Account() is called" << endl;
    balance = 0.0;
    owner = nullptr;
}

Account::Account(double b, char* ow) {
    cout << "Constructor Account(double, char*) is called" << endl;
    balance = b;
    owner = new char[strlen(ow)+1];
    strcpy(owner, ow);
}

Account::Account(const Account& a) {
    cout << "Copy Constructor Account(const Account&) is called" << endl;
    balance = a.getBalance();
    owner = new char[strlen(a.getOwner())+1];
    strcpy(owner, a.getOwner());
}

int Account::getBalance() const {
    return balance;
}

void Account::setBalance(double b) {
    balance = b;
}

char* Account::getOwner() const{
    return owner;
}

void Account::setOwner(char* ow) {
    owner = new char[strlen(ow)+1];
    strcpy(owner, ow);
}

Account::~Account() {
    delete owner;
}

int class_practice() {
    
    cout <<"Example 1.............." << endl;
    Account* a1 = new Account();
    cout << a1->getBalance() << endl;
    cout << endl;

    cout <<"Example 2.............." << endl;
    Account *a2 = new Account(500, "John");
    cout << a2->getBalance() << endl;
    cout << a2->getOwner() << endl;
    cout << endl;
    
    cout <<"Example 3.............." << endl;
    Account* a3 = new Account(*a2);
    cout << a3->getBalance() << endl;
    cout << a3->getOwner() << endl;
    cout << endl;
    
    cout <<"Example 4.............." << endl;
    delete a2;
    cout << a3->getOwner() << endl;
    
    return 0;

}
/**
int main(){
    class_practice();
    
    return 0;
}
 */
