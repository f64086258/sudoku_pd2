#ifndef SUDOKU_H
#define SUDOKU_H

/***************************************************
 * Finish your .cpp according to this header file. *
 * You can modify this file if needed.             *
 ***************************************************/

#include<iostream>
using namespace std;


class sudoku {

  public:
    sudoku();
    void set();
    void print();


    // generate
    static sudoku generate();

    // transform
    void swapNum(int x,int y);
    void swapRow(int x,int y);
    void swapCol(int x,int y);
    void rotate(int x);
    void flip(int x);

    // solve
    int solve();
    void fillinNum(int row, int col, int value);
    int returnNum(int row, int col);
    sudoku operator=(sudoku other);
    bool returnY(int row, int col, int Num);
    void fillinFalse(int row, int col, int k);
    void fillinTrue(int row, int col, int k);
    void fillinColFalse(int col, int k);
    void fillinColTrue(int col, int k);
    void fillinRowFalse(int row, int k);
    void fillinRowTrue(int row, int k);
    void fillinSquareFalse(int row, int col, int num);
    void fillinSquareTrue(int row, int col, int num);
    void reset(int row, int col);


  private:
    int sudo[9][9];
    bool Y[9][9][10];


};

#endif //SUDOKU_H
