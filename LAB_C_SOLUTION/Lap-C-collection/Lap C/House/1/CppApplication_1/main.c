/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Cong Co
 *
 * Created on June 8, 2017, 11:27 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {

    int *c = (int*)malloc(2*sizeof(int));

    for(int i = 0; i < 2;i++){
        scanf("%d", &c[i]);
    }
    int *newc = (int*)realloc(c,3 + 2*sizeof(int));
    for(int i = 2; i < 5;i++){
        scanf("%d", &newc[i]);
    }
    
    return (EXIT_SUCCESS);
}

