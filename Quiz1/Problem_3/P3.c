# include<stdio.h>


int main(){
    char x[64];
    long int *ptr;                  //pointer declaration
    ptr = (long int *)x ;           //Initialize ptr to point to arr x with typecasting its value to int 
    for(int i=0; i<8; i++){
        long int num;
        printf("enter integer %d : ",i+1 );
        scanf("%ld",&num);
        *ptr = num;
        ++ptr;
    }
    ptr = (long int *)x;            //reset the pointer
    for(int i=0; i<8; i++){
        printf("%ld \n" ,*ptr);
        ++ptr;
    }
    return 0;
}
