//
// Created by Ian on 9/3/2019.
//

#include <stdio.h>
#include <mem.h>
#include <ctype.h>


int main() {


    char userText[255];
    char pattern[255];
    char caseSensitive;


    puts("Enter input: ");
    fgets(userText, 255, stdin);

    puts("Enter Pattern");
    fgets(pattern, 255, stdin);

    int boolCasesel = 0;
    do {
        puts("Should the match be case sensitive? Y/N");
        caseSensitive = (char) getchar();


        if (tolower(caseSensitive) == 'n') {
            for (int i = 0; userText[i]; i++) {
                userText[i] = (char) tolower(userText[i]);
            }
            boolCasesel = 1;
        } else if (tolower(caseSensitive) == 'y') {
            boolCasesel = 1;

        } else {
            printf("Invalid Character Inputted!\n");
        }

    } while (boolCasesel == 0);

    userText[strcspn(userText, "\r\n")] = 0;
    pattern[strcspn(pattern, "\r\n")] = 0;

    int pattern_length, userText_length;

    pattern_length = strlen(pattern);
    userText_length = strlen(userText);


    int bool = 0;
    int boolIndex = 0;

    for (int i = 0; i < userText_length; ++i) {

        // if substring match before, break the loop
        if (bool == 1) {
            break;
        }

        char subbuff[pattern_length];
        // substring copy
        memcpy(subbuff, &userText[i], (size_t) pattern_length);

//      handling of '.'
        char dotsbuffer[pattern_length];
        for (int j = 0; j < strlen(subbuff); ++j) {

            if (subbuff[j] == ' ') {

                dotsbuffer[j] = '_';
            } else if (pattern[j] == '.') {
                dotsbuffer[j] = '.';
            } else {
                dotsbuffer[j] = subbuff[j];
            }
        }


        char *ret;

        // checking string is in string
        ret = strstr(dotsbuffer, pattern);

        // if string found is NOT NULL
        if (ret != NULL) {

            // setting boolean value to 1
            bool = 1;

            //saving index to variable outside current scope
            boolIndex = i;
        }
    }

    if (bool == 1) {
        printf("Matches at position %d", boolIndex);

    } else {
        printf("No match.");
    }

    return 0;

}
