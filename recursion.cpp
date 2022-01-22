#include <iostream>
#include "hutils.cpp"

using namespace std;

    // std::cout << Print(2) << std::endl;
    // towers(3, 'I', 'E', 'T');
    // int b[5] = {1,5,3,4,5};
    // kstring(blen, 3);

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

void kstring(int n, int k);
const int blen = 3;
int B[blen];

int getval(int (*A)[5], int i, int j, int L, int H);
void findMaxBlock(int (*A)[5], int r, int c, int L, int H, int size, bool **cntarr, int &maxsize);
int getMaxOnes(int (*A)[5], int rmax, int cmax);

int main(){
    int zarr[][5] = {
        {1,1,0,0,0},
        {0,1,0,0,0},
        {0,0,1,0,0},
        {0,0,0,1,0},
        {0,0,0,0,0}};
    std::cout << "Biggest clump of 1s: " << getMaxOnes(zarr,5,5) << std::endl;
}

bool** create2darr(int rows, int cols){
    bool **arr = (bool **)malloc(sizeof(bool *) * rows);
    for(int i = 0; i < rows; i++){
        arr[i] = (bool *)malloc(sizeof(bool) * cols);
    }
    return arr;
}

int getval(int (*A)[5], int i, int j, int L, int H){
    if(i<0 || i>=L||j<0 || j>=H){
        return 0;
    }
    else{
        // printf("\nLocation: (%d,%d), Value: %d",i,j,A[i][j]);
        return A[i][j];
    }
}

void findMaxBlock(int (*A)[5], int r, int c, int L, int H, int size, bool** cntarr, int& maxsize){
    if(r>=L||c>=H){
        return; //return nothing if out of bounds
    }
    cntarr[r][c] = true; //mark current spot as counted
    size++;
    if(size > maxsize)
        // printf("\nLocation: (%d,%d), Cursize: %d",r,c,maxsize);
        maxsize = size;  //function received &maxsizeand can therefore reference maxsize from out of scope
    
    int direction[][2] = {{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1}};
    for (int i=0;i<8;i++){
        int newi = r+direction[i][0];
        int newj = c+direction[i][1];
        int val = getval(A, newi, newj, L, H);
        if (val>0 && (cntarr[newi][newj]==false)){
            findMaxBlock(A, newi, newj, L, H, size, cntarr, maxsize);
        }
    }
    cntarr[r][c] = false;
}

int getMaxOnes(int (*A)[5], int rmax, int cmax){
    
    int maxsize = 0;
    int size = 0;
    
    bool **cntarr = create2darrB(rmax, cmax);
    
    for(int i=0;i<rmax;i++){
        for(int j=0;j<cmax;j++){
            if(A[i][j] == 1){
                findMaxBlock(A,i,j,rmax,cmax,0,cntarr,maxsize);            
            }
        }
    }
    return maxsize;
}

void kstring(int n, int k){
    if (n<1){
        for (int i = 0; i < blen; i++){
            if (i==0)
                printf("\n");
            printf("%d",B[i]);
        }
    }
    else{
        for (int i = 0; i < k; i++){
            B[n - 1] = i;
            kstring(n - 1, k);
        }
    }
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