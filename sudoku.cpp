#include"sudoku.h"

sudoku::sudoku() {
    for(int i=0; i<9 ; i++) {
        for(int j=0; j<9 ; j++) {
            sudo[i][j]=0;
            for(int k=0; k<10 ; k++) {
                Y[i][j][k]=true;
            }
        }
    }
}


void sudoku::set() {
    for(int i=0; i<9; i++) {
        cin >> sudo[i][0] >>sudo[i][1] >> sudo[i][2] >> sudo[i][3] >>sudo[i][4] >>sudo[i][5] >>sudo[i][6] >>sudo[i][7] >>sudo[i][8];
    }
}


void sudoku::print() {
    for(int i=0; i<9; i++) {
        cout << sudo[i][0] <<" " << sudo[i][1] << " " << sudo[i][2] << " " <<sudo[i][3] << " " <<sudo[i][4] << " " <<sudo[i][5] << " " << sudo[i][6] << " " << sudo[i][7] << " " << sudo[i][8] << endl;
    }
}

//**************************************************************


void sudoku::swapNum(int x,int y) {
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            if(sudo[i][j]==x) {
                sudo[i][j]=y;
            } else if(sudo[i][j]==y) {
                sudo[i][j]=x;
            }
        }
    }
}


void sudoku::swapRow(int x,int y) {
    x*=3;
    y*=3;
    for(int j=0; j<9; j++) {
        sudo[y][j]+=sudo[x][j];
        sudo[x][j]=sudo[y][j]-sudo[x][j];
        sudo[y][j]-=sudo[x][j];

        sudo[y+1][j]+=sudo[x+1][j];
        sudo[x+1][j]=sudo[y+1][j]-sudo[x+1][j];
        sudo[y+1][j]-=sudo[x+1][j];

        sudo[y+2][j]+=sudo[x+2][j];
        sudo[x+2][j]=sudo[y+2][j]-sudo[x+2][j];
        sudo[y+2][j]-=sudo[x+2][j];
    }
}

void sudoku::swapCol(int x,int y) {
    x*=3;
    y*=3;
    for(int i=0; i<9; i++) {
        sudo[i][y]+=sudo[i][x];
        sudo[i][x]=sudo[i][y]-sudo[i][x];
        sudo[i][y]-=sudo[i][x];

        sudo[i][y+1]+=sudo[i][x+1];
        sudo[i][x+1]=sudo[i][y+1]-sudo[i][x+1];
        sudo[i][y+1]-=sudo[i][x+1];

        sudo[i][y+2]+=sudo[i][x+2];
        sudo[i][x+2]=sudo[i][y+2]-sudo[i][x+2];
        sudo[i][y+2]-=sudo[i][x+2];
    }
}


void sudoku::rotate(int x) {
    int**trans = new int*[9];
    for(int i=0; i<9; i++) {
        trans[i]=new int[9];
    }

    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            trans[i][j]=sudo[i][j];
        }
    }

    switch(x) {
    case 0:
        break;

    case 1:
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                sudo[i][j]=trans[8-j][i];
            }
        }
        break;

    case 2:
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                sudo[i][j]=trans[8-i][8-j];
            }
        }

    case 3:
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                sudo[i][j]=trans[j][8-i];
            }
        }
        break;
    }

    for(int i=0; i<9; i++) {
        delete[]trans[i];
    }
    delete[]trans;
}


void sudoku::flip(int x) {
    switch(x) {
    case 0:
        for(int j=0; j<9; j++) {
            for(int i=0; i<4; i++) {
                sudo[i][j]+=sudo[8-i][j];
                sudo[8-i][j]=sudo[i][j]-sudo[8-i][j];
                sudo[i][j]=sudo[i][j]-sudo[8-i][j];
            }
        }
        break;

    case 1:
        for(int i=0; i<9; i++) {
            for(int j=0; j<4; j++) {
                sudo[i][j]+=sudo[i][8-j];
                sudo[i][8-j]=sudo[i][j]-sudo[i][8-j];
                sudo[i][j]=sudo[i][j]-sudo[i][8-j];
            }
        }
        break;
    }
}


//***********************************************************



void sudoku::fillinNum(int row, int col, int value) {
    sudo[row][col]=value;
}


int sudoku::returnNum(int row, int col) {
    return(sudo[row][col]);
}


sudoku sudoku::operator=(sudoku other) {
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            sudo[i][j]=other.returnNum(i,j);
        }
    }
    return(other);
}


bool sudoku::returnY(int row, int col, int Num) {
    return(Y[row][col][Num-1]);
}


void sudoku::fillinFalse(int row, int col, int k) {
    Y[row][col][k-1]=false;
}

void sudoku::fillinTrue(int row, int col, int k) {
    Y[row][col][k-1]=true;
}




void sudoku::fillinColFalse(int col,int k) {
    for(int i=0; i<9; i++) {
        Y[i][col][k-1]=false;
    }
}

void sudoku::fillinColTrue(int col, int k) {
    for(int i=0; i<9; i++) {
        Y[i][col][k-1]=true;
    }
}

void sudoku::fillinRowFalse(int row, int k) {
    for(int j=0; j<9; j++) {
        Y[row][j][k-1]=false;
    }
}

void sudoku::fillinRowTrue(int row, int k) {
    for(int j=0; j<9; j++) {
        Y[row][j][k-1]=true;
    }
}


void sudoku::fillinSquareFalse(int row, int col, int num) {
    int A= row/3, B= col/3;
    for(int i=A*3; i<(A+1)*3; i++) {
        for(int j=B*3; j<(B+1)*3; j++) {
            Y[i][j][num-1]=false;
        }
    }
}


void sudoku::fillinSquareTrue(int row, int col, int num) {
    int A= row/3, B=col/3;
    for(int i=A*3; i<(A+1)*3; i++) {
        for(int j=B*3; j<(B+1)*3; j++) {
            Y[i][j][num-1]=true;
        }
    }
}


void sudoku::reset(int row, int col) {
    int i,j;
    for(i=0; i<10; i++) {
        Y[row][col][i]=true;
    }

    for(i=0; i<9; i++) {
        if(sudo[i][col]!=0) {
            Y[row][col][sudo[i][col]-1]=false;
        }
    }


    for(i=0; i<9; i++) {
        if(sudo[row][i]!=0) {
            Y[row][col][sudo[row][i]-1]=false;
        }
    }

    int A=row/3, B=col/3;
    for(i=A*3; i<(A+1)*3; i++) {
        for(j=B*3; j<(B+1)*3; j++) {
            if(sudo[i][j]!=0) {
                Y[row][col][sudo[i][j]-1]=false;
            }
        }
    }
}



