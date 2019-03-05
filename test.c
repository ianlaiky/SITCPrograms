//
// Created by Ian on 5/3/2019.
//
#include <stdio.h>
#include <mem.h>


int main(){

    char *a = "abcdef";
    char b[7];
    strcpy(b, a);
    for (int i = 0; i < 3; i++)
        b[i] = b[i] + 1;
    b[3] = '\0';

    printf("%c",a[0]);



    return 0;
}