#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define FILELOCATION "CSV Format\\A Words.csv"
#define MIN_LEVEL 1
#define MAX_LEVEL 10
#define MAX_LENGTH 256

typedef struct word_node
{
    char word[MAX_LENGTH];
    int index;
    struct word_node *next;
} WORD_NODE;

WORD_NODE *insertHead(WORD_NODE *head, WORD_NODE *new_node)
{
    new_node->next = head;
    return new_node;
}

void deleteList(WORD_NODE **head)
{
    WORD_NODE *current = (*head);
    WORD_NODE *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

int insertWordIntoList(WORD_NODE **head, int length)
{
    FILE *f;
    char filename[MAX_LENGTH];
    char guessword[MAX_LENGTH];
    char name[256] = FILELOCATION;
    int index = 0;

    for (int i = 65; i <= 90; i++)
    {
        name[11] = (char)i;
        strcpy(filename, name);
        printf("%s",filename);
        f = fopen(filename, "r");

        if (f == NULL)
        {
            printf("Error, file cannot be found.\n");
            return 0;
        }

        while (!feof(f))
        {
            fscanf(f, "%s", guessword);

            if (strlen(guessword) == length)
            {
                WORD_NODE *new_node = (WORD_NODE *)malloc(sizeof(WORD_NODE));
                strcpy(new_node->word, guessword);
                new_node->index = index;
                new_node->next = NULL;
                (*head) = insertHead((*head), new_node);
                index++;
            }
        }
        fclose(f);
    }

    return 1;
}

int lengthOfList(WORD_NODE *head)
{
    WORD_NODE *cur = head;
    int size = 0;

    while (cur != NULL)
    {
        size++;
        cur = cur->next;
    }
    return size;
}

char *getWordFromList(WORD_NODE *head)
{
    srand(time(NULL));

    int index = rand() % lengthOfList(head) + 1;
    WORD_NODE *temp = head;

    while (temp != NULL)
    {
        if (temp->index == index)
            return temp->word;
        temp = temp->next;
    }
    return "\0";
}

void initOutput(char player1[], char output[])
{
    for (int i = 0; i < strlen(player1); i++)
        *(output + i) = '_';
}

int outputLetters(char player1[], char output[])
{
    int lettersLeft = strlen(player1);

    for (int i = 0; i < strlen(player1); i++)
    {
        if (*(output + i) != '_')
            lettersLeft--;
    }

    printf("%i letters left to guess\n", lettersLeft);

    for (int i = 0; i < strlen(player1); i++)
        printf("%c ", *(output + i));

    printf("\n");

    return lettersLeft;
}

int checkLetter(char player1[], char player2, char output[])
{
    int count = 0;

    if (ispunct(player2) || isspace(player2) || isdigit(player2))
        return 0;

    player2 = tolower(player2);

    for (int i = 0; i < strlen(player1); i++)
    {
        if (*(player1 + i) == player2)
        {
            *(output + i) = player2;
            count = 1;
        }
    }
    if (count)
        return 1;
    return 0;
}

void main()
{
    WORD_NODE *head = NULL;
    int length, incorrectGuess = 0, lettersLeft = 0, currentDifficulty;
    char word[MAX_LENGTH], output[MAX_LENGTH], player2 = ' ';

    printf("Enter number between %d - %d:\n", MIN_LEVEL, MAX_LEVEL);

    while (1)
    {
        scanf("%d", &length);
        currentDifficulty = length;
        if (length > 0 && length <= 10)
            break;
        else
            printf("Error. Please enter number between %d - %d:\n", MIN_LEVEL, MAX_LEVEL);
    }

    if (insertWordIntoList(&head, length) == 0)
    {
        return;
    }

    strcpy(word, getWordFromList(head));

    initOutput(word, output);

    system("cls");

    while (incorrectGuess < currentDifficulty)
    {
        printf("You have %i guesses left\n\n", currentDifficulty - incorrectGuess);

        lettersLeft = outputLetters(word, output);

        if (lettersLeft == 0)
            break;

        printf("\nPlease input 1 letter to guess:\n");
        scanf(" %c", &player2);

        system("cls");

        printf("Letter guessed: %c\n", player2);
        if (!checkLetter(word, player2, output))
        {
            incorrectGuess++;
            printf("You have guessed a letter wrongly!\n\n");
        }
        else
            printf("You have guessed a letter correctly!\n\n");
    }

    printf("The word is: %s\n", word);

    if (incorrectGuess == currentDifficulty)
        printf("\nYou lose!");
    else
        printf("\nYou win!");

    deleteList(&head);
}