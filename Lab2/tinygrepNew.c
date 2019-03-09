//
// Created by Ian on 9/3/2019.
//

#include <stdio.h>
#include <mem.h>
#include <ctype.h>


int stringCompare(char userText[], char pattern[]) {


    int pattern_length, userText_length;

    pattern_length = strlen(pattern);
    userText_length = strlen(userText);


    puts("Length of pattern: ");
    printf("%d", pattern_length);
    puts(userText);
    puts(pattern);
    printf("\n");

//    char *ret;
//    ret = strstr(userText, pattern);
//    puts(ret);



//    for (int i = 0; i < userText_length; ++i) {
//        for (int j = 0; j < pattern_length; ++j) {
//
//        }
//
//    }


}


int main() {


    char userText[255];
    char pattern[255];
    char caseSensitive[30];

    puts("Enter input: ");
    fgets(userText, 255, stdin);





    puts("Enter Pattern");
    fgets(pattern, 255, stdin);



//    puts("Should the match be case sensitive? Yes/No");
//    fgets(caseSensitive,30,stdin);





    stringCompare(userText, pattern);


    return 0;

}
