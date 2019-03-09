//
// Created by Ian on 9/3/2019.
//

#include <stdio.h>
#include <mem.h>
#include <ctype.h>


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








//    for (int i = 0; i < strlen(userText)-1; ++i) {
//        printf("%c",userText[i]);
//
//    } for (int i = 0; i < strlen(pattern)-1; ++i) {
//        printf("%c",pattern[i]);
//    }
//
//    for (int i = 0; i < strlen(userText); ++i) {
//
//    }


    printf("\n");

    userText[strcspn(userText, "\r\n")] = 0;
    pattern[strcspn(pattern, "\r\n")] = 0;

    puts(userText);
    puts(pattern);


    int pattern_length, userText_length;

    pattern_length = strlen(pattern);
    userText_length = strlen(userText);

    puts("Length of pattern: ");
    printf("%d", pattern_length);
    printf("\n");

//    char *ret;
//
//
//    printf("%d",strlen(pattern));

//    ret = strstr(userText, pattern);
//    puts("Match");
//    puts(ret);

    int bool = 0;
    int boolIndex;

    for (int i = 0; i < userText_length; ++i) {

        if(bool==1){
            break;
        }

        char subbuff[pattern_length];
        memcpy(subbuff, &userText[i], (size_t) pattern_length);
//        puts("Substring");
//        puts(subbuff);

//      handle .
        char dotsbuffer[pattern_length];
        for (int j = 0; j < strlen(subbuff); ++j) {


            if(pattern[j]=='.'){
                dotsbuffer[j]='.';
            }else{
                dotsbuffer[j]=subbuff[j];
            }
        }
//        puts("NEW DORTS SHIT");
//        printf("%s",dotsbuffer);

        char *ret;
        ret = strstr(dotsbuffer, pattern);
//        puts("Match");
//        printf("%s",ret);
//        puts("-----------");
        if (ret != NULL) {



            puts("Index position");
            printf("%d", i);
            printf("\n");

            bool=1;
            boolIndex = i;
        }


    }


    if(bool==1){
        printf("Matches at position %d",boolIndex);

    }


    return 0;

}
