/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Cong Co
 *
 * Created on May 30, 2017, 11:43 PM
 */

#include <cstdlib>
#include <stdio.h>
#include <string.h>
using namespace std;

/*
 * 
 */

char str[100];
char arr[100][100];
char *p;
int i=0;
int c=0;

void reversed_String(){
    p = strtok(str,"_");//cut string with _
    while( p != NULL ){
	strcpy(arr[c], p);
	c++;  
	p = strtok(NULL,"_");// cut the string from the previous stop position
        
    }
}


int main() {
	printf ("Plaease enter string: ");
	gets(str);
	printf("The old string: %s\n", str);
        reversed_String();
        printf("The reversed string: ");
        if(c>1){
        for (int i = c - 1; i >= 0 ; i--){  //reverse string
            printf ("%s", arr[i]);
            for(int j = i-1;j>=0;j--){
                if(arr[j] != ""){
                    printf ("%s", "_");
                }
            }
	}
	}else{
            
             printf ("_%s", arr[0]);
        }
	return 0;
}

