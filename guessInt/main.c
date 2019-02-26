#include <stdio.h>
int main() {

    int player2Round = 10;
    int player1No;


    do{
        printf("Player 1, enter a number between 1 and 1000:");
        scanf("%d",&player1No);

        if (player1No>1000||player1No<0){
            printf("That number is out of range.");
        }

    }while(player1No>1000 || player1No <0);


    int player1wins = 0;



    while(player2Round>0) {
        int player2Guess;
        printf("Player 2, you have %d guesses remaining.\n", player2Round);
        printf("Enter your guess\n");
        scanf("%d", &player2Guess);
        if (player2Guess > 1000 || player2Guess < 1) {
            continue;
        } else if (player2Guess > player1No) {
            printf("Too high.\n");
            player2Round = player2Round - 1;
        } else if (player2Guess < player1No) {
            printf("Too low.\n");
            player2Round = player2Round - 1;
        } else if (player2Guess == player1No) {
            printf("Player 2 wins.\n");
            player1wins = 1;
            break;
        }


    }



    if(player1wins==0){
        printf("Player 1 wins.");
    }

    return 0;


}