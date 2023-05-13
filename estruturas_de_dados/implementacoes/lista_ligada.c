#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d, ", current->data);
        current = current->next;
    }
    printf("\n");
}

void insertAtBeginning(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void insertAtMiddle(Node** head, int data, int position) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    if (position == 0 || *head == NULL) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* current = *head;
    int currentPosition = 0;
    while (current->next != NULL && currentPosition < position - 1) {
        current = current->next;
        currentPosition++;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void removeItem(Node** head, int data) {
    if (*head == NULL) {
        return;
    }

    if ((*head)->data == data) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    Node* current = *head;
    Node* previous = NULL;
    while (current != NULL && current->data != data) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        return;
    }

    previous->next = current->next;
    free(current);
}


int main() {
    Node* head = NULL;

    insertAtBeginning(&head, 1); // [1,]
    insertAtBeginning(&head, 0); // [0, 1]
    insertAtMiddle(&head, 2, 1); // [ 0, 2, 1]
    insertAtMiddle(&head, 3, 2); // [0, 2, 3, 1]
    removeItem(&head, 2); // [0, 3, 1]

    printList(head);

    return 0;
}
