#include <stdio.h>
#include <math.h>
#include <limits.h>

float checkPrice(float min, float max){
    float num;
    int check;
    char c;
    do{
        check=scanf("%f%c", &num, &c);//Returns the value of an integer
        if(check!=2||c != '\n' || num<=min || num>max){
           	printf("Please enter again!!!\n\tEnter a real number: ");
            fflush(stdin);//Delete buffer
            check=0; //input is a character
        }
        else{
            check=1; //input is a number
        }
    }while(check==0);
    return num;
}

int checkInVi(int min, int max){
    int num;
    int check;
    char c;
    do{
        check=scanf("%d%c", &num, &c);//Returns the value of an integer
        if(check!=2||c != '\n' || num<min || num>max){
           	printf("Please enter again!!!\n\tEnter a positive number: ");
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
	int packetSmall=50, packetBig=200;//suc chua cua hop to, nho
	float priceSmall, priceBig,price;
	int n, small=0,big=0;
	printf("What is the cost of a small package (indolars)?");
	priceSmall=checkPrice(0.0,500.0);
	
	printf("What is the cost of a large package (indolars)?");
	priceBig=checkPrice(0.0,500.0);
	
	printf("How many invitations are you sending out? ");
	n=checkInVi(1,10000);
	
	if(priceSmall*packetBig/packetSmall<priceBig){
		small=ceil((float)n/packetSmall);
	}else{
		big=(n/packetBig);
		int remain =n%packetBig;
			
		if(ceil((float)(remain)/packetSmall)*priceSmall< priceBig){
			small= ceil((float)(remain)/packetSmall);
		}
		else{
			big=big+1;
		}
	}
	price=priceSmall*small+priceBig*big;
	
	printf("\nYou should order %d small package (s).",small);
	printf("\nYou should order %d large package (s).",big);
	printf("\nYour cost for invatation will be $%.2f.",price);
	return 0;
}

