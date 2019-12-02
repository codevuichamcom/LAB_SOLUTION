/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Cong Co
 *
 * Created on May 26, 2017, 12:07 AM
 */

#include <cstdlib>
#include <stdio.h>
using namespace std;

/*
 * 
 */
int getInt(int min, int max){
    int num;
    int check;
    char c;
    do{
        printf ("Number of element s =  ");
        check = scanf ("%d%c", &num,&c); //Returns the value of an integer
        if (c != '\n' || num < min || num > max){
            printf ("The number of element size can only between 1-100\n");
            fpurge(stdin); //Delete buffer
            check = 0;
        }
        else check = 1;
    }while (check == 0);
    return num;
}


int getElement(int i){
    int num;
    int check;
    char c;
    do{
        printf ("Enter an integer: ");
        check = scanf ("%d%c", &num,&c); //Returns the value of an integer
        if (c != '\n' || check==0){
            printf ("Integer of Array's element can not contains any letters\n");
            fpurge(stdin); //Delete buffer
            check = 0;
        }
        else check = 1;
    }while (check == 0);
    return num;
}

// input element of array
void enter_Array(int arr[], int size){
    for(int i=0;i<size;i++){
        int temp = getElement(i); //check element
        arr[i] = temp;
    }
}

int sum_Array (int arr[], int size){
    int sum = 0;
    for (int i = 0; i < size; i++){ //Sum array
        sum = sum + arr[i];
    }
    return sum;
}
int main(int argc, char** argv) {
    int arr[100];
    int size;
    while(size != 27){
        fpurge(stdin);
        printf("Dynamic memory allocation\n");
        size=getInt(1,100); //check number
        enter_Array(arr,size); 
        printf("Sum = %d\n", sum_Array(arr,size));
        printf("Press any key to continue\n");
        size=getchar();
    }
}

