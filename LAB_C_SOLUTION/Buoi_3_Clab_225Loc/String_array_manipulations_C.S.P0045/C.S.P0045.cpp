#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>//them thu vien de check chu


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

int isValidName(char name[] ){
	for(int i=0;i<strlen(name);i++){
		if(a[i]<'a'||a[i]>'z'&&a[i]<'A'||a[i]>'Z'{
			return 0;
		}
	}
	return 1;
}

int main() {
  int i,j,n;
  n=inputCheck("Enter the value of n: \n","Enter again!!!\n",1,50);
  char s[n][100],temp[100];
  
  printf("Enter %d names\n",n);
  for(i=0;i<n;i++){
	do{
		fflush(stdin);
		gets(s[i]);
	}while(isValidName(s[i])==0)
  	
  }
  printf("\nList input name:");
  for(i=0;i<n;i++){
  	printf("\n%d. %s",i+1,s[i]);
  }
  printf("\nList sort name:");
  for(i=0;i<n-1;i++){
  	for(j=i+1;j<n;j++){
  		if(strcmp(strlwr(s[i]),strlwr(s[j]))>0){
  			strcpy(temp,s[i]);
  			strcpy(s[i],s[j]);
  			strcpy(s[j],temp);
		  }
	  }
  }
  for(i=0;i<n;i++){
  	printf("\n%d. %s",i+1,s[i]);
  }
  
  
  
  return 0;
}

