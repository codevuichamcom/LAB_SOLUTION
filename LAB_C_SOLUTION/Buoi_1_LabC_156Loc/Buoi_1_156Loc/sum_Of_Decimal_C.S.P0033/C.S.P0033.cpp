#include <stdio.h>
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
	while(1){
		printf("Dynamic memory allocation\n");
		int n=inputCheck(1,INT_MAX,"\tNumber of element s = ","Please enter a positive integer.\n");
		
		int *a = (int *) calloc(n, sizeof(int));
		int sum=0;
		
		for(int i=0;i<n;i++){
			a[i]=inputCheck(INT_MIN,INT_MAX,"\tEnter an integer: ","Please enter positve integer\n");
			sum+=a[i];
		}
		
		printf("\tSum = %d\n",sum);
		free(a);//giai phong bo nho
		printf("Press any key to continue.\n");
		char c = getchar();
	}
	
	return 0;
}

