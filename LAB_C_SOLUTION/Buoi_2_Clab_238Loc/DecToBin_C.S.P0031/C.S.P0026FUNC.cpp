#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

int inputCheck(int min, int max){
    int num;
    int check;
    char c;
    do{
        check=scanf("%d%c", &num, &c);//Returns the value of an integer
        if(check!=2||c != '\n' || num<min || num>max){
           	printf("Please enter again!!!\n\tEnter a positive number: ");
            fflush(stdin);//Delete buffer
            check=0; //input is a character
        }
        else{
            check=1; //input is a number
        }
    }while(check==0);
    return num;
}

void func1(int &n){
	printf("\tEnter a positive number: ");
	n=inputCheck(1,INT_MAX);
}

void func2(int n){
	int size=0;
	printf("\tBinary Number: ");
		char A[32];
		while(n>0){
			A[size++]=n%2+48;
			n/=2;
		}
	for(int i = size-1;i>=0;i--){
		printf("%c",A[i]);
	}
}

int main(){
	int n;

	while(true){
		
		printf("Convert Decimal to Binary program\n");
		func1(n);
		func2(n);
		printf("\nPress any key to do another conversion.\n");
		char k =getchar();
		printf("\n");
	}
}
