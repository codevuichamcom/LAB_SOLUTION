/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Cong Co
 *
 * Created on June 12, 2017, 7:39 PM
 */

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
#include<windows.h>
#define Clrscr() printf("\033[H\033[J")

#define BLA   "\x1B[30m"
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define LRE   "\x1b[41m"
#define MEG   "\x1b[45m"
#define RESET "\x1B[0m"

char arrColor[10][10] = {"\x1B[34m", "\x1B[37m", "\x1B[33m","\x1b[30m"  
                         "\x1B[31m","\x1B[35m","\x1B[36m","\x1B[32m",};
int getInt(int min, int max){
    int num;
    int check;
    char c;
    do{
        printf ("\nEnter your choice: ");
        check = scanf ("%d%c", &num,&c);
        if (c != '\n' || num < min || num > max){
            printf ("Invalid input\n");
            fpurge(stdin);
            check = 0;
        }
        else{
            check = 1;
        }
    }while(check == 0);
    return num;
}

void SaveMoney(float total){
    FILE *f = fopen("SaveMoney.txt", "w+");
    fprintf(f,"%.2f", total);
    fclose(f);
}
float GetMoney(float money){
    FILE *f = fopen("SaveMoney.txt", "r+");
    fscanf(f,"%f", &money);
    return money;
    fclose(f);
}
int main(int argc, char** argv) {
    int num;
    int a,b,c,check1 =0,check2=0;
    float total=10.0, money =0.0;
    FILE *f = fopen("SaveMoney.txt","r+");
    if(f==NULL) {
        fclose(f);
        SaveMoney(total);
    }else{
        if(GetMoney(money) == 0){
            rewind(f);
            SaveMoney(total);
        }
        else
            total = GetMoney(money);
    }
    printf("%sWelcome to Slot Machine%s\n",BLU,RESET);
    printf("You have%s %.2f$%s\n",RED,total,RESET);
    printf("%s-----------------MENU-----------------%s\n",RED,RESET);
    loop:
    printf("%s1. Play the slot machine\n",YEL);
    printf("2. Save game\n");
    printf("3. Cash out\n");
    printf("4. Quite game%s\n",RESET);
    while(total >0){
        printf("\n\nChoose one of the following menu options(1 or 2 or 3 or 4): ");
    switch(getInt(1,4)){
        case 1:{
            if(total <= 0){
                goto end;
            }
            else{
            total -= 0.25;
            check1 = 1;
            //srand(time(NULL));
            for(int i = 0;i<5000;i++){
            a = rand()%10;
            b = rand()%10;
            c = rand()%10;
            printf("%s %d %s",arrColor[a], a,RESET);
            printf("%s %d %s",arrColor[b], b,RESET);
            printf("%s %d %s",arrColor[c], c,RESET);
            Clrscr();
            }
            printf("The slot machine show: %s%d%s%d%s%d%s\n",arrColor[a],a,arrColor[b],b,arrColor[c],c,RESET);
            if((a==b)&&(a==c)){
                total += 10;
                printf("%s\nYou win 10$%s\n",RED,RESET);
                printf("%sYou have %.2f$%s\n\n",MAG, total,RESET);
            }else
                if(a==b||a==c||b==c){
                total += 0.5;
                printf("%s\nYou win 50 cents%s\n",RED,RESET);
                printf("%sYou have %.2f$%s\n",MAG, total,RESET);
            }
            else
                printf("\n%sSorry, You don't win anythings%s\n\n",YEL,RESET);
            goto loop;
            }
        } 
        case 2:{
            if(check1 == 0){
                printf("%sYou should play the game to get money%s\n\n", RED,RESET);
                goto loop;
            }
            else {
            check2=1;
            check1 =1;
            rewind(f);
            SaveMoney(total);
            Clrscr();
            printf("%sYour money had saved\n\nPress 1 to play continue\nor\nPress 3 to cash out your money%s\n\n",BLU,RESET);
            goto loop;
            }
        }
        case 3:{
            if(check1==0&&check2==0){
                printf("%sYou should play game to get money%s\n\n", RED,RESET);
                goto loop;
            }
            if(check2==0){
                printf("%sYou not save game\nPlease enter 2 to save game\nor\nEnter 1 to play continue%s\n\n",BLU,RESET);
            goto loop;
            }
            if(check1 == 1 && check2==1){
                Clrscr();
                printf("%s\nThanks you for playing! You end with %.2f$%s\n",RED, total,RESET);
                rewind(f);
                SaveMoney(0.0);
                goto GetMoney;
            }
        }
        case 4:{
            if(check2==0){
                printf("%sYou not save game\nPlease enter 2 to save game\nor\nEnter 1 to play continue%s\n\n",BLU,RESET);
                goto loop;
            }else
                goto GetMoney; 
        }
    }
    }
    end: {
            printf("%sYou lose!!!\n",RED);
            printf("Game Over");
    }
    GetMoney:  
    return (EXIT_SUCCESS);
}

