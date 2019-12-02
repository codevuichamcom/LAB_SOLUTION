/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Cong Co
 *
 * Created on May 16, 2017, 1:02 AM
 */

#include <cstdlib>
#include <stdio.h>

using namespace std;

/*enter array
 *min-position 
 */


int getInt(int min, int max){
    int num;
    int check;
    char c;
    do{
        printf ("\nEnter your choice: ");
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
                check=0;
                i--;
            }
            else{
                check=1;   
            }
        }while(check == 0);
        return num;
}

//show array on screen
void enter_Array(int arr[], int num){
    for(int i=0;i<num;i++){
        int temp = getElement(i);
        arr[i] = temp;
    }
}

int aMinimum(int arr[], int num){
    int min=arr[0], mini=0;
    for(int i=0;i<num;i++){
        if(min>arr[i]){
            min=arr[i]; //min-value
            mini=i; //position
        }
    }
    return mini;
}


int main(int argc, char** argv) {
    int num, arr[100], d;
    num = getInt(1,100); 
    enter_Array(arr,num);
    d=aMinimum(arr,num);
    printf("Min is %d- it is position: %d", arr[d], d+1);
    return 0;
}

