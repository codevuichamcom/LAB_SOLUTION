/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Cong Co
 *
 * Created on June 8, 2017, 3:15 PM
 */

#include <cstdlib>
#include <stdio.h>
#include <limits.h>
using namespace std;

/*
 * 
 */
int size;
int getInt(int min, int max){
    int num;
    int check;
    char c;
    do{
        printf ("Enter size of array: ");
        check = scanf("%d%c", &num, &c);//Returns the value of an integer
        if(c !='\n' || num<min || num>max){
            printf ("The number of element size can only between 1-100\n");
            fpurge(stdin);//Delete buffer
            check=0; //input is a character
    }
        else{
            check=1;   //input is a number
        }
    }while(check == 0);
    return num;
}

int getElement(){
    int num;
    int check;
    char c;    
        do{
            check = scanf("%d%c", &num, &c);//Returns the value of an integer
            if(c !='\n' || check==0){
                printf("Integer number can not contains any letters\n");
                fpurge(stdin);//Delete buffer
                check=0; //input is a character
            }
            else{
                check=1;   //input is a number
            }
        }while(check == 0);
        return num;
}


void enter_Array(int *arr){
    for(int i=0;i<size;i++){
        printf("Input a[%d]: ", i);
        int temp = getElement(); //check element
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

int *addElement(int *arr, int *newarr){
    newarr = (int*) realloc(arr,1+size*sizeof(int));
    for(int i = 0; i < size;i++){
        newarr[i] = arr[i]; //assign old array values to new array
    } 
    printf("Enter add element: ");
    int x=getElement();
    for(int i=size;i<size+1;i++){
        newarr[i] = x; //add value  
    }
    size++; 
    return newarr;
}

void findInDex(int *arr){
    int count=0;
    int index[size];
    int check=0;
    printf("\nNew value: ");
    int value = getElement(); // check add value
    for(int i=0;i<size;i++){
        if(value == arr[i]){
            index[count] = i;
            count++; //count the occurrences of the value
            check=1;
        }
    }
    if(check != 1){
        printf("No number are satisfied\n");
    }
    for(int i=0;i<count;i++){
            printf("\nNumber %d are location %d",value, index[i]);
    }
    printf("\n");
}

int minMax(int *arr){
    int min=arr[0];
    int max=arr[0];
    for(int i=0;i<size;i++){
        if(min>arr[i]){
            min=arr[i]; //minimum value
        }
    }
    for(int i=0;i<size;i++){
        if(max<arr[i]){
            max=arr[i]; //maximum value
        }
    }
    printf("Min = %d\n", min);
    printf("Max = %d\n", max);
}

void sortAscending(int *arr){
    for(int i=0;i<size;i++){
        for(int j=size-1;j>i;j--){
            if(arr[j]<arr[j-1]){ //ascending elements  value of array
                int temp = arr[j-1];
                arr[j-1] = arr[j]; //swap element
                arr[j] = temp;
            }
        }
    }

}

int getChoice(int min, int max){
    int num;
    int check;
    char c;
    do{
        printf("Please enter number(1-5) and another number exits: ");
        check = scanf("%d%c", &num, &c);//Returns the value of an integer
        if(c !='\n' || num<min || num>max){
            printf("Integer of choice can not contains any letters\n");
            fpurge(stdin);//Delete buffer
            check=0; //input is a character
    }
        else{
            check=1;   //input is a number
        }
    }while(check == 0);
    return num;
}
int main(int argc, char** argv) {
    int check=0;
    size=getInt(1,100);
    int *arr = (int*) calloc(size, sizeof(int));
    int *newarr;
    enter_Array(arr);
    display(arr);
    printf("=====Menu=====\n");
    printf("1. Add\n");
    printf("2. Search element of array\n");
    printf("3. Print all elements\n");
    printf("4. Print all elements in range of [min, max]\n");
    printf("5. Sort ascending\n");
    do{
        int choice = getChoice(INT_MIN, INT_MAX);
        switch(choice){
            case 1:
            {   
                check = 1;
                newarr = addElement(arr, newarr);
                display(newarr);
                break;
            }
            case 2:
            {
                if(check == 1)
                findInDex(newarr);
                else
                    findInDex(arr);
                break;
            }
            case 3:
            {
                if(check==1)
                    display(newarr);
                else
                    display(arr);
                break;
            }
            case 4:
            {
                if(check==1)
                    minMax(newarr);
                else
                    minMax(arr);
                break;
            }
            case 5:
            {
                if(check==1){
                    sortAscending(newarr);
                    display(newarr);
                }else{
                    sortAscending(arr);
                    display(arr);
                } 
                break;
            }
            default:
                return 0;
        }
    }while(1);
}
