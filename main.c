#include <stdio.h>
#include "conio.h"
int main(int argc, char *argv[])
{
    int *prt,size=0;
    size=inputSizearray();
    int array[size];
    prt=array;

    pairUnpairednumber (size);
    inputElementsarray(size,prt);
    sortArray(prt,size);
    return 0;
}
int inputSizearray(){
    int size;
    do{
        printf("\Input size array >12\n");
        size=GetInt();
        printf("\n");
    }while (size<12);
    return size;
}
void inputElementsarray(int size,int *prt){
    int i;
    for (i = 0; i < size; i++){
        printf ("array [%d]=",i);
        scanf("%d",(prt+i));
    }

    printf("Array befor\n");
    for (i = 0; i < size; i++){
        printf("%d ",*(prt+i));
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
int GetInt()//Enter only numbers
{
    int k,n=0,flgS=0,c=0;
    while (1){

        k=getch();
        if ((k == '-') && (flgS == 0)){
            flgS=-1;
            putch('-');
            c++;
        }
        if ((k >= '0') && (k <= '9')){

            printf("%c",k);
            n=n*10+k-'0';
            c++;
        }
        if (k == 8){

            putch(8);
            putch(' ');
            putch(8);
            n=n / 10;
            c--;
            if (c == 0) flgS=0;
        }
        if (k == 13) break;
    }
    if (flgS == -1) n=-n;
    return n;
}
