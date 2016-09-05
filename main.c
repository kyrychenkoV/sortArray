#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include<string.h>
#include <time.h>

int inputSizearray();
void inputElementsarray(int size,int *prt);
int pairUnpairednumber(int size);
void sortArray (int *prt,int size);
int inputNumber();

int main(void)
{   srand((unsigned) time(NULL));
    int *prt,size;
    size=12;//inputSizearray();
    int array[size];
    prt=array;

    inputElementsarray(size,prt);
    pairUnpairednumber (size);
    sortArray(prt,size);

    return 0;
}
void testArraytrue(){
    srand((unsigned) time(NULL));
        int *prt,size;
        size=12;//inputSizearray();
        int array[size];
        prt=array;
}
int inputSizearray(){
    int size;
    do{
        printf("Input size array >12\n");
        size=inputNumber();
        printf("\n");
    }while (size<12);
    return size;
}
void inputElementsarray(int size,int *prt){
    int i;
    for (i = 0; i < size; i++){
        // printf ("array [%d]=",i);
        //scanf("%d",(prt+i));
        *(prt+i)=i+1;
    }
}
int pairUnpairednumber(int size){
    if(size%2==0){
        return 1;
    }
    else {
        return 0;
    }
}
void sortArray (int *prt,int size){
    int i,tmp;
    printf("Array befor\n");
    for (i = 0; i < size; i++){
        printf("%d ",*(prt+i));
    }
    if ( pairUnpairednumber(size)==1){
        for(i=0;i<size/2;i++){

            if(i%2!=0){
                tmp=*(prt+i);
                *(prt+i)=*(prt+size-i);
                *(prt+size-i)=tmp;
            }
        }
    }
    else{
        for(i=0;i<size/2;i++){
            if(i%2==0){
                tmp=*(prt+i);
                *(prt+i)=*(prt+size-i-1);
                *(prt+size-i-1)=tmp;
            }
        }
    }
    printf("\nArray after\n");
    for (i = 0; i < size; i++){
        printf("%d ",*(prt+i));
    }
}
int inputNumber(){
    char input[256];
    while (1)
    {
        printf("Input number:");
        fgets(input, 256, stdin);
        int last = strlen(input) - 1;
        input[last] = '\0';

        int i, not_digit = 0;
        for (i = 0; input[i] != '\0'; i++){
            if (!isdigit(input[i]))
            {
                not_digit = 1;
                printf ("Please enter the number! \n");
                break;
            }
        }
        if (not_digit){
            continue;
        }
        return atoi(input);
    }
}
