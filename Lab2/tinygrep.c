//
// Created by Ian on 5/3/2019.
//

#include <stdio.h>
#include <mem.h>
#include <ctype.h>

int stringCompare(char userText[], char pattern[]) {

//    todo: solve pattern with ...
// todo: pay pose a problem, since whitespace is _, . may match with _


    int pattern_length, userText_length;

    pattern_length = strlen(pattern);
    userText_length = strlen(userText);

    printf("Pattern len original\n");
    printf("%d", pattern_length);
    printf("\n");

    int countdots = 0;
    while (pattern[countdots]) {
        if (pattern[countdots] != '.') {
            break;
        }


        if (pattern[countdots] == '.') {
            countdots++;

        }

    }
    // clearning dots
    char temppattern[pattern_length];
    int tempcount = 0;
    for (int k = 0; k < pattern_length; ++k) {
        if (pattern[k] != '.') {
            temppattern[tempcount] = pattern[k];
            tempcount++;
        }
    }

    // adding null char to end of temppattern
    temppattern[tempcount] = '\0';

    //assiging new pattern without .
    pattern = temppattern;
    // assigning new length for pattern
    pattern_length = strlen(pattern);

    printf("NEW PATT\n");
    printf("%s", pattern);

    printf("Count dots: ");
    printf("%d", countdots);
    printf("\n");

    // replace whitespace with _
    int rep = 0;
    while (userText[rep]) {
        if (isspace(userText[rep])) {
            userText[rep] = '_';
        }
        rep++;
    }
    printf("%s", userText);

    if (pattern_length > userText_length) {
        return -1;
    }

    int patternCharCounted = 0;
    int indexOfFirstFound = -1;

    for (int i = 0; i < userText_length - 1; ++i) {
        printf("%d", patternCharCounted);
        if (patternCharCounted == pattern_length - 1) {
            break;
        }
        if (userText[i] == pattern[0]) {
//          patternCharCounted = patternCharCounted+1;
            for (int j = 0; j < pattern_length - 1; ++j) {
                if (patternCharCounted == pattern_length - 1) {
                    break;
                }
                printf("\nLocation:");
                printf("%d", i);
                printf("\ninitial:");

                printf("%c", userText[i]);
                printf("\n");
                printf("Pattern cmp:");
                printf("%c", pattern[j]);
                printf("\n");
                printf("Counted: ");
                printf("%d", patternCharCounted);
                printf("\n");

                if (userText[i + j] == pattern[j]) {

                    printf("%c", userText[i + j]);
                    printf("\n");
                    printf("%c", pattern[j]);
                    printf("\n");
                    indexOfFirstFound = i;
                    patternCharCounted = patternCharCounted + 1;

                }
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
    printf("patterncount\n");
    printf("%d", patternCharCounted);
    printf("\n");
    printf("Patn Leng: %d", pattern_length);


    if (patternCharCounted == pattern_length - 1) {
        printf("Found\n");

        //minus the . if there is any to move the index of the match by x amount
        printf("Matches at index: %d", indexOfFirstFound - countdots);
    } else {
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
