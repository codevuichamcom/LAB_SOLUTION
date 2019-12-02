#include <stdio.h>
#include <limits.h>



int inputCheck(char msg[], char error[], int min, int max){
	int check, num;
	char c;
	do{
		printf("%s",msg);
		check=scanf("%d%c", &num, &c);//Returns the value of an integer
		fflush(stdin);
        if(check!=2||c != '\n' || num<min || num>max){
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

int main(){
	
	
	int j,i;
	int n=inputCheck("Enter the size of an array\n","Enter again!!!\n",1,100);
	int a[n];
	
	printf("\nEnter the elements of the array\n");
	for(i=0;i<n;i++){
		a[i]=inputCheck("","Enter again!!\n",INT_MIN,INT_MAX);
	}
	
	printf("\n\nArray elements: \n");
	for(i=0;i<n;i++){
		printf("%d\t",a[i]);
	}
	int max=a[0];
	
	printf("\n\nArray maximum value:\n");
	for(i=1;i<n;i++){
		if(a[i]>max)
			max=a[i];
	}
	printf("The max is %d",max);
	printf("\n\nArray even values:\n");
	for(i=0;i<n;i++){
		if(a[i]%2==0){
			printf("%d\t",a[i]);
		}
	}

	return 0;
}

