#include<iostream>
#include<time.h>
#include"sudoku.h"

using namespace std;

typedef struct state state;


int main () {

    sudoku sudo, solve;
    sudo.set();

    int i=0,j=0, k=0, t=0;
/*
    for(i=0; i<9; i++){
        for(j=0; j<9; j++){

            if(sudo.returnNum(i,j)==0){
                t++;
            }
        }
    }
    if(t>=65){
        cout<<"2"<<endl;
        exit(0);
    }
*/


    solve = sudo;


    for(i=0; i<9; i++) {
        for(j=0; j<9; j++) {
            if(sudo.returnNum(i,j)!=0) {
                solve.fillinColFalse(j, solve.returnNum(i,j));
                solve.fillinRowFalse(i, solve.returnNum(i,j));
                solve.fillinSquareFalse(i,j,solve.returnNum(i,j));

                sudo.fillinColFalse(j, solve.returnNum(i,j));
                sudo.fillinRowFalse(i, solve.returnNum(i,j));
                sudo.fillinSquareFalse(i,j,solve.returnNum(i,j));
            }
        }
    }


//
int q=0, u=0;
int rowq=0;
int rowu1=0,rowu2=0,rowu3=0,rowu4=0,rowu5=0,rowu6=0,rowu7=0,rowu8=0,rowu9=0;                                             
int x1,x2,x3,x4,x5,x6,x7,x8,x9;                                                                                          
int y1,y2,y3,y4,y5,y6,y7,y8,y9;
int colq=0;
int colu1=0,colu2=0,colu3=0,colu4=0,colu5=0,colu6=0,colu7=0,colu8=0,colu9=0;
int v1,v2,v3,v4,v5,v6,v7,v8,v9;
int w1,w2,w3,w4,w5,w6,w7,w8,w9;
do{
    q=0;
    for(i=0; i<9; i++){
        for(j=0; j<9; j++){
            if(sudo.returnNum(i,j)==0){

                u=0;
                for(k=1; k<10; k++){
                    if(sudo.returnY(i,j,k)){
                        u++;
                        if(u==2){
                            k=9;
                        }
                    }
                }

                if(u==1){
                    for(k=1; k<10; k++){
                        if(sudo.returnY(i,j,k)){
                            sudo.fillinNum(i,j,k);
                            sudo.fillinColFalse(j, sudo.returnNum(i,j));
                            sudo.fillinRowFalse(i, sudo.returnNum(i,j));
                            sudo.fillinSquareFalse(i,j,sudo.returnNum(i,j));

                            solve.fillinNum(i,j,k);
                            solve.fillinColFalse(j, solve.returnNum(i,j));
                            solve.fillinRowFalse(i, solve.returnNum(i,j));
                            solve.fillinSquareFalse(i,j,solve.returnNum(i,j));
                            k=9;
                            q++;
                        
                        }
                    }

                }
            }


        }
    }
//  }while(q>0);

//
// u is how many true
// q is how many new num i fill in
/*
int rowq=0;
int rowu1=0,rowu2=0,rowu3=0,rowu4=0,rowu5=0,rowu6=0,rowu7=0,rowu8=0,rowu9=0;
int x1,x2,x3,x4,x5,x6,x7,x8,x9;
int y1,y2,y3,y4,y5,y6,y7,y8,y9;
*/
    
for(i=0; i<9; i++){
    for(j=0; j<9; j++){
        if(sudo.returnNum(i,j)==0){
            if(sudo.returnY(i,j,1)){
                x1=i;
                y1=j;
                rowu1++;
                
            }

            if(sudo.returnY(i,j,2)){
                x2=i;
                y2=j;
                rowu2++;
                
            }

            if(sudo.returnY(i,j,3)){
                x3=i;
                y3=j;
                rowu3++;
                
            }

            if(sudo.returnY(i,j,4)){
                x4=i;
                y4=j;
                rowu4++;
                
            }


            if(sudo.returnY(i,j,5)){
                x5=i;
                y5=j;
                rowu5++;
                
            }


            if(sudo.returnY(i,j,6)){
                x6=i;
                y6=j;
                rowu6++;
                
            }

            if(sudo.returnY(i,j,7)){
                x7=i;
                y7=j;
                rowu7++;
                
            }

            if(sudo.returnY(i,j,8)){
                x8=i;
                y8=j;
                rowu8++;
                
            }


            if(sudo.returnY(i,j,9)){
                x9=i;
                y9=j;
                rowu9++;
                
            }

        }
    }

    if(rowu1==1){
        sudo.fillinNum(x1,y1,1);
        sudo.fillinColFalse(y1, sudo.returnNum(x1,y1));
        sudo.fillinRowFalse(x1, sudo.returnNum(x1,y1));
        sudo.fillinSquareFalse(x1,y1,sudo.returnNum(x1,y1));
        solve.fillinNum(x1,y1,1);
        solve.fillinColFalse(y1, sudo.returnNum(x1,y1));
        solve.fillinRowFalse(x1, sudo.returnNum(x1,y1));
        solve.fillinSquareFalse(x1,y1,sudo.returnNum(x1,y1));
        q++;
    }

    if(rowu2==1){
        sudo.fillinNum(x2,y2,2);
        sudo.fillinColFalse(y2, sudo.returnNum(x2,y2));
        sudo.fillinRowFalse(x2, sudo.returnNum(x2,y2));
        sudo.fillinSquareFalse(x2,y2,sudo.returnNum(x2,y2));
        solve.fillinNum(x2,y2,2);
        solve.fillinColFalse(y2, sudo.returnNum(x2,y2));
        solve.fillinRowFalse(x2, sudo.returnNum(x2,y2));
        solve.fillinSquareFalse(x2,y2,sudo.returnNum(x2,y2));
        q++;
    }

    if(rowu3==1){
        sudo.fillinNum(x3,y3,3);
        sudo.fillinColFalse(y3, sudo.returnNum(x3,y3));
        sudo.fillinRowFalse(x3, sudo.returnNum(x3,y3));
        sudo.fillinSquareFalse(x3,y3,sudo.returnNum(x3,y3));
        solve.fillinNum(x3,y3,3);
        solve.fillinColFalse(y3, sudo.returnNum(x3,y3));
        solve.fillinRowFalse(x3, sudo.returnNum(x3,y3));
        solve.fillinSquareFalse(x3,y3,sudo.returnNum(x3,y3));
        q++;
    }

    if(rowu4==1){
        sudo.fillinNum(x4,y4,4);
        sudo.fillinColFalse(y4, sudo.returnNum(x4,y4));
        sudo.fillinRowFalse(x4, sudo.returnNum(x4,y4));
        sudo.fillinSquareFalse(x4,y4,sudo.returnNum(x4,y4));
        solve.fillinNum(x4,y4,4);
        solve.fillinColFalse(y4, sudo.returnNum(x4,y4));
        solve.fillinRowFalse(x4, sudo.returnNum(x4,y4));
        solve.fillinSquareFalse(x4,y4,sudo.returnNum(x4,y4));
        q++;
    }

    if(rowu5==1){
        sudo.fillinNum(x5,y5,5);
        sudo.fillinColFalse(y5, sudo.returnNum(x5,y5));
        sudo.fillinRowFalse(x5, sudo.returnNum(x5,y5));
        sudo.fillinSquareFalse(x5,y5,sudo.returnNum(x5,y5));
        solve.fillinNum(x5,y5,5);
        solve.fillinColFalse(y5, sudo.returnNum(x5,y5));
        solve.fillinRowFalse(x5, sudo.returnNum(x5,y5));
        solve.fillinSquareFalse(x5,y5,sudo.returnNum(x5,y5));
        q++;
    }

    if(rowu6==1){
        sudo.fillinNum(x6,y6,6);
        sudo.fillinColFalse(y6, sudo.returnNum(x6,y6));
        sudo.fillinRowFalse(x6, sudo.returnNum(x6,y6));
        sudo.fillinSquareFalse(x6,y6,sudo.returnNum(x6,y6));
        solve.fillinNum(x6,y6,6);
        solve.fillinColFalse(y6, sudo.returnNum(x6,y6));
        solve.fillinRowFalse(x6, sudo.returnNum(x6,y6));
        solve.fillinSquareFalse(x6,y6,sudo.returnNum(x6,y6));
        q++;
    }

    if(rowu7==1){
        sudo.fillinNum(x7,y7,7);
        sudo.fillinColFalse(y7, sudo.returnNum(x7,y7));
        sudo.fillinRowFalse(x7, sudo.returnNum(x7,y7));
        sudo.fillinSquareFalse(x7,y7,sudo.returnNum(x7,y7));
        solve.fillinNum(x7,y7,7);
        solve.fillinColFalse(y7, sudo.returnNum(x7,y7));
        solve.fillinRowFalse(x7, sudo.returnNum(x7,y7));
        solve.fillinSquareFalse(x7,y7,sudo.returnNum(x7,y7));
        q++;
    }

    if(rowu8==1){
        sudo.fillinNum(x8,y8,8);
        sudo.fillinColFalse(y8, sudo.returnNum(x8,y8));
        sudo.fillinRowFalse(x8, sudo.returnNum(x8,y8));
        sudo.fillinSquareFalse(x8,y8,sudo.returnNum(x8,y8));
        solve.fillinNum(x8,y8,8);
        solve.fillinColFalse(y8, sudo.returnNum(x8,y8));
        solve.fillinRowFalse(x8, sudo.returnNum(x8,y8));
        solve.fillinSquareFalse(x8,y8,sudo.returnNum(x8,y8));
        q++;
    }

    if(rowu9==1){
        sudo.fillinNum(x9,y9,9);
        sudo.fillinColFalse(y9, sudo.returnNum(x9,y9));
        sudo.fillinRowFalse(x9, sudo.returnNum(x9,y9));
        sudo.fillinSquareFalse(x9,y9,sudo.returnNum(x9,y9));
        solve.fillinNum(x9,y9,9);
        solve.fillinColFalse(y9, sudo.returnNum(x9,y9));
        solve.fillinRowFalse(x9, sudo.returnNum(x9,y9));
        solve.fillinSquareFalse(x9,y9,sudo.returnNum(x9,y9));
        q++;
    }

}

/*
int colq=0;
int colu1=0,colu2=0,colu3=0,colu4=0,colu5=0,colu6=0,colu7=0,colu8=0,colu9=0;
int v1,v2,v3,v4,v5,v6,v7,v8,v9;
int w1,w2,w3,w4,w5,w6,w7,w8,w9;
*/
    
for(j=0; j<9; j++){
    for(i=0; i<9; i++){
        if(sudo.returnNum(i,j)==0){
            if(sudo.returnY(i,j,1)){
                v1=i;
                w1=j;
                colu1++;
                /*
                if(rowu1==2){
                    j=8;
                }
                */
            }

            if(sudo.returnY(i,j,2)){
                v2=i;
                w2=j;
                colu2++;
                /*
                if(row2==2){
                    j=8;
                }
                */
            }

            if(sudo.returnY(i,j,3)){
                v3=i;
                w3=j;
                colu3++;
                /*
                if(row3==2){
                    j=8;
                }
                */
            }

            if(sudo.returnY(i,j,4)){
                v4=i;
                w4=j;
                colu4++;
                /*
                if(row4==2){
                    j=8;
                }
                */
            }


            if(sudo.returnY(i,j,5)){
                v5=i;
                w5=j;
                colu5++;
                /*
                if(row5==2){
                    j=8;
                }
                */
            }


            if(sudo.returnY(i,j,6)){
                v6=i;
                w6=j;
                colu6++;
                /*
                if(row6==2){
                    j=8;
                }
                */
            }

            if(sudo.returnY(i,j,7)){
                v7=i;
                w7=j;
                colu7++;
                /*
                if(row7==2){
                    j=8;
                }
                */
            }

            if(sudo.returnY(i,j,8)){
                v8=i;
                w8=j;
                colu8++;
                /*
                if(row8==2){
                    j=8;
                }
                */
            }


            if(sudo.returnY(i,j,9)){
                v9=i;
                w9=j;
                colu9++;
                /*
                if(row9==2){
                    j=8;
                }
                */
            }

        }
    }

    if(colu1==1){
        sudo.fillinNum(v1,w1,1);
        sudo.fillinColFalse(w1, sudo.returnNum(v1,w1));
        sudo.fillinRowFalse(v1, sudo.returnNum(v1,w1));
        sudo.fillinSquareFalse(v1,w1,sudo.returnNum(v1,w1));
        solve.fillinNum(v1,w1,1);
        solve.fillinColFalse(w1, sudo.returnNum(v1,w1));
        solve.fillinRowFalse(v1, sudo.returnNum(v1,w1));
        solve.fillinSquareFalse(x1,y1,sudo.returnNum(v1,w1));
        q++;
    }

    if(colu2==1){
        sudo.fillinNum(v2,w2,2);
        sudo.fillinColFalse(w2, sudo.returnNum(v2,w2));
        sudo.fillinRowFalse(v2, sudo.returnNum(v2,w2));
        sudo.fillinSquareFalse(v2,w2,sudo.returnNum(v2,w2));
        solve.fillinNum(v2,w2,2);
        solve.fillinColFalse(w2, sudo.returnNum(v2,w2));
        solve.fillinRowFalse(v2, sudo.returnNum(v2,w2));
        solve.fillinSquareFalse(v2,w2,sudo.returnNum(v2,w2));
        q++;
    }

    if(colu3==1){
        sudo.fillinNum(v3,w3,3);
        sudo.fillinColFalse(w3, sudo.returnNum(v3,w3));
        sudo.fillinRowFalse(v3, sudo.returnNum(v3,w3));
        sudo.fillinSquareFalse(v3,w3,sudo.returnNum(v3,w3));
        solve.fillinNum(v3,w3,3);
        solve.fillinColFalse(w3, sudo.returnNum(v3,w3));
        solve.fillinRowFalse(v3, sudo.returnNum(v3,w3));
        solve.fillinSquareFalse(v3,w3,sudo.returnNum(v3,w3));
        q++;
    }

    if(colu4==1){
        sudo.fillinNum(v4,w4,4);
        sudo.fillinColFalse(w4, sudo.returnNum(v4,w4));
        sudo.fillinRowFalse(v4, sudo.returnNum(v4,w4));
        sudo.fillinSquareFalse(v4,w4,sudo.returnNum(v4,w4));
        solve.fillinNum(v4,w4,4);
        solve.fillinColFalse(w4, sudo.returnNum(v4,w4));
        solve.fillinRowFalse(v4, sudo.returnNum(v4,w4));
        solve.fillinSquareFalse(v4,w4,sudo.returnNum(v4,w4));
        q++;
    }

    if(colu5==1){
        sudo.fillinNum(v5,w5,5);
        sudo.fillinColFalse(w5, sudo.returnNum(v5,w5));
        sudo.fillinRowFalse(v5, sudo.returnNum(v5,w5));
        sudo.fillinSquareFalse(x5,y5,sudo.returnNum(v5,w5));
        solve.fillinNum(v5,w5,5);
        solve.fillinColFalse(w5, sudo.returnNum(v5,w5));
        solve.fillinRowFalse(v5, sudo.returnNum(v5,w5));
        solve.fillinSquareFalse(v5,w5,sudo.returnNum(v5,w5));
        q++;
    }

    if(colu6==1){
        sudo.fillinNum(v6,w6,6);
        sudo.fillinColFalse(w6, sudo.returnNum(v6,w6));
        sudo.fillinRowFalse(v6, sudo.returnNum(v6,w6));
        sudo.fillinSquareFalse(v6,w6,sudo.returnNum(v6,w6));
        solve.fillinNum(v6,w6,6);
        solve.fillinColFalse(w6, sudo.returnNum(v6,w6));
        solve.fillinRowFalse(v6, sudo.returnNum(v6,w6));
        solve.fillinSquareFalse(v6,w6,sudo.returnNum(v6,w6));
        q++;
    }

    if(colu7==1){
        sudo.fillinNum(v7,w7,7);
        sudo.fillinColFalse(w7, sudo.returnNum(v7,w7));
        sudo.fillinRowFalse(v7, sudo.returnNum(v7,w7));
        sudo.fillinSquareFalse(v7,w7,sudo.returnNum(v7,w7));
        solve.fillinNum(v7,w7,7);
        solve.fillinColFalse(w7, sudo.returnNum(v7,w7));
        solve.fillinRowFalse(v7, sudo.returnNum(v7,w7));
        solve.fillinSquareFalse(v7,w7,sudo.returnNum(v7,w7));
        q++;
    }

    if(colu8==1){
        sudo.fillinNum(v8,w8,8);
        sudo.fillinColFalse(w8, sudo.returnNum(v8,w8));
        sudo.fillinRowFalse(v8, sudo.returnNum(v8,w8));
        sudo.fillinSquareFalse(v8,w8,sudo.returnNum(v8,w8));
        solve.fillinNum(v8,w8,8);
        solve.fillinColFalse(w8, sudo.returnNum(v8,w8));
        solve.fillinRowFalse(v8, sudo.returnNum(v8,w8));
        solve.fillinSquareFalse(v8,w8,sudo.returnNum(v8,w8));
        q++;
    }

    if(colu9==1){
        sudo.fillinNum(v9,w9,9);
        sudo.fillinColFalse(w9, sudo.returnNum(v9,w9));
        sudo.fillinRowFalse(v9, sudo.returnNum(v9,w9));
        sudo.fillinSquareFalse(v9,w9,sudo.returnNum(v9,w9));
        solve.fillinNum(v9,w9,9);
        solve.fillinColFalse(w9, sudo.returnNum(v9,w9));
        solve.fillinRowFalse(v9, sudo.returnNum(v9,w9));
        solve.fillinSquareFalse(v9,w9,sudo.returnNum(v9,w9));
        q++;
    }

}


}while(q>0);






    for(i=0; i<9; i++) {
        j=0;
        while(j<9) {

            if( (solve.returnNum(i,j)==0) || (sudo.returnNum(i,j)==0) ) {


                k=solve.returnNum(i,j)+1;

                solve.reset(i,j);

                while(k<11) {
                    if(solve.returnY(i,j,k)) {
                        solve.fillinNum(i,j,k);
                        if(k<10) {

                            j++;
                        }
                        break;
                    } else {
                        k++;
                    }
                }




                if(solve.returnNum(i,j)==10) {
                    solve.fillinNum(i,j,0);
                    do {
                        if(j==0) {
                            if(i==0) {
                                cout << "0" <<endl;
                                exit(0);
                            } else {

                                i-=1;
                                j=8;
                            }
                        } else {
                            j-=1;
                        }
                    } while(sudo.returnNum(i,j)!=0);
                }
            } else j++;
        }
    }



    t=0;
    for(i=0; i<9; i++) {
        for(j=0; j<9; j++) {
            
            if(sudo.returnNum(i,j)==0) {

                t++;
            }
        }
    }


    if(t>=65) {
        cout<<"2"<<endl;
        exit(0);
    } else {
        cout<<"1";
    }



    cout << endl;
    solve.print();


    return (0);

}
