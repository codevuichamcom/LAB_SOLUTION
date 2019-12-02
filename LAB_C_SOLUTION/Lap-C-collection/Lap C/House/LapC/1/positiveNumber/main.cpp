/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Cong Co
 *
 * Created on June 16, 2017, 9:16 AM
 */

#include <cstdlib>
#include <stdio.h>
#include <math.h>
using namespace std;

/*
 * 
 */

int getInt(){
    int num;
    int check;
    char c;
    do{
        printf ("Enter a positive interger n=  ");
        check = scanf ("%d%c", &num,&c); //Returns the value of an integer
        if (c != '\n' ){
            printf ("Integer number can not contains any letters\n");
            fpurge(stdin);
            check = 0; //input is a character
        }
        else check = 1; //input is a number
    }while (check == 0);
    return num;
}

int checkSquare(int &numSquare){
    int temp=sqrt(numSquare);
    if(numSquare<=0){
        return 0; //it's not positive number
    }
    else{
        if(numSquare==temp*temp){
                return 1; //it's square number
        }
        else{
            return -1; //it's not square number
        }
    }
}

void display(int &numSquare, int &check){
    int temp;
    if(check==0){
        printf("Please enter a positive integer!\n");
    }else
        if(check==1){
            printf("%d is a square number %d = %d x %d\n", numSquare, numSquare, temp, temp);
        } 
    else
    {
        printf("%d is not a square number\n", numSquare);
    }
    
}
int main(int argc, char** argv) {
    int check;
    int checkContinue;
    while(checkContinue!=27){
        fpurge(stdin);
        int numSquare = getInt();
        check = checkSquare(numSquare);
        display(numSquare,check);
        printf("Press any key to continue\n");
        checkContinue=getchar();
    }
}