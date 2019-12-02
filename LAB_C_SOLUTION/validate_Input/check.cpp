#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int check(){
	int check=0;
	char s[11];//do kieu int bang hon 2 ty nen toi da la 10 ki tu so nhap vao
	int i=0;
	char c;
	do{
		
		while((c=getchar())!='\n'){//nhap tung ki tu tu ban phim
			if(isdigit(c)||(i==0&&c=='-')){
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
		if(s[0]=='-'&&(!isdigit(s[1]))){
			i=0;
			check=0;
			printf("Enter again.\n");
			fflush(stdin);
		}
	}while(check==0);
	
	int n=atoi(s);//chuyen xau sang so
	return n;
	
}

int main(){
	
	int n=check();
	printf("%d",n);


	return 0;
}

