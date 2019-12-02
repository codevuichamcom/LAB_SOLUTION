#include <stdio.h>
#include <math.h>
#include <limits.h>
int n;
int isSquareNumber(int n){
	if(n<=0)
		return 0;
	if((int)sqrt(n)*(int)sqrt(n)==n){
		return 1;
	}
	return 0;
}


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
        	if(num<0){
			printf("Please enter a posotive integer!\n");
				check=0;
			}else{
				check=1; //input is a positive integer
			}
        	
            
        }
    }while(check==0);
    return num;
	
}

void fun1(){
	printf("Check square Number Program\n");
		n=inputCheck("Enter positive integer n = ","Please enter a posotive integer!\n",INT_MIN,INT_MAX);
		
}
int a=0;
void fun2(){
	if(isSquareNumber(n)){
			a=(int)sqrt(n);
	}else
		a= -1;
			
}
void fun3(){
	if(a!=-1){
		printf("%d is a square number %d = %d x %d\n",n,n,a,a);
	}else{
		printf("%d is not a square number.\n",n);
	}
	
	printf("Press any key to continue.\n");
	char c = getchar();
	printf("\n");
}


int main() {
	int n;
	while(1){
		fun1();
		fun2();
		fun3();
	}
		

  
  
  
  return 0;
}

