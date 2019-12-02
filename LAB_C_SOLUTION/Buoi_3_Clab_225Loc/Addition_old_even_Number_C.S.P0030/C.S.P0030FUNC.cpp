#include <stdio.h>
#include <limits.h>


int inputCheck(char error[], int min, int max){
	int num;
	int check; 
	char c;
	do{
		check=scanf("%d%c", &num, &c);//Returns the value of an integer
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

int setSize(){
	printf("\nEnter a number of element n=");
	int n = inputCheck("Enter again!!!\nEnter a number of element n=",1,10);
	return n;
}

void setArr(int size, int arr[]){
	printf("Input element:\n");
	for(int i=0;i<size;i++){
		printf("\tElement %d=",i);
		arr[i]=inputCheck("Enter again!!\n\tElement =",0,INT_MAX);
	}
}

int getEvenSum(int arr[], int size){
	 int sum_even=0;
	for(int i=0; i<size; i++){
		if(arr[i]%2==0){
			sum_even+=arr[i];
		}
	}
	return sum_even;
	
}

int getOddSum(int arr[], int size){
	 int sum_old=0;
	for(int i=0; i<size; i++){
		if(arr[i]%2!=0){
			sum_old+=arr[i];
		}
	}
	return sum_old;
}

void ouput(int arr[], int size,int sum_even,int sum_old){
	printf("Sum of Even=%d",sum_even);
	printf("\nSum of Old=%d\n",sum_old);
}

int main() {
	printf("Sum Even Old program");
	int size=setSize();
	int arr[size];
	setArr(size, arr);
	int sum_old,sum_even;
	sum_even=getEvenSum(arr,size);
	sum_old=getOddSum(arr,size);
	ouput(arr, size,sum_old,sum_even);
  	return 0;
}
