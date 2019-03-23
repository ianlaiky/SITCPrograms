//
// Created by Ian on 12/3/2019.
//

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define CMAX_LEN 13

int main() {
    int bool = 0;

    int MAX_LEN = CMAX_LEN;
    char guess[MAX_LEN];
    int triesLeft = 7;


    do {

        puts("Player 1, enter a word of no more than 12 letters:");
        fgets(guess, MAX_LEN, stdin);

        int flushOff = 0;
        for (int i = 0; guess[i]; i++) {
            if(guess[i]=='\n'){
                flushOff=1;
            }
        }
        if(flushOff==0){
            fflush(stdin);
        }


        int checkVal = -1;
        for (int i = 0; guess[i]; i++) {
            if (!isalpha(guess[i])) {
                checkVal++;
            }
        }
//        printf("%d", checkVal);

        if (checkVal == 0) {
            bool = 1;
        } else {
            puts("Sorry, the word must contain only English letters.");
        }


    } while (bool == 0);


    for (int i = 0; guess[i]; i++) {
        guess[i] = (char) tolower(guess[i]);
    }

    char p2Guess[MAX_LEN];

    guess[strcspn(guess, "\r\n")] = 0;

    for (int i = 0; i < strlen(guess); i++) {

        p2Guess[i] = '_';
    }

    p2Guess[strlen(guess)] = '\0';
//    puts("GUESSLE");
//    printf("%d",strlen(p2Guess));
//    printf("%s",p2Guess);

    int win = 0;
    do {
        char p2input;

        printf("\nPlayer 2 has so far guessed: ");

        for (int i = 0; i < strlen(p2Guess); i++) {

            printf("%c ", p2Guess[i]);
        }

        printf("\nPlayer 2, you have %d guesses remaining. Enter your next guess:", triesLeft);

        p2input = (char) getchar();
        getchar();


        int guessCorrect = 0;
        for (int i = 0; i < strlen(p2Guess); i++) {
            if (p2Guess[i] == '_') {
                if (p2input == guess[i]) {
                    p2Guess[i] = p2input;
                    guessCorrect++;
                }
            } else {
                guessCorrect++;
            }

        }


        if (guessCorrect == strlen(guess)) {
            win = 0;

            break;
        } else {
            win = 1;
            triesLeft--;
        }

    } while (triesLeft > 0);
    printf("\nPlayer 2 has so far guessed: ");

    for (int i = 0; i < strlen(p2Guess); i++) {

        printf("%c ", p2Guess[i]);
    }

    if (win == 1) {
        puts("\nPlayer 1 wins.");
    } else{
        puts("\nPlayer 2 wins.");
    }


    return 0;
}