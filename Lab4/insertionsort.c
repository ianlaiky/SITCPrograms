#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 32

typedef struct node_struct {
    char *data[SIZE];
    struct node_struct *next;
} Node;


Node *createNode(char data[]);
Node *insert_to_list(Node *head, Node *new_node);
Node *print_list(Node *head, char *text);

int checkError(char word2[]);


int main() {

    char userIn[SIZE];
    int errorRrt = 0;

    do {

        Node *new_node;
        Node *pointerToNode = NULL;
        do {
            printf("Enter a character not more then 32 characters");
            scanf("%s", &userIn);

            errorRrt = checkError(userIn);

            printf("\nReturn error \n%d", errorRrt);
        } while (errorRrt != 0);

        new_node = createNode(userIn);
        pointerToNode = insert_to_list(pointerToNode, new_node);
//        print_list()

    } while (errorRrt != 2);


    return 0;
}

Node *createNode(char data[]) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    if (new_node != NULL) {
        strcpy((char *) new_node->data, data);
        new_node->next = NULL;
    }

}


/* print out ever eleent in the list */
Node *print_list(Node *head, char *text) {
    printf("%s: ", text);
    Node *temp = head;
    while (temp != NULL) {
        printf("%s ", (char *) temp->data);
        temp = temp->next;
    }
    printf("\n");
    return head;
}

/* insert a node at the head of the list */
Node *insert_to_list(Node *head, Node *new_node) {



    new_node->next = head;
    return new_node;
}


int checkError(char word2[]) {
    if (strcmp(word2, "***") == 0) {
        return 2;
    }
    if (strlen(word2) > 32) {
        return 1;
    }
    for (int i = 0; i < strlen(word2); i++) {
        if (word2[i] != 39 && word2[i] != 45 && (!isalpha(word2[i]))) {
            return 1;
        }
    }
    return 0;
}