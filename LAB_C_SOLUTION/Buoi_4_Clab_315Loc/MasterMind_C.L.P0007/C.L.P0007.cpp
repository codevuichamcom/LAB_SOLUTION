#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int getInt(int min, int max){
    int num;
    int check;
    char c;
    do{
        check=scanf("%d%c", &num, &c);//Returns the value of an integer
        if((c != ' '&&c!='\n')|| num<min || num>max){
            printf("The number you enter must in 0-5\n");
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
	printf("Welcome to MasterMind!!!");
	printf("\n\nAt each turn, you will enter your guess for the playing board.");
	printf("\nA valid has 4 values in between 0 and 5.");
	printf("\nEach guess will have each number within the guess separated by space.");
	printf("\nWhen you are ready, enter your first guess.");
	printf("\nFrom that point on, you will be told how many perfect and imperfect matches you have.");
	printf("\nAfter this message, you should guess again. You have 10 chances, good luck!\n\n");
	srand(time(NULL));
	
		  int a[4], b[4], c[4];
		  int i,j,perfect,imPerfect,turn=1;
		  clock_t start_t, end_t;
		  for(i=0;i<4;i++){
		  	a[i]=rand()%6; //create 4 number random.
		  }
		  for(i=0;i<4;i++){
		  	printf("%4d",a[i]);
		  }
		  printf("\n");
		  start_t=clock();//start count time
  
  // 1 3 -1 -1
  // 2 1 -1 -1
  	while(turn<=10){
	  		for(i=0;i<4;i++)
	  		c[i]=a[i];
	  	perfect=0;imPerfect=0;
	  for(i=0;i<4;i++){
	  	b[i]=getInt(0,5);
	  }
	  for(i=0;i<4;i++){
	  	if(c[i]==b[i]){
	  		perfect++;
	  		c[i]=-1;
	  		b[i]=-1;
		  }	
	  }

	  for(i=0;i<4;i++){//scan from head to tail to check matches value
	  	for(j=0;j<4;j++){
	  		if(c[i]==b[j]&&c[i]!=-1){//Check if the value matches and has not been counted
	  			imPerfect++;
	  			c[i]=-1;
	  			b[j]=-1;
			  }
	  			
		  }
	  }
	  printf("You have %d perfect matches and %d imperfect matches.\n",perfect,imPerfect);
	  if(perfect==4){
	  	end_t=clock();
	  	long minute=(end_t-start_t)/(60000);
	  	long second=((end_t-start_t)-minute*60000)/1000;
	  	printf("You have won the game in %d turn and %ld:%ld!!!",turn,minute,second);
	  	return 0;
	  }
	  turn++;
	}
  	
	  
	printf("Sorry you have exceeded the maximum number of future. You lose.");
  	printf("\nHere is the winning board: ");
  	
	for(i=0;i<4;i++){
  		printf("%d ",a[i]);
	}
  	
  
  
  
  
  return 0;
}

