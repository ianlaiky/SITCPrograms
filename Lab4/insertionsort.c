#include <stdio.h>
#include <stdlib.h>

typedef struct node_struct {
    int data;
    struct node_struct *next;
} Node;

Node *search_list(Node *head, int target);

int main() {
    Node *head = NULL;
    Node *temp;

    Node node1 = {15, NULL};
    Node node2 = {10, NULL};
    Node node3 = {50, NULL};
    node1.next = &node2;
    node2.next = &node3;

    printf("Node1 data = %d\n", node1.data);
    printf("Node1 next = %d\n", node1.next);

    Node *node_ptr = &node1;
    node_ptr = node_ptr->next;
    printf("node 2 data = %d\n", node_ptr->data);

    temp = search_list(head, 10);
    printf("Node %d found at %p\n", 10, temp);

    return 0;
}

Node *search_list(Node *head, int target) {
    Node *temp = head;
    while (temp != NULL && temp->data != target)
        temp = temp->next;
    return temp;
}