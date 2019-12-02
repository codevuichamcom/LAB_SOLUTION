#include <stdio.h>
#include <limits.h>

int getInt(char error[], int min, int max){
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

int main() {
	int n,i,Tc=0,Tl=0,c;
	printf("Sum Even Old program");
	printf("\nEnter a number of element n=");
	n=getInt("Enter again!!!\nEnter a number of element n=",1,INT_MAX);
	printf("Input element:\n");
	for(i=0;i<n;i++){
		printf("\tElement %d=",i);
		c=getInt("Enter again!!\n\tElement =",0,INT_MAX);
		if(c%2==0)
			Tc+=c;
		else
			Tl+=c;
	}
	printf("Sum of Even=%d",Tc);
	printf("\nSum of Old=%d\n",Tl);
  
  
  
  
  return 0;
}

