#include <stdio.h>                      //this header file contain printf and scanf function
#include <inttypes.h>                   // this contain int64_t function

int64_t add(int64_t , int64_t);         //declaration of add function with parameter and return of type int64_t(64 bit integer) 
int main(){                             // main function
    int a, b;
    printf("Enter 1st integer : ");
    scanf("%d",&a);                     // first input
    printf("Enter 2nd integer : ");
    scanf("%d", &b);                    //second input
    printf("%ld\n", add(a , b));        //calling function add() and print the result
    return 0;
}
