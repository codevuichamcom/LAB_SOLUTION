#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>


int inputCheck(char msg[], char error[], int min, int max){
	int num;
	int check; 
	char c;
	do{
		printf("%s",msg);
		check=scanf("%d%c", &num, &c);//Returns the value of an integer
		fflush(stdin);
        if(check!=2||c != '\n' || num<=min || num>max){
            printf("%s",error);
            fflush(stdin);//Delete buffer
            check=0; //input is a character
        }
        else{
            check=1; //input is a number
        }
    }while(check==0);
    return num;
	
}

void func1(int &a){
  	a=inputCheck("Enter an integer n=","Enter an integer number\n",INT_MIN,INT_MAX);
}

void func2(int n,int &s){
	n=abs(n);
	  s=0;
	while(n>0){
	  	s=s+(n%10);
	  	n/=10;
	}
}

void func3(int s){
	printf("Sum digit = %d",s);
  	printf("\nPress any key to continue.");
//  	fflush(stdin);//xoa bo dem de phong enter con dang luu trong bo dem.
  	char c= getchar();
  	fflush(stdin);
}


int main() {
	int n,s;
  printf("Sum Digit Program\n");
  while(true){
  	func1(n);
  	func2(n,s);
  	func3(s);
  }


  return 0;
}

