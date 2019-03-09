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

//    for (int i = 0; i < strlen(userText)-1; ++i) {
//        printf("%c",userText[i]);
//
//    } for (int i = 0; i < strlen(pattern)-1; ++i) {
//        printf("%c",pattern[i]);
//    }

    for (int i = 0; i < strlen(userText); ++i) {

    }


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
//
//    char *buff = "this is a test string";
//    char subbuff[5];
//    memcpy( subbuff, &buff[10], 4 );
//    subbuff[4] = '\0';
//    puts(subbuff);



    puts("Enter input: ");
    fgets(userText, 255, stdin);

    puts("Enter Pattern");
    fgets(pattern, 255, stdin);


//    puts("Should the match be case sensitive? Yes/No");
//    fgets(caseSensitive,30,stdin);





    stringCompare(userText, pattern);


    return 0;

}
