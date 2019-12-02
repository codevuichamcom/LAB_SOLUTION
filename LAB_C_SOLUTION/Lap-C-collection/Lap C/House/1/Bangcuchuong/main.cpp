/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Cong Co
 *
 * Created on May 17, 2017, 3:17 PM
 */

#include <cstdlib>
#include <stdio.h>
using namespace std;

/*Enter a number 1-9
 * print multiplication table 
 * 
 */

int getInt(int min, int max){
    int num;
    int check;
    char c;
    do{
        printf("Please enter a number(1-9): ");
        check = scanf("%d%c", &num, &c);
        if(c !='\n' || num<min || num>max){
            printf("The Number can not contains any letters\n");
            fpurge(stdin);
            check=0;
    }
        else{
            check=1;   
        }
    }while(check == 0);
    return num;
}

void Multiple_Table(int num){
    for(int i=1;i<=10;i++){
        printf("%dx%d = %d\n", num, i, num*i);
    }
}
int main(int argc, char** argv) {
    int num;
    char ans;
    while(1){
    num=getInt(1,9);
    printf("Multiplication table for %d number\n", num);
    Multiple_Table(num);
    printf("Do you want to continue Y/N: ");
    scanf("%s", &ans);
    if(ans=='y'|| ans=='Y'){
    }else
        break;
    }
    return 0;
}

