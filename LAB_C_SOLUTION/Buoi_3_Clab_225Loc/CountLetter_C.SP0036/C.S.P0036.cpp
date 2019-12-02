#include <stdio.h>
#include <string.h>



int main() {
  
  char s[100];
  printf("Enter a string: ");  
  
  scanf("%99[^\n]",s);
  
  strlwr(s);
  char ch;
  int i;
  for(ch='a';ch<='z';ch++){
  	int dem=0;
  	for(i=0;i<strlen(s);i++){
  		if(s[i]==ch)
  			dem++;
	  }
	if(dem!=0){
		printf("\t%c: %d\n",ch,dem);
	}
  }
  
  
  
  return 0;
}

