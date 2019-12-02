#include <stdio.h>
#include <limits.h>
#include <float.h>

double getDouble(double min, double max,char err[]){
    double num;
    int check;
    char c;
    do{
        check=scanf("%lf%c", &num, &c);//Returns the value of an integer
        if(check!=2||c != '\n' || num<min || num>max){
           	printf("%s",err);
            fflush(stdin);//Delete buffer
            check=0; //input is a character
        }
        else{
            check=1; //input is a number
        }
    }while(check==0);
    return num;
}

int getInt(int min, int max,char err[]){
    int num;
    int check;
    char c;
    do{
        check=scanf("%d%c", &num, &c);//Returns the value of an integer
        if(check!=2||c != '\n' || num<min || num>max){
           	printf("%s",err);
            fflush(stdin);//Delete buffer
            check=0; //input is a character
        }
        else{
            check=1; //input is a number
        }
    }while(check==0);
    return num;
}

void NhapMang(double a[],int n){
	for(int i=0;i<n;i++){
		printf("Element[%d]=",i);
		a[i]=getDouble(-DBL_MAX,DBL_MAX,"Enter element again: ");
	}
}
void timMin(double a[], int n){
	double min=a[0];
	for(int i=1;i<n;i++){
		if(a[i]<min)
			min=a[i];
	}
	for(int i=0;i<n;i++){
		if(a[i]==min){
			printf("The smallest element:%g-Its position: %d\n",min,(i+1));
		}
	}
}
int main(){
	int n;
	printf("Please enter size of array: ");
	n=getInt(1,INT_MAX,"Enter again\nPlease enter size of array:");
	double a[n];
	NhapMang(a,n);
	timMin(a,n);


	return 0;
}

