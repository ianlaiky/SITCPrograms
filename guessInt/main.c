#include <stdio.h>

#define maxGuess 6

int main() {

    int player2Round = maxGuess;
    int player1No;

    // do while loop to check for out of range values
    do {
        printf("Player 1, enter a number between 1 and 1000:");

        scanf("%d", &player1No);


        if (player1No > 1000 || player1No < 0) {
            printf("That number is out of range.");
        }

    } while (player1No > 1000 || player1No < 0);


    int player1wins = 0;

    // second while loop that repeats if guesses is above 10
    while (player2Round > 0) {
        int player2Guess;
        printf("Player 2, you have %d guesses remaining.\n", player2Round);
        printf("Enter your guess\n");
        scanf("%d", &player2Guess);

        // out of range checking
        if (player2Guess > 1000 || player2Guess < 1) {
            continue;
            // if second player guess is higher then first player input
        } else if (player2Guess > player1No) {
            printf("Too high.\n");
            player2Round = player2Round - 1;
            // if second player guess is smaller then first player input
        } else if (player2Guess < player1No) {
            printf("Too low.\n");
            player2Round = player2Round - 1;

            // player 2 wins condition
        } else if (player2Guess == player1No) {
            printf("Player 2 wins.\n");
            player1wins = 1;
            break;
        }


    }

    // if player 2 did not manage to win
    if (player1wins == 0) {
        printf("Player 1 wins.");
    }

    return 0;


}