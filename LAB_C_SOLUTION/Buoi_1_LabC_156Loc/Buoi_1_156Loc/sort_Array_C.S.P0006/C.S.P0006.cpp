#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <malloc.h>

int inputCheck(int min, int max,char msg[],char err[]){
    int num;
    int check;
    char c;
    do{
    	printf("%s",msg);
        check=scanf("%d%c", &num, &c);//Returns the value of an integer
        fflush(stdin);
        if(check!=2||c != '\n' || num<min || num>max){
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

int main(){
		printf("Dynamic memory allocation\n");
		int n=inputCheck(1,INT_MAX,"Please enter size of array:" ,"Please enter a positive integer.\n");
		int a[n];
		for(int i=0;i<n;i++){
			printf("Enter element[%d]:",i);
			a[i]=inputCheck(INT_MIN,INT_MAX,"","Please enter a positive integer.\n");
		}
		
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				if(a[i]>a[j]){
					int temp=a[i];
					a[i]=a[j];
					a[j]=temp;
				}
			}
		}
		
		//bubble sort
		for(int i=0;i<n-1;i++){
			for(int j=i; j<n-i-1;j++){
				if(a[j]>a[j+1]){
					int temp=a[j];
					a[j]=a[j+1];
					a[j+1]=temp;
				}
			}
		}
		
		printf("The array sorted in ascending:\n");
		for(int i=0;i<n;i++){
			if(i==n-1){
				printf("%d",a[i]);
			}else{
				printf("%d\t",a[i]);
			}
		}
		printf("\nThe array sorted in decending:\n");
		for(int i=n-1;i>=0;i--){
			if(i==0){
				printf("%d",a[i]);
			}else{
				printf("%d\t",a[i]);
			}
		}
	
	return 0;
}

