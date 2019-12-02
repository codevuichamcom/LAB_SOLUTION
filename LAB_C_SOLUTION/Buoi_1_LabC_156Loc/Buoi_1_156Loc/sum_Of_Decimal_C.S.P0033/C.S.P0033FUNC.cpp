#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <malloc.h>

int n;int *a;int sum;
int inputCheck(int min, int max,char msg[],char err []){
    int num;
    int check;
    char c;
    do{
    	printf("%s",msg);
        check=scanf("%d%c", &num, &c);//Returns the value of an integer
        fflush(stdin);
        if(check!=2||c != '\n' || num<min || num>max){
           	printf(err);
            fflush(stdin);//Delete buffer
            check=0; //input is a character
        }
        else{
            check=1; //input is a number
        }
    }while(check==0);
    return num;
}

void func1(){
	printf("Dynamic memory allocation\n");
	n=inputCheck(1,INT_MAX,"\tNumber of element s = ","Please enter a positive integer.\n");
}

void func2(){
	a = (int *) calloc(n, sizeof(int ));
	for(int i=0;i<n;i++){
			a[i]=inputCheck(INT_MIN,INT_MAX,"\tEnter an integer: ","Please enter positve integer\n");
		}
}

void func3(){
	sum=0;
	for(int i=0;i<n;i++){
			sum+=a[i];
	}
}

void func4(){
	printf("\tSum = %d\n",sum);
	free(a);
	printf("Press any key to continue.\n");
	char c = getchar();
}

int main(){
	while(true){
		func1();
		func2();
		func3();
		func4();
		
	}
	
	return 0;
}

