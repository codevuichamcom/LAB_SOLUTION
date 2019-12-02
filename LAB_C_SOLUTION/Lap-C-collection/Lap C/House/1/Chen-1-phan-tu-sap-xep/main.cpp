/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Cong Co
 *
 * Created on June 4, 2017, 11:12 PM
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
        printf ("Please enter size of array ");
        check = scanf("%d%c", &num, &c);//Returns the value of an integer
        if(c !='\n' || num<min || num>max){
            printf("The Number of Array size can only between 1-100\n");
            fpurge(stdin);//Delete buffer
            check=0;
    }
        else{
            check=1;   
        }
    }while(check == 0);
    return num;
}

int getElement(){
    int i;
    int num;
    int check;
    char c;    
        do{
            check = scanf("%d%c", &num, &c);//Returns the value of an integer
            if(c !='\n' || check==0){
                printf("Integer of Array's element can not contains any letters\n");
                fpurge(stdin);//Delete buffer
                check=0; //input is a character
            }
            else{
                check=1;   //input is a number
            }
        }while(check == 0);
        return num;
}

void enter_Array(int arr[], int num){
    for(int i=0;i<num;i++){
       printf("Input a[%d]: ", i);
       int temp = getElement(); //check element
        arr[i] = temp;
    }
}

//show array on screen
void display(int arr[], int size){
    for(int i=0;i<size;i++){
        printf("%3d", arr[i]);
    }
}

//sort array in ascending
void sortArray(int arr[], int size){
    int temp;
    for(int i=0;i<size-1;i++){
        for(int j=i+1;j<size;j++){
            if(arr[i]>arr[j]){ //swap 2 element and ascending
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

// add new element x in array
void addnewElement(int arr[], int &size, int &x){
    printf("\nPlease enter new value:");
    x=getElement(); //check add element
    for(int i=size;i>0;i--){
        arr[i] = arr[i-1];
    }
    arr[0]=x;
    size++;
    sortArray(arr,size);
}

int main(int argc, char** argv) {
    int arr[100];
    int size=getInt(1,100);
    int x;
    enter_Array(arr,size);
    printf("The array after sorting: \n");
    sortArray(arr,size);
    display(arr,size);
    addnewElement(arr,size,x);
    printf("New array: ");
    display(arr,size);
    return 0;
}

