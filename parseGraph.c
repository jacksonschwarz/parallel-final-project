#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main (int argc, char **argv)
{
    int c;
    char *input = "matrix.txt";
    FILE *input_file;

    input_file = fopen(input, "r");

    int rowcount = 0;
    int colcount = 0;
    while ((c =fgetc(input_file)) != EOF )
    {
        if (isdigit(c)){
            int digit = c-48;
            if(digit > 0){
                printf("(%d, %d)   ", rowcount, colcount);                            
            }
            colcount++;
            
        }
        if(c == 10) {
            rowcount++;
            colcount = 0;
        }
    }

    fclose(input_file);


    printf("\n");

    return 0;
}
