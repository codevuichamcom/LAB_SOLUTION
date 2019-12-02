#include <stdio.h>
#include <math.h>
#include <limits.h>

int isSquareNumber(int n){
	if(n<0)
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
            check=1; //input is a number
        }
    }while(check==0);
    return num;
	
}

int main() {
	int n;
	while(1){
		printf("Check square Number Program\n");
		n=inputCheck("Enter positive integer n = ","Please enter a posotive integer!\n",INT_MIN,INT_MAX);
		if(n<0){
			printf("Please enter a posotive integer!\n");
		}
		else{
			if(isSquareNumber(n)){
				printf("%d is a square number %d = %d x %d\n",n,n,(int)sqrt(n),(int)sqrt(n));
			}else{
				printf("%d is not a square number.\n",n);
			}
		}
		printf("Press any key to continue.\n");
		
		char c = getchar();
		printf("\n");
		
	}
		

  
  
  
  return 0;
}

