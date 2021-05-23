#include <stdio.h>                      
#include <inttypes.h>                   

int32_t long_add(int32_t , int32_t, int32_t, int32_t);         
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
    printf("%d\n", long_add(a , b , c , d));       
    return 0;
}