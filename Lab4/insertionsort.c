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

void *insert_to_list(Node *head, Node *new_node);

Node *print_list(Node *head, char *text);

int checkError(char word2[]);


int main() {

    char userIn[SIZE];
    int errorRrt = 0;
    Node *head = NULL;
    do {

        Node *new_node;
        Node *pointerToNode = NULL;
        do {
            printf("Enter a character not more then 32 characters");
            fgets(userIn, SIZE, stdin);
            userIn[strcspn(userIn, "\r\n")] = 0;
            errorRrt = checkError(userIn);
            if(errorRrt==2){
                break;
            }

            printf("\nReturn error %d\n", errorRrt);
        } while (errorRrt > 0);

        new_node = createNode(userIn);
        head = insert_to_list(head, new_node);


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
void *insert_to_list(Node *head, Node *new_node) {
    if (head == NULL) {
        return new_node;
    }

//    Node *temp1 = head;
//    while (temp1->next != NULL)
//        temp1 = temp1->next;
//    temp1->next = new_node;

    Node *temp = head;
    int fail = 0;
    int firstinLine = 0;
    Node *previous = head;
    while (temp != NULL) {

        printf("\n%s ", (char *) temp->data);

        if (strcmp((const char *) new_node->data, (const char *) temp->data) < 0) {

            if(firstinLine==0){
                new_node->next = head;
                head = new_node;

                fail = fail + 1;
            }else{
                previous->next = new_node;
                new_node->next = temp;
                fail = fail + 1;
            }



            break;

        }
        previous = temp;
        temp = temp->next;
        firstinLine = firstinLine+1;

    }
    printf("FAIL:%d", fail);
    if (fail == 0) {
        Node *tempta = head;
        while (tempta->next != NULL)
            tempta = tempta->next;
        tempta->next = new_node;
    }
    printf("\nDATA IN LIST\n");
    Node *tempp = head;
    while (tempp != NULL) {
        printf("%s ", (char *) tempp->data);
        tempp = tempp->next;
        printf("\n");
    }

    printf("\n");

//    new_node->next = head;
    return head;
}


int checkError(char word2[]) {
    if (strcmp(word2, "***") == 0) {
        return 2;
    }
    if (strlen(word2) > 32) {
        return 1;
    }
    for (int i = 0; i < strlen(word2); i++) {

        printf("Len%d ",strlen(word2));
        printf("%d ",word2[i]);

        //todo
        if (word2[i] != 39 && word2[i] != 45 && word2[i] != 32 && (!isalpha(word2[i]))) {

            return 1;
        }
    }
    return 0;
}