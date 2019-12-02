/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Cong Co
 *
 * Created on June 30, 2017, 6:31 PM
 */

#include <cstdlib>
#include <stdio.h>
#include <limits.h>
using namespace std;

/*
 * 
 */

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


void enter_Array(int *arr, int size){
    for(int i=0;i<size;i++){
        printf("Input a[%d]: ", i);
        int temp = getElement(); //check element
            arr[i] = temp;
    }
}


//show array on screen
void display(int *arr, int size){
    for(int i=0;i<size;i++){
        printf("%3d", arr[i]);
    }
    printf("\n");
}

int *addElement(int *arr, int *newarr, int &size){
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

void findInDex(int *arr, int size){
    int count=0;
    int index[size];
    int check=0;
    printf("\nNew value: ");
    int value = getElement(); //check add value
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

void deleteElement(int *arr, int &size, int pos){
    for(int i=pos;i<size;i++){ 
        arr[i]=arr[i+1]; //delete location
    }
    size--;
}

void deleteFirst(int *arr, int &size){
    printf("Enter number you want to delete: ");
    int num = getElement();
    for(int i=0;i<size;i++){
        if(arr[i]==num){ //delete first of dublicate element
            deleteElement(arr,size,i);
            break;
        }
    }
    display(arr,size);
}


void deleteAll(int *arr, int &size){
    printf("Enter number you want to delete all: ");
    int num = getElement();
    for(int i=0;i<size;i++){   
        if(arr[i]==num){
            deleteElement(arr,size,i);//delete all the same elements
        }
    }
    display(arr,size);
}

void sortAscending(int *arr, int size){
    for(int i=0;i<size;i++){
        for(int j=size-1;j>i;j--){
            if(arr[j]<arr[j-1]){ //ascending elements  value of array
                int temp = arr[j-1];
                arr[j-1] = arr[j]; //swap element
                arr[j] = temp;
            }
        }
    }
    display(arr,size);
}

void sortDescending(int *arr, int size){
    for(int i=0;i<size;i++){
        for(int j=size-1;j>i;j--){
            if(arr[j]>arr[j-1]){ //descending elements  value of array
                int temp = arr[j-1];
                arr[j-1] = arr[j]; //swap element
                arr[j] = temp;
            }
        }
    }
    display(arr,size);
}

int getChoice(int min, int max){
    int num;
    int check;
    char c;
    do{
        printf("Please enter number(1-7) and another number exits: ");
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

int menuChoice(int *arr, int size){
    int check=0;
    int *newarr;
    do{
        int choice = getChoice(INT_MIN, INT_MAX);
        switch(choice){
            case 1:
            {
                check=1;
                newarr=addElement(arr,newarr,size);
                display(newarr,size);
                break;
            }
            case 2:
            {
                if(check==1){
                    findInDex(newarr,size);
                }
                else{
                    findInDex(arr,size);
                }
                break;
            }
            
            case 3:
            {
                if(check==1){
                    deleteFirst(newarr,size);
                }
                else{
                   deleteFirst(arr,size);
                }
                break;
            }
            
            case 4:
            {
                if(check==1){
                    deleteAll(newarr,size);
                }
                else{
                    deleteAll(arr,size);
                }
                break;
            }
            
            case 5:
            {
                if(check==1){
                    display(newarr,size);
                }
                else{
                    display(arr,size);
                }
                break;
            }
            case 6:
            {
                if(check==1){
                    sortAscending(newarr,size);
                }
                else{
                    sortAscending(arr,size);
                }
                break;
            }
            case 7:
            {
                if(check==1){
                    sortDescending(newarr,size);
                }
                else{
                    sortDescending(arr,size);
                }
                break;
            }
            default:
                return 0;
        }
    }while(1);
}


int main(int argc, char** argv) {
    int size=getInt(1,100);
    int *arr = (int*) calloc(size, sizeof(int));
    enter_Array(arr,size);
    display(arr,size);
    printf("=====Menu=====\n");
    printf("1. Ad a value\n");
    printf("2. Search a value\n");
    printf("3. Remove the first existence of value\n");
    printf("4. Remove all existence of value\n");
    printf("5. Print out the array\n");
    printf("6. Sort the array in ascending order\n");
    printf("7. Sort the array in descending order\n");
    menuChoice(arr,size);
    return 0;
}

