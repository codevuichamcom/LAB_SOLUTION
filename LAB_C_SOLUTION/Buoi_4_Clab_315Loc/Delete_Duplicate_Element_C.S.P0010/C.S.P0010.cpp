#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

void display(int a[], int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d\t",a[i]);
	}
}

int getInt(int min, int max,char err[]){
    int num;
    int check;
    char c;
    do{
        check=scanf("%d%c", &num, &c);//Returns the value of an integer
        fflush(stdin);
        if(check!=2||(c != ' '&&c!='\n')|| num<min || num>max){
            printf("%s",err);
            fflush(stdin);//Delete buffer
            check=0; //input is a character
        }
        else{
            check=1; //input is a number
        }
    }while(check==0);
    return num;
}

double getDouble(double min, double max,char err[]){
    double num;
    int check;
    char c;
    do{
        check=scanf("%lf%c", &num, &c);//Returns the value of an integer
        fflush(stdin);
        if(check!=2||(c != ' '&&c!='\n')|| num<min || num>max){
            printf("%s",err);
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
	
	printf("Please enter size of array:");
	int size=getInt(1,INT_MAX,"Enter a positive integer.\nPlease enter size of array:");
	int a[size];
	int i,j;
	for(i=0;i<size;i++){
		printf("Element[%d]=",i);
		a[i]=getDouble(INT_MIN,INT_MAX,"Enter an integer number: ");
	}
	printf("The original array:\n");
	display(a,size);
	
	for(int i=0;i<size;i++){
		if(a[i]==a[i+1]){
			for(int j=i;j<size;j++){
				a[j]=a[j+1];
			}
			size--;
			i--;
		}
	}
	
	
	
	
//	
//	for(i=0;i<size;i++){
//		if(a[i]==a[i+1]){
//			for(j=i;j<size;j++){
//				a[j]=a[j+1];
//			}
//			size--;
//			i--;
//		}
//		
//	}
	printf("\nThe array removing duplicate elements:\n");
	display(a,size);
	
  
  
  
  
  return 0;
}

