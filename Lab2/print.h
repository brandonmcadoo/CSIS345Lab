#ifndef PRINT_H
#define PRINT_H

#include <iostream>
using namespace std;

void printout(int* index){
    while(true){
        cout << index << " : " << *(index++) << endl;
    }
}

#endif