#include <stdio.h> 
#include <stdlib.h> 

int main(int argc, char *argv[]){

    printf("There are %d arguments.\n", argc); //argc is argument count, which is the number of strings pointed to by argv.
    for (int i = 0; i < argc; i++) {
        printf("%s\n", argv[i]); //argv is the argument vector, and each element is an argument.
    }

    
    return 0;
}