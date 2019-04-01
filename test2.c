//
// Created by Ian on 5/3/2019.
//
#include <stdio.h>
#include <mem.h>


int main() {
    FILE *f;

    f = fopen("data.txt", "a+");

    if (f == NULL) {
        printf("Could not open");
        return 1;
    }

    while (!feof(f)) {

        int account;
        char name[255];
        double balance;
        fscanf(f, "%d%19s%lf", &account,name,&balance);



        printf("\n%d\t%s\t%f",account,name,balance);
    }
    int accounter = 12;
    char namey[]="micth";
    double balanmcee = 12.3;


    fprintf(f,"\n%d %s %f",accounter,namey,balanmcee);

    fclose(f);

    return 0;
}