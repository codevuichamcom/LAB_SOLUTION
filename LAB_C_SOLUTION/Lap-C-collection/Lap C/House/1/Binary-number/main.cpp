/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Cong Co
 *
 * Created on June 4, 2017, 10:23 PM
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
        printf ("Enter a positive number:  ");
        check = scanf ("%d%c", &num,&c); //Returns the value of an integer
        if (c != '\n' || num==0){
            printf ("The number of element size can only between 1-100\n");
            fpurge(stdin); //Delete buffer
            check = 0;
        }
        else check = 1;
    }while (check == 0);
    return num;
}

int decimal_Val(int size){
	long long binary_val=0;
	int base=1;
        int rem;
	while(size>0){
		rem=size%2; //remainder
		size/=2;
		binary_val+=rem*base;
		base*=10;
	}
	return binary_val;
}

int main(int argc, char** argv) {
    int size;
    while(size != 27){
        printf("Convert Decimal to Binary program\n");
        size=getInt(); //check number
        printf("Binary number: %d\n", decimal_Val(size));
        printf("Press any key to do another conversion\n");
        size = getchar();
    }
    
}

