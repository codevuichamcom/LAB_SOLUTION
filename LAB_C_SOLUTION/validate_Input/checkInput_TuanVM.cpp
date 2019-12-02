#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//luu y chi dung 1 ham check
//Ham check 1
int check(){
	int check=0;
	char s[11];//do kieu int bang hon 2 ty nen toi da la 10 ki tu so nhap vao
	int i=0;
	char c;
	do{
		
		while((c=getchar())!='\n'){//nhap tung ki tu tu ban phim
			if(isdigit(c)){
				s[i++]=c;//do tung ki tu vao xau
				check=1;//danh dau la dang nhap so
			}else{
				i=0;//gan lai 
				check=0;//ki tu nhap vao sai , nhap lai
				break;
			}
		}
		if(check==0){
			printf("Enter again.\n");
			fflush(stdin);
		}
		
	}while(check==0);
	int n=atoi(s);//chuyen xau sang so
	return n;
	
}

//ham check 2
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

int main(){
	
	int n=check();
	printf("%d",n);


	return 0;
}

