#include <stdio.h>

int main(){
    FILE *fptr;
    fptr = fopen("new.text" ,"w");
    char name[] = "dolly";
    fprintf(fptr ,"%s" , name);
    fclose(fptr);
    return 0;

}