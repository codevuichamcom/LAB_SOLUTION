#include <stdio.h>
#include <string.h>

void Func1(char s[]){
	printf("Enter a string: ");
  	scanf("%99[^\n]",s);
}
int letter[26];
void Func2(char s[]){
	strlwr(s); // viet hoa thanh viet thuong
	int k=0,i;
	char ch;
	for(ch='a';ch<='z';ch++){
  	int dem=0;
  	for(i=0;i<strlen(s);i++){
  		if(s[i]==ch)
  			dem++;
	  }
	letter[k]=dem;
	k++;
	}
}
void Func3(){
	char ch ='a';
	for(int i=0;i<26;i++){
		if(letter[i]!=0){
			printf("%c : %d\n",ch,letter[i]);
			
		}
		ch++;
	}
}


int main() {
  
  char s[100];
  Func1(s);
  Func2(s);
  Func3();
  
  
  
  
  return 0;
}

