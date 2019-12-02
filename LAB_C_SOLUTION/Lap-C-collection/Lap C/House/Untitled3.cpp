#include <stdio.h>
#include <limits.h>
int getInt(int min, int max) {
	int num;
	char term;
	int k;
	do {
		k = scanf("%d%c", &num, &term);
		if (term != '\n') {
			printf("Please enter input is integer number: ");
			fflush(stdin);
		}
		else {
			return num;
		}
	} while (1);
}

void menu(){
	printf("1-The first primes\n");
	printf("2-Fibonacci element\n");
	printf("3-Sum of digits");
}

void firstPrimes(int num){
	int i, j, isPrime; //isPrime is used as flag variable
    /* Find all Prime numbers between 1 to n */
    for(i=2; i<=num; i++)
    {
        /* Assume that the current number is Prime */
        isPrime = 1; 
 
        /* Check if the current number i is prime or not */
        for(j=2; j<=i/2; j++)
        {
            /*
             * If i is divisible by any number other than 1 and self
             * then it is not prime number
             */
            if(i%j==0)
            {
                isPrime = 0;
                break;
            }
        }
 
        /* If the number is prime then print */
        if(isPrime==1)
        {
            printf("%-3d ", i);
        }
    }
}

int checkFibonacci(int num){
	int prv, pre, trm;
 	if((num==0)||(num==1))
   	printf("\nIt's is a Fibonacci term\n",num);
 	else
 	{
   		prv = 0;
   		pre = 1;
   		trm = prv + pre;
   		while(trm < num)
   	{
    	prv = pre;
     	pre = trm;
     	trm = prv + pre;
   	}
   		if(trm == num)
     printf("\nIt's is a Fibonacci term\n",num);
   else
     printf("\nIt's is not a Fibonacci term\n",num);
 	}
 }

void sumDigits(int num){
	int remainder,sum=0,temp;
	temp = num;
		while (num != 0){
		remainder = num%10;
		sum = sum + remainder;
		num = num/10;	
		}
	printf("Sum of it's digit: %d\n",sum);
}

void option() {
    int select;
    int check = 1;
    int num;
    do {
        //fpurge(stdin);
        //fflush(stdin);
        printf("\nChoose an option: ");
        select = getInt(1,3);
        //fpurge(stdin);
        
        switch (select) {
            case 1:
            {
            	printf("Number of primes: ");
            	do{
            		num = getInt(INT_MIN,INT_MAX);
            		if(num < 1 || num > 50){
            			printf("Range of input must be (1-50): ");
            			fflush(stdin);
            		}
            	}while(num < 1 || num > 50);
                	firstPrimes(num);
                	printf("\n");
                	menu();
                	break;
            		
            }
            case 2:
            {
                printf("Number testd: ");
                do{
            		num = getInt(INT_MIN,INT_MAX);
            		if(num < 0 || num > 1000){
            			printf("Range of input must be (1-1000): ");
            			fflush(stdin);
            		}
            	}while(num < 0 || num > 1000);
                	checkFibonacci(num);
                	printf("\n");
                	menu();
                	break;
            }
            case 3:
            {
                printf("Enter an integer: ");
                num = getInt(INT_MIN,INT_MAX);
                sumDigits(num);
                printf("\n");
                menu();
                break;
            }
            default:
                check = 0;
                return;
        }
        if(!check) {
            break;
        }
    } while (1);
}

main(){
	menu();
	option();
}
 
