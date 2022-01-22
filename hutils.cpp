#include "hutils.h"
#include <iostream>

bool** create2darrB(int rows, int cols);
int fact(int n);

bool** create2darrB(int rows, int cols){
    bool **arr = (bool **)malloc(sizeof(bool *) * rows);
    for(int i = 0; i < rows; i++){
        arr[i] = (bool *)malloc(sizeof(bool) * cols);
    }
    return arr;
}

int fact(int n){
    if (n<=1)
        return 1;
    else
        return n*fact(n-1);
}