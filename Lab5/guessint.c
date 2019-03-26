//
// Created by Ian on 12/3/2019.
//

#include <stdio.h>
#include <ctype.h>
#include <mem.h>



int main() {
    int length;
    int wordlength;

    printf("Enter number between %d - %d:\n", 1, 10 );


    while (1)
    {
        scanf("%d", &length);
        wordlength = length;
        if (length > 0 && length <= 10)
            break;
        else
            printf("Error. Please enter number between %d - %d:\n", 0, 10);
    }


    return 0;
}