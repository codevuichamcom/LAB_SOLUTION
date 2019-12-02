#include<stdio.h>
#include<ctype.h>

int enterInt(int min, int max) {
	int oke ;
	int num ;
	int i;
	int cnt;
	do {
		fflush(stdin);
		char temp[11];
		cnt= 0;
		char c;
		while ((c = getchar()) =='\n') {
			printf("!!!\n");
		} 
		// c = ki tu !='\n'
		
		int checkNeg = 0;
		if (c=='-') checkNeg = 1;
		else temp[cnt++] = c;
		
		while((c=getchar()) != '\n') {
			temp[cnt++] = c;	
		} 
		
		i=0;
		num = 0;
		oke = 1;
		while (i<cnt && oke==1) {
			if (!isdigit(temp[i])) {
				cnt=0;
				printf("!!!\n");
				oke = 0;
				num = 0;
			} else {
				num = num*10+temp[i]-'0';
			}
			++i;
		}
		if (checkNeg) num = -num;
		if(num<min||num>max){
		oke=0;
	}
	}while(oke==0);
	return num;
}




int main()
{
	int n = enterInt(-10,10);
	printf("%d", n);
}
