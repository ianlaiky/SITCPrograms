#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 32
#define QUIT "***"

struct node
{
    char *data[SIZE];
    struct node *next;
};

typedef struct node Node;
typedef struct node *NodePointer;

void insertIntoLinkedList(char[], NodePointer *);
void displayLinkedList(NodePointer);

int main()
{
    char word[SIZE];
    int flag = 0;
    NodePointer head = NULL;

    while (flag != 2)
    {
        do
        {
            printf("Enter a word (Not more than %d characters):\n", SIZE);
            scanf("%s", &word);
            flag = checkError(word);
            if (flag == 2)
            {
                return 0;
            }
        } while (flag > 0);

        for (int i = 0; word[i]; i++)
        {
            word[i] = tolower(word[i]);
        }
        insertIntoLinkedList(word, &head);
        displayLinkedList(head);
    }
    return 0;
}

void insertIntoLinkedList(char word2[], NodePointer *head2)
{
    NodePointer newNode = NULL;
    NodePointer previous = NULL;
    NodePointer current = *head2;
    newNode = malloc(sizeof(Node));

    if (NULL != newNode)
    {
        strcpy(newNode->data, word2);
        while (NULL != current && strcmp(word2, current->data) > 0)
        {
            previous = current;
            current = current->next;
        }
        if (NULL == previous)
        {
            newNode->next = current;
            *head2 = newNode;
        }
        else
        {
            previous->next = newNode;
            newNode->next = current;
        }
    }
}

void displayLinkedList(NodePointer current)
{
    if (current == NULL)
    {
        printf("\nThe linked list is empty.\n\n");
        return;
    }
    printf("\nCurrent linked list items:\n");
    while (current != NULL)
    {
        printf(">%s\n", current->data);
        current = current->next;
    }
    printf("\n");
}

int checkError(char word2[])
{
    if (strcmp(word2, QUIT) == 0)
    {
        return 2;
    }
    if (strlen(word2) > 32)
    {
        return 1;
    }
    for (int i = 0; i < strlen(word2); i++)
    {
        if (word2[i] != 39 && word2[i] != 45 && (!isalpha(word2[i])))
        {
            return 1;
        }
    }
    return 0;
}