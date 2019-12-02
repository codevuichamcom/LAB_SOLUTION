#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

int isPrime(int n){
	int i;
	if(n<2)
		return 0;
	for(i=2;i<=sqrt(n);i++){
		if(n%i==0)
			return 0;
	}
	return 1;
}

int inputCheck(char msg[], char error[], int min, int max){
	int check, num;
	char c;
	do{
		printf("%s",msg);fflush(stdin);
		check=scanf("%d%c", &num, &c);//Returns the value of an integer
        if(c != '\n' || num<min || num>max){
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

void displayPrime(){
	int num=inputCheck("Number of primes:","Enter again!!!(0<n<=50)\n",0,51);
	int dem=1,i=1;
  		while(dem<=num){
  			i++;
  			if(isPrime(i)){
  				printf("%d ",i);
  				dem++;
			}
		}
		  printf("\n\n");
}
void checkFibonaci(){
	int n,f1=0,f2=1,f3=1;
	  	n=inputCheck("Number tested:","Enter again!!!(0<n<=1000)\n",1,1000);
	  	while(f1+f2<=n){
	  		f3=f1+f2;
	  		f1=f2;
	  		f2=f3;
		  }
		  if(f3==n){
		  	printf("It's a Fibonacci term.\n\n");
		  }else{
		  	printf("It's not a Fibonacci term.\n\n");
		  }
}

void sumOfDigit(){
	int s=0,n;
	n=inputCheck("Enter an interger:","Try again!.Enter an integer number\n",1,INT_MAX);
	  	while(n>0){
	  		s=s+n%10;   
	  		n=n/10;
		  }
		  printf("Sum of it's digits:%d\n\n",s);
}

void menuOption(){
	do{
	
	printf("1-The first primes");
	printf("\n2-Fibonacci element");
	printf("\n3-Sum of digits");
	int option=inputCheck("\nChoose an option:","Option is illigal.Try again\n",1,3);
	
	if(option==1)
		displayPrime();
	if(option==2)
		checkFibonaci();
	if(option==3)
		sumOfDigit();
		
	  }while(1);
}
int main() {
  
menuOption();
  
  
  return 0;
}

