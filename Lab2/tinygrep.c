//
// Created by Ian on 5/3/2019.
//

#include <stdio.h>
#include <mem.h>

int stringCompare(char userText[], char pattern[]) {

    int pattern_length, userText_length;

    pattern_length = strlen(pattern);
    userText_length = strlen(userText);

    if (pattern_length > userText_length) {
        return -1;
    }

    int patternCharCounted = 0;
    int indexOfFirstFound = -1;

    for (int i = 0; i <userText_length; ++i) {
        for (int j = 0; j < pattern_length; ++j) {
            if(userText[i]==pattern[j]){

            }
        }
    }




//    for (int i = 0; i < pattern_length; ++i) {
//
//        int jlocate=0;
//        for (int j = jlocate; j < userText_length; ++j) {
//
//
//
//            //problem
//            if (pattern[i] == userText[j]) {
//                jlocate=j;
//                patternCharCounted = patternCharCounted + 1;
//                if (patternCharCounted + 1 == pattern_length) {
//                    indexOfFirstFound = j - pattern_length + 2;
//                }
//                break;
//            }
//        }
//    }
//    printf("%d",patternCharCounted);
    if (patternCharCounted == pattern_length) {
        printf("Found\n");
        printf("Matches at index: %d",indexOfFirstFound);
    }else{
        printf("No Match.\n");
    }

    return 0;
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
