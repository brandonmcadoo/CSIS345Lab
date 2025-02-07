#include <iostream>
#include "print.h"

using std::cout;
using std::endl;

int main(){
    int* array = new int[10];
    int b = 1;
    int c = 2;
    int d = 3;
    int e = 4;

    int i = 0;
    while(i < 10){
        array[i] = -1;
        i++;
    }
    i = 0;
    // while(1){
    //     cout << index << " : " << array[index] << endl;
    //     index++;
    // }
    int* index = &b;
    printout(index);

    delete[] array;
}


