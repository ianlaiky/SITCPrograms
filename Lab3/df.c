#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 12
#define MAX_ROUNDS 7

int checkError(char *text)
{
    if (strlen(text) > 12)
    {
        return 1;
    }

    for (int i = 0; i < strlen(text); i++)
    {
        if (!isalpha(text[i]))
        {
            return 1;
        }

        else if (isspace(text[i]))
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    char wordInput[MAX_LENGTH], underScore[MAX_LENGTH], guessInput;
    int i, j, len, roundLeft = MAX_ROUNDS, winCounter = 0, counter = 0, currentRound = 0, flag = 0;

    do
    {
        printf("Player 1, please enter a word up to %d letters:\n", MAX_LENGTH);
        scanf("%s", &wordInput);
        len = strlen(wordInput);
        j = checkError(wordInput);
    } while (j > 0);

    for (i = 0; i < strlen(wordInput); i++)
    {
        wordInput[i] = tolower(wordInput[i]);
    }

    for (i = 0; i < strlen(wordInput); i++)
    {
        for (counter = 0; counter < len; counter++)
        {
            underScore[counter] = '_';
        }
        underScore[len] = '\0';

        for (counter = 0; counter < 19; counter++)
        {
            if (winCounter == len)
            {
                printf("\n%s\n", &wordInput);
                printf("Player 2 Wins.\n");
                break;
            }

            if (currentRound == MAX_ROUNDS)
            {
                printf("\nThe word was: %s\n\n", wordInput);
                printf("Player 1 Wins.\n");
                break;
            }

            printf("\n%s\n", underScore);
            printf("\nPlayer 2, You have %d chances left, please enter a letter:\n", roundLeft);
            scanf(" %c", &guessInput);
            guessInput = tolower(guessInput);

            for (i = 0; i < len; i++)
            {
                if (wordInput[i] == guessInput)
                {
                    underScore[i] = guessInput;
                    flag++;
                    winCounter++;
                }
            }

            if (flag == 0)
            {
                currentRound++;
                roundLeft--;
            }

            flag = 0;
        }
        return 0;
    }
}

