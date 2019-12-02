/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Cong Co
 *
 * Created on June 7, 2017, 11:00 PM
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
        printf("Enter the size of an array: ");
        check = scanf ("%d%c", &num,&c); //Returns the value of an integer
        if (c != '\n' || num < min || num > max){
            printf ("The number of element size can only between 1-100\n");
            fpurge(stdin); //Delete buffer
            check = 0; //input is a character
        }
        else check = 1; //input is a number
    }while (check == 0); 
    return num;
}


int getElement(int i){
    int num;
    int check;
    char c;    
        do{
            printf("Input a[%d]: ", i++);
            check = scanf("%d%c", &num, &c);//Returns the value of an integer
            if(c !='\n' || check==0){
                printf("Integer of Array's element can not contains any letters\n");
                fpurge(stdin);//Delete buffer
                check=0; //input is a character
                i--;
            }
            else{
                check = 1;   //input is a number
            }
        }while(check == 0);
        return num;
}

void enter_Array(int *arr, int size){
    for(int i=0;i<size;i++){
        int temp = getElement(i); //check element
            arr[i] = temp;
    }
}

//show array on screen
void display(int *arr, int size){
    for(int i=0;i<size;i++){
        printf("%3d", arr[i]);
    }
}

int maxElement(int *arr, int size){
    int max=arr[0];
    for(int i=0;i<size;i++){
        if(max<arr[i]){
            max=arr[i]; //max-value
        }
    }
    return max;
}

//even number
void evenElement(int *arr, int size){
    for(int i=0;i<size;i++){
        if(arr[i]%2==0){ //even number of elements
            printf("%3d", arr[i]);
        }
    }
}

int main(int argc, char** argv) {
    int size=getInt(1,100);
    int *arr = (int*) calloc(size, sizeof(int));
    enter_Array(arr,size);
    printf("Array element\n");
    display(arr,size);
    printf("\nArray maximum value\n");
    printf("The max is %d\n", maxElement(arr,size));
    printf("Array even values\n");
    evenElement(arr,size); 
    return 0;
}

