//
//  ArrayPractice.cpp
//  CommenFunction
//
//  Created by Rui Zhou on 2021-02-10.
//

#include <iostream>
#include <array>
using namespace std;

void func_declare_cin(){
    string romen;
    
    // First step: bitor
    cout <<"input"<< "\n";
    cin >> romen;
    cout << "the input is " << romen <<endl;

}
void func_declare_array(){
    
    //Second step: defind
    string romen="XII";
    array<char, 3> arab;
    
    for (size_t i=0; i < arab.size();i++)
        arab[i]=romen[i];
        
    for (size_t i=0; i < arab.size();i++)
        cout<<arab[i]<<endl;
    
}
    
int func_abs_array(){
    
    //check the value of each
    array<char, 3> arab = {'X','I','I'};
    int result = 0;
    if (arab[0]=='X')
        result += 10;
    else if (arab[0]=='V')
        result += 5;
    else if (arab[0]=='I')
        result += 1;
    cout << result<<endl;
    
    return 0;
}

//build [0][0]
int array_init()
{
    std::array<std::array<int, 6>, 10> table;
    for(int i = 0; i < 10; i ++){
        for( int j=0; j < 6; j ++){
            table[i][j]=0;
        }
    }
        for(int i = 0; i < 10; i ++){
        for( int j=0; j < 6; j ++){
            std::cout<<table[i][j]<<" ";
        }
        std::cout<<std::endl;
    }

    return 0;
}

// calcute 5+2*3-4
int array_calculator()
{
    array<int, 4> arab = {5,2,3,4};
    array<char, 3> op = {'+','*','-'};
    
    array<int, 3> arab_1;
    array<char, 2> op_1;
    
    for (size_t i=0; i < op.size();i++)
        if (op[i]=='*'){
            arab[i+1]*=arab[i];
            arab[i]= 0;
        }

    for (size_t i=0,j=0; i < arab.size();i++)
        if (arab[i]!=0){
            arab_1[j]=arab[i];
            if(j<op_1.size())
                op_1[j]=op[i];
            j++;
        }
    
    for (size_t i=0; i < arab_1.size();i++)
        cout<<arab_1[i]<<" ";
    cout <<'\n';

    for (size_t i=0; i < op_1.size();i++)
        cout<<op_1[i]<<" ";
    cout << endl;
    
    return 0;
}
