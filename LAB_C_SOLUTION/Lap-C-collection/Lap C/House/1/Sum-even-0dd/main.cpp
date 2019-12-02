/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Cong Co
 *
 * Created on May 26, 2017, 12:48 AM
 */

#include <cstdlib>
#include <stdio.h>

using namespace std;

/*
 * 
 */
int getInt(int min, int max){
    int num;
    char check;
    char c;
    do{
        printf ("Enter a number of element n= ");
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

int *getArr(int *arr, int num){
    arr =(int *) calloc (100, sizeof(int));//The memory allocator level
    for (int i = 0; i < num; i ++){
        fpurge(stdin);
        printf ("Element %d: ", i+1); // Element of array
        scanf ("%d", &arr[i]);
    }
    return arr;  
}

int sum_Even(int *arr, int num){
    int sum_even=0;
    for(int i=0;i<num;i++){  
        if(arr[i]%2==0){
            sum_even+=arr[i]; //sum of even
        }
    }
    return sum_even;
}

int sum_Odd(int *arr, int num){
    int sum_odd=0;
    for(int i=0;i<num;i++){
        if(arr[i]%2!=0){
            sum_odd+=arr[i]; //sum of odd
        }
    }
    return sum_odd;
}

void out_Put(int *arr, int num){
    sum_Even(arr,num);
    sum_Odd(arr,num);
    printf("Sum of Even=%d\n", sum_Even(arr,num));
    printf("Sum of Odd=%d", sum_Odd(arr,num));
}

int main(int argc, char** argv){
    int *arr=NULL;
    printf("Sum Even Odd program\n");
    int num=getInt(1,100); //check number
    printf("Input element: \n");
    arr = getArr(arr,num);
    out_Put(arr,num); //display output
    return 0;
}


