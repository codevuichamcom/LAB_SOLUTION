#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <malloc.h>

int inputCheck(int min, int max){
    int num;
    int check;
    char c;
    do{
        check=scanf("%d%c", &num, &c);//Returns the value of an integer
        if(check!=2||c != '\n' || num<min || num>max){
           	printf("Please enter a positive integer: ");
            fflush(stdin);//Delete buffer
            check=0; //input is a character
        }
        else{
            check=1; //input is a number
        }
    }while(check==0);
    return num;
}
int *NhapMang(int *a, int *n){
	printf("Dynamic memory allocation\n");
		printf("Please enter size of array: ");
		 *n=inputCheck(1,INT_MAX);
		a=(int *)calloc((*n),sizeof(int));
		for(int i=0;i<(*n);i++){
			printf("Enter element[%d]:",i);
			a[i]=inputCheck(INT_MIN,INT_MAX);
		}
	return a;
}
void display(int a[], int n){
	for(int i=0;i<n;i++){
		printf("%d\t",a[i]);
	}
}
void sortByAscending(int a[], int *n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]>a[j]){
				int temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	printf("The array sorted in ascending:\n");
	display(a,n);
}
void sortByDescending(int a[], int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]<a[j]){
				int temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	printf("\n\nThe array sorted in decending:\n");
	display(a,n);
}

int main(){
	int *a, n;
	a=NhapMang(a,&n);
	sortByAscending(a,n);
	sortByDescending(a,n);


	return 0;
}

