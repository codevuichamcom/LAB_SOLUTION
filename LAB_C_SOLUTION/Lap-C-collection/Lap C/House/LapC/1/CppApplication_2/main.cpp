

#include <cstdlib>

using namespace std;
int getInt(int min, int max){
    int num;
    int check;
    char c;
    do{
        printf("Enter size of array: ");
        check=scanf("%d%c", &num, &c);//Returns the value of an integer
        if(c != '\n' || num<min || num>max){
            printf("The number of element size can only between 1-100\n");
            fpurge(stdin);//Delete buffer
            check=0; //input is a character
        }
        else{
            check=1; //input is a number
        }
    }while(check==0);
    return num;
}

int getElement(int i){
    int num;
    int check;
    char c;    
        do{
            printf("Input a[%d]: ", i++);
            check = scanf("%d%c", &num, &c);//Returns the value of an integer
            if(c !='\n' || check==0){
                printf("Integer number can not contains any letters\n");
                fpurge(stdin);//Delete buffer
                check=0; //input is a character
                i--;
            }
            else{
                check=1;   //input is a number
            }
        }while(check == 0);
        return num;
}

void enter_Array(int *arr, int size){
    for(int i=0;i<size;i++){
        int temp = getElement(i); //check element
            arr[i] = temp;
    }
}


//show array on screen
void display(int *arr, int size){
    for(int i=0;i<size;i++){
        printf("%3d", arr[i]);
    }
    printf("\n");
}

void deletePosition(int *arr, int &size, int pos){
    for(int i=pos;i<size;i++){ //delete location
        arr[i]=arr[i+1];
    }
    size--;
}

void deleteElement(int *arr, int &size){
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(arr[i]==arr[j]){
                deletePosition(arr,size,j); //delete first location
                j--;
            }
        }
    }
}
int main(int argc, char** argv) {
    int size=getInt(1,100);
    int *arr = (int*) calloc(size,sizeof(int));
    enter_Array(arr,size);
    printf("Array old is: \n");
    display(arr,size);
    printf("Array is: \n");
    deleteElement(arr,size);
    display(arr,size);
    return 0;
}

