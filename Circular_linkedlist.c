#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL; // In a circular list, the next pointer of the last node points back to the head.
    return newNode;
}

Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        newNode->next = head; // For a circular list, the last node points back to the head.
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
    return head;
}

Node* insertAtEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        newNode->next = head; // For a circular list, the last node points back to the head.
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
    return head;
}

Node* deleteNode(Node* head, int data) {
    if (head == NULL) {
        return NULL;
    }

    Node* temp = head;
    Node* prev = NULL;

    // If head node itself holds the data to be deleted
    if (temp != NULL && temp->data == data) {
        while (temp->next != head) {
            temp = temp->next;
        }
        free(head);
        head = temp->next;
        free(temp);
        return head;
    }

    // Search for the data to be deleted, keep track of the previous node as we need to change 'prev->next'
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    // If the data was not present in linked list
    if (temp == NULL) {
        return head;
    }

    // Unlink the node from linked list
    prev->next = temp->next;

    free(temp); // Free memory

    return head;
}

void traverse(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    Node* head = NULL;

    // Insert at the beginning
    head = insertAtBeginning(head, 1);
    head = insertAtBeginning(head, 2);
    head = insertAtBeginning(head, 3);

    // Insert at the end
    head = insertAtEnd(head, 4);
    head = insertAtEnd(head, 5);

    // Traverse the list
    traverse(head);

    // Delete a node
    head = deleteNode(head, 3);

    // Traverse the list after deletion
    traverse(head);

    return 0;
}
