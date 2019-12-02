/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Cong Co
 *
 * Created on June 7, 2017, 10:35 PM
 */

#include <cstdlib>
#include <stdio.h>
using namespace std;

/*
 * 
 */

int getInt(){
    int num;
    int check;
    char c;
    do{
        printf ("Enter an interger n=  ");
        check = scanf ("%d%c", &num,&c); //Returns the value of an integer
        if (c != '\n' ){
            printf ("The number of element size can only between 1-100\n");
            fpurge(stdin); //Delete buffer
            check = 0;
        }
        else check = 1;
    }while (check == 0);
    return num;
}

int sumDigit(int size){
    int sum=0;
    while(size != 0){
        if(size<0){
            size = -size;
        }
        int temp = size%10; // separation of number
        size/=10;
        sum += temp; //sum digit
    }
    return sum;
}
int main(int argc, char** argv) {
    int size;
    printf("Sum Digit Program\n");
    while(size != 27){
        fpurge(stdin);
        size=getInt(); //check number
        printf("Sum digit = %d\n", sumDigit(size));
        printf("Press any key to continue\n");
        size=getchar();
    }
}

