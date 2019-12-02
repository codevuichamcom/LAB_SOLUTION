/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Cong Co
 *
 * Created on June 14, 2017, 3:41 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
/*
 * 
 */

int size;
int getInt(int min, int max){
    int num;
    int check;
    char c;
    do{
        printf("Enter size of array: ");
        check=scanf("%d%c", &num, &c);//Returns the value of an integer
        if(c != '\n' || num<min || num>max){
            printf("The number of element size can only between 1-100\n");
            fpurge(stdin);//Delete buffer
            check=0; //input is a character
        }
        else{
            check=1; //input is a number
        }
    }while(check==0);
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
                printf("Integer number can not contains any letters\n");
                fpurge(stdin);//Delete buffer
                check=0; //input is a character
                i--;
            }
            else{
                check=1;   //input is a number
            }
        }while(check == 0);
        return num;
}

void enter_Array(int *arr){
    for(int i=0;i<size;i++){
        int temp = getElement(i); //check element
            arr[i] = temp;
    }
}


//show array on screen
void display(int *arr){
    for(int i=0;i<size;i++){
        printf("%3d", arr[i]);
    }
    printf("\n");
}

void deletePosition(int *arr, int pos){
    for(int i=pos;i<size;i++){ //delete location
        arr[i]=arr[i+1];
    }
    size--;
}

void deleteElement(int *arr){
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(arr[i]==arr[j]){
                deletePosition(arr,j); //delete first location
                j--;
            }
        }
    }
}


int main(int argc, char** argv) {
    size=getInt(1,100);
    int *arr = (int*) calloc(size,sizeof(int));
    enter_Array(arr);
    printf("Array old is: \n");
    display(arr);
    printf("Array is: \n");
    deleteElement(arr);
    display(arr);
}

