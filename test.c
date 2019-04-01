//
// Created by Ian on 5/3/2019.
//
#include <stdio.h>
#include <mem.h>


int main() {
    FILE *f;

    f = fopen("data.txt","a+");

    if(f==NULL){
        printf("Could not open");
        return 1;
    }
    int account;
    printf("? ");
    scanf("%d",&account);

    while(account!=0){
        char name[255];
        float balance;

        scanf("%19s%f",name,&balance);
        printf("%s",name);
        printf("%f",balance);
        fprintf(f,"\n%d %s %f",account,name,balance);

        printf("? ");
        scanf("%d",&account);

    }







    fclose(f);

    return 0;
}