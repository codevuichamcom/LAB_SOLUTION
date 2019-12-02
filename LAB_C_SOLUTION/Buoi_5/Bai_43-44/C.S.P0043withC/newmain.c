/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: ThinkPro
 *
 * Created on August 26, 2019, 9:49 AM
 */

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

/*
 * 
 */

int checkInput(char msg[], char err[], int min, int max) {
    int num;
    int check;
    char c;
    do {
        printf("%s", msg);
        check = scanf("%d%c", &num, &c); //Returns the value of an integer
        if (check != 2 || c != '\n' || num < min || num > max) {
            printf("%s", err);
            fpurge(stdin); //Delete buffer
            check = 0; //input is a character
        } else {
            check = 1; //input is a number
        }
    } while (check == 0);
    return num;
}

void display(int a[],int size){
    for(int i=0;i<size;i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
}

int *addElement(int *a, int *size){
    a=(int*) realloc(a,(++*size)*sizeof(int));
    int x=checkInput("Enter add element: ","Try again!!!\n",INT_MIN,INT_MAX);
    a[*size-1]=x;//add value to the last
    return a;
}

int isExist(int a[], int size, int x) {
    for (int i = 0; i < size; i++) {
        if (a[i] == x) {
            return 1;
        }
    }
    return 0;
}
void findIndex(int a[],int size){
    int x=checkInput("Enter the value to find: ","try again!!!\n",INT_MIN,INT_MAX);
    if(isExist(a,size,x)==1){
        printf("Number %d has index:",x);
        for(int i=0;i<size;i++){
            if(a[i]==x){
                printf("%d  ",i);
            }
        }
    }else{
        printf("In array don't have number you were entered\n");
    }
    printf("\n");
}

void deleteElement(int a[],int *size, int pos){
    for(int i=pos;i<(*size);i++){
        a[i]=a[i+1];
    }
    (*size)--;
}
void deleteFirst(int a[], int *size){
    int x=checkInput("Enter the value to delete: ","Try again!!!\n",INT_MIN,INT_MAX);
    int i=0;
    while(i<*size){
        if(a[i]==x){
            deleteElement(a,size,i);
            break;
        }
        i++;
    }
    display(a,*size);
}
void deleteAll(int a[],int *size){
    int x=checkInput("Enter the value to delete: ","Try again!!!\n",INT_MIN,INT_MAX);
    int i=0;
    while(i<*size){
        if(a[i]==x){
            deleteElement(a,size,i);
            i--;
        }
        i++;
    }
}
void sortAcending(int a[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}
void sortDescending(int a[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]<a[j]){
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}

void copy(int a1[], int a2[], int n){
    for(int i=0;i<n;i++){
        a2[i]=a1[i];
    }
}
int menuOption(int a[], int size){
    int check=0;
    do{
        int choice = checkInput("Enter the choice: ", "try again!!!\n",INT_MIN,INT_MAX);
       
        switch(choice){
                case 1:{
                    a=addElement(a,&size);
                    break;
                }
                case 2:{
                    findIndex(a,size);
                    break;
                }
                case 3:{
                    deleteFirst(a,&size);
                    break;
                }
                case 4:{
                    deleteAll(a,&size);
                    break;
                }
                case 5:{
                    display(a,size);
                    break;
                }
                case 6:{
                    int a1[size];
                    copy(a,a1,size);
                    sortAcending(a1,size);
                    display(a1,size);
                    break;
                }
                case 7:{
                    int a2[size];
                    copy(a,a2,size);
                    sortDescending(a2,size);
                    display(a2,size);
                    break;
                }
                default:
                    return 0;

        }	
    }while(1);
    
}
int main(int argc, char** argv) {
    int size=0;
    int *a=(int *) calloc(0,sizeof(int));

        printf("--------Menu--------\n");	
        printf("1- Add a value\n");
        printf("2- Search a value\n");
        printf("3- Remove the first existence of a value\n");
        printf("4- Remove all existences of a value\n");
        printf("5- Print out the array\n");
        printf("6- Sort the array in ascending order\n");
        printf("7- Sort the array in descending order\n");
        printf("Others- Quit\n");
    menuOption(a,size);
    return 0;
}

