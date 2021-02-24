//
//  Seekg.cpp
//  CommenFunction
//
//  Created by Rui Zhou on 2021-02-23.
//

//  Example of using seekg in File System

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    int id;
    string name;
    float grade;

    ifstream inFile;
    inFile.open("grades.txt", ios::in); // opens file grades.txt

    // checks if file is opened properly
    if (!inFile) {
      cerr << "File could not be opened" << endl;
      exit(EXIT_FAILURE);
    }
  
    // Go through file
    cout << "Print file info:" << endl;
    inFile >> id >> name >> grade;  // reads information from a file
    while ( !inFile.eof() ) {
        cout << id << " " << name << " " << grade <<  endl;
        inFile >> id >> name >> grade;  // reads information from a file
    }
 
    inFile.clear();    // clears eof bit
    inFile.seekg(0, ios::beg); // moves pointer to beginning of file

    cout << "\nGo through the file another time:" << endl;
    // Go through the file again.
    inFile >> id >> name >> grade;  // reads information from a file

    while ( !inFile.eof() ) {
        cout << id << " " << name << " " << grade <<  endl;
        inFile >> id >> name >> grade;  // reads information from a file
    }

    inFile.close();

    return 0;
}
