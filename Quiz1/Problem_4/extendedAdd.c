#include <stdio.h>                      
#include <inttypes.h>                   

int64_t extended_add(int64_t , int64_t, int64_t, int64_t);         
int main(){                            
    int a, b, c, d;
    printf("Enter 1st integer : ");
    scanf("%d",&a);                     
    printf("Enter 2nd integer : ");
    scanf("%d", &b);                  
    printf("Enter 3nd integer : ");
    scanf("%d", &c);                   
    printf("Enter 4nd integer : ");  
    scanf("%d", &d);
    printf("%ld\n", extended_add(a , b , c , d));       
    return 0;
}