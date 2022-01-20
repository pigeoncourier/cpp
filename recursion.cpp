#include <iostream>
using namespace std;

    // std::cout << Print(2) << std::endl;
    // towers(3, 'I', 'E', 'T');

int fact(int n){
    if (n<=1)
        return 1;
    else
        return n*fact(n-1);
}

int Print(int n){
    if(n==0)
        return 0;
    else{
        printf("%d",n);
        return Print(n-1);
    }
}

void towers(int n, char frompeg, char topeg, char auxpeg){
    /*if only one disk, make move and return*/
    if (n==1){
        printf("Move disk from peg %c to peg %c", frompeg, topeg);
        return;
    }
    /*Move top n-1 disks from A to B, using C as auxiliary*/
    towers(n-1, frompeg, auxpeg, topeg);
    /*Move remaining disks from A to C*/
    printf("\nMove disk %d from peg %c to peg %c", n, frompeg, topeg);
    /*Move n-1 disks from B to C using A as auxiliary*/
    towers(n-1, auxpeg, topeg, frompeg);
}

//declare before elaborating
int sortedcheck(int A[], int n);

void binary(int n);
const int alen = 4;
int A[alen];

int main(){
    int b[5] = {1,5,3,4,5};
    binary(alen);
}

int sortedcheck(int A[], int n){
    printf("n= %d, n-1= %d, n-2= %d\n",n,A[n-1],A[n-2]);
    printf("A[n-1] < A[n-2] result: %d\n",A[n-1] < A[n-2]);
    if (n==1){
        printf("Nice");
        return 1;
    }
    return (A[n-1] < A[n-2])?0:sortedcheck(A, n-1);
}

void binary(int n){
    if (n<1){
        for (int i = 0; i < alen; i++){
            if (i==0)
                printf("\n");
            printf("%d",A[i]);
        }
    }
    else{
        A[n-1] = 0;
        binary(n - 1);
        A[n-1] = 1;
        binary(n-1);
    }
}