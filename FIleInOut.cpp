//
//  FIleInOut.cpp
//  CommenFunction
//
//  Created by Rui Zhou on 2021-02-23.
//  Using ofstream object to create input/output file

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    int id;
    string name;
    float grade;

    fstream file("grades.txt", ios::in | ios::out); // opens file for input and output

    // checks if file is opened properly
    if (!file) {
      cerr << "File could not be opened" << endl;
      exit(EXIT_FAILURE);
    }
  
    cout << "Enter student information:" << endl;

    cout << "Student id (-1 to exit): ";
    cin >> id;
    
    while (id != -1) {
        cout << "Student name: ";
        cin >> name;
        cout << "Student grade: ";
        cin >> grade;
   
        file << id << " " << name << " " << grade << endl;  // Writes information to a file
        
        cout << "Student id (-1 to exit): ";
        cin >> id;
    }

    file.clear();
    file.seekg(0, ios::beg);

    cout << "\nThe file contains the following records:" << endl;

    while ( file >> id >> name >> grade ) {
    
        cout << id << " " << name << " " << grade <<  endl;
    
    }
    
    file.close();

    return 0;
}
