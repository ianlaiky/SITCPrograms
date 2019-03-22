#include <stdio.h>
#include <stdlib.h>

typedef struct node_struct {
	int data;
	struct node_struct *next;
} Node;

Node *search_list(Node *head, int target);
Node *create_node(int data);
Node *insert_at_head(Node *head, Node *new_node);
Node *insert_at_tail(Node *head, Node *new_node);
Node *delete_node(Node *head, Node *node_ptr);
Node *print_list(Node *head, char *text);
Node *free_list(Node *head);

int main() {
	Node *head = NULL;
	Node *new_node;
	Node *temp;

	/* add one node */
	new_node = create_node(100);
	head = insert_at_head(head, new_node);
	print_list(head, "After one node");

	/* add another node */
	new_node = create_node(200);
	head = insert_at_head(head, new_node);
	print_list(head, "After two node");

	/* add another node */
	new_node = create_node(300);
	head = insert_at_head(head, new_node);
	print_list(head, "After three node");

	/* search for node 200 */
	temp = search_list(head, 200);
	printf("Node %d found at %p\n", 200, temp);

	/* delete node 200 */
	head = delete_node(head, temp);
	print_list(head, "After deleteing 200");

	/* deleting head */
	head = delete_node(head, head);
	print_list(head, "After deleteing head");

	/* search for node 400 */
	temp = search_list(head, 400);
	printf("Node %d found at %p\n", 400, temp);

	/* add at the end of the list */
	new_node = create_node(500);
	head = insert_at_tail(head, new_node);
	print_list(head, "After inserting 500 at the tail");

	head = free_list(head);
	print_list(head, "After freeing the list");
	return 0;
}

/* create a new node; returns NULL if there is not enough memory */
Node *create_node(int data) {
	Node *new_node = (Node *)malloc(sizeof(Node));
	if (new_node != NULL) {
		new_node->data = data;
		new_node->next = NULL;
	}
	return new_node;
}

/* search for the node ocntraining the target value */
Node *search_list(Node *head, int target) {
	Node *temp = head;
	while (temp != NULL && temp->data != target)
		temp = temp->next;
	return temp;
}

/* insert a node at the head of the list */
Node *insert_at_head(Node *head, Node *new_node) {
	new_node->next = head;
	return new_node;
}

Node *insert_at_tail(Node *head, Node *new_node) {
	if (head == NULL) {
		return new_node;
	}
	Node *temp = head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new_node;
	return head;
}

/* delete the node indicated by node_ptr */
Node *delete_node(Node *head, Node *node_ptr) {
	if (head == NULL) { //if head is NULL
		return NULL;
	}

	if (head == node_ptr) { //if head is the targeted node to change
		head = head->next; //get head's nxt & return 'new head'
		free(node_ptr);
		return head;
	}

	Node *prev_ptr = head;
	while (prev_ptr->next != NULL && prev_ptr->next != node_ptr) {
		prev_ptr = prev_ptr->next;
	}
	if (prev_ptr->next == NULL) {
		return head;
	} else {
		prev_ptr->next = node_ptr->next;
		free(node_ptr);
	}
	return head;
}

/* print out ever eleent in the list */
Node *print_list(Node *head, char *text) {
	printf("%s: ", text);
	Node *temp = head;
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
	return head;
}

/* de-allocate list */
Node *free_list(Node *head) {
	Node *temp = head;

	while (temp != NULL) {
		temp = temp->next;
		free(head);
		head = temp;
	}
	return NULL;
}
