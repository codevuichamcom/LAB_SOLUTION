#include<stdio.h>
#include<stdlib.h>
char fileName[13] = "saveGame.txt";
FILE *file;

int chooseOption(int min, int max){
	int num;
	int check; 
	char c;
	do{
		printf("Please enter your choice:");
		check=scanf("%d%c", &num, &c);//Returns the value of an integer
		fflush(stdin);
        if(check!=2||c != '\n' || num<min || num>max){
        	printf("Wrong choice! Enter again:\n");
            fflush(stdin);//Delete buffer
            check=0; //input is a character
        }
        else{
            check=1; //input is a number
        }
    }while(check==0);
    return num;
	
}
int checkFile(){
	file = fopen(fileName,"r");
	if(!file){
		file = fopen(fileName,"w");
		fprintf(file,"%.2f",10.00);
		fclose(file);
		return 0;
	}
	return 1;
}
void getMoney(double *money){
	char buff[255];
	file = fopen(fileName,"r");
	fgets(buff,255,file);
	*money = atof(buff);
}
double randomNumber(int *num1, int *num2, int *num3){
	*num1=rand()%10;
	*num2=rand()%10;
	*num3=rand()%10;
	printf("The slot machine show: %d%d%d\n",*num1,*num2,*num3);
}
double playGame(double money){
	int num1;
	int num2;
	int num3;
	money= money -0.25;
	randomNumber(&num1,&num2,&num3);
	if (num1==num2 && num1 ==num3){
		printf("You won 10.00$\n");
		money=money+10;
	}
	else if(num1==num2 || num1==num3 || num2==num3){
		printf("You won 50 cents\n");
		money=money+0.5;
	}
	else 
	printf("You won nothing\n");
	return money;
}
void saveGame(double money){
	file= fopen(fileName,"w");
	fprintf(file, "%2f",money);
	fclose(file);
}
void cashOut(double money){
	char buff[255];
	printf("file name:%s\n",fileName);
	file=fopen(fileName,"r");
	fgets(buff,255,file);
	printf("Thank you for playing game, you end with $ %s\n",buff);
	fclose(file);
	
	remove(fileName);
}
void showMenu(){
	printf("1 2 3");
}
int main(){
	double money=10;
	int option;
	int condition = 1;
	if(checkFile() != 0){
		getMoney(&money);
	}
	do{
		printf("You have $ %.2f \n",money);
		showMenu();
		option = chooseOption(1,3);
		switch (option){
			case 1:
				money =playGame(money);
				break;
			case 2:
				saveGame(money);
				printf("Save successfully\n");
				break;
			case 3:
				cashOut(money);
				condition=0;
				break;
		}	
	}while (condition == 1);
}

