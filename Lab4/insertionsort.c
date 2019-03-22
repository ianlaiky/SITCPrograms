#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 32

struct node_struct
{
    char *data[SIZE];
    struct node_struct *next;
}Node;

int checkError(char word2[]);

int main() {

    char userIn[SIZE];
    int errorRrt = 0;

    do{
        printf("Enter a character not more then 32 characters");
        scanf("%s",&userIn);

        errorRrt = checkError(userIn);

        printf("\nReturn error \n%d",errorRrt);

    }while(errorRrt!=0);







    return 0;
}

int checkError(char word2[])
{
    if (strcmp(word2, "***") == 0)
    {
        return 2;
    }
    if (strlen(word2) > 32)
    {
        return 1;
    }
    for (int i = 0; i < strlen(word2); i++)
    {
        if (word2[i] != 39 && word2[i] != 45 && (!isalpha(word2[i])))
        {
            return 1;
        }
    }
    return 0;
}