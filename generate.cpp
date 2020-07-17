#include<iostream>
#include"sudoku.h"

using namespace std;

int main() {
    // finish your generate code...
    int array[9][9]= {{3,0,2,0,0,5,6,9,0},
        {0,4,0,0,9,6,0,3,0},
        {0,5,0,0,0,8,0,0,0},
        {1,9,0,0,8,0,7,0,3},
        {0,0,0,0,0,0,0,0,0},
        {5,0,7,0,3,0,0,6,1},
        {0,0,0,8,0,0,0,2,0},
        {0,8,0,9,6,0,0,7,0},
        {0,6,5,7,0,0,3,0,9}
    };

    int i, j;
    for(i=0; i<9; ++i) {
        for(j=0; j<9; ++j) {
            cout <<array[i][j]<<" ";
        }
        cout<<'\n';
    }



    return 0;
}
