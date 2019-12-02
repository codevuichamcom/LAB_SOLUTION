#include <stdio.h>
#include <string.h>
#include <malloc.h>



int main() {
  
  printf("Enter a string: ");  
  char *s;//khai bao con tro
  s=(char*) calloc(0, sizeof(char));//cap phat ban dau cho mang la 0 phan tu
  int size=0;//size cua mang ban dau la 0
  while(true){
  	char c=getchar();//nhap 1 ki tu tu ban phim
  	if(c=='\n'){//neu ki tu day la phim enter thi thoat
  		break;
  	}
  	s=(char*) realloc(s, 1+size*sizeof(char));//tang them size cho mang
  	s[size++]=c;//add thêm ki tu c vao mang
	}
  
  
  
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

