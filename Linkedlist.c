#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the beginning
void insertAtBeginning(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a new node at the end
void insertAtEnd(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode; // If the list is empty, make the new node the head
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to insert a new node after a specific value
void insertAfter(struct Node* prevNode, int newData) {
    if (prevNode == NULL) {
        return; // Handle invalid input
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

// Function to delete the first node
void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        return; // List is empty
    }

    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Function to delete the last node
void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        return; // List is empty
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    struct Node* current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
}

// Function to delete a node by value
void deleteByValue(struct Node** head, int targetData) {
    if (*head == NULL) {
        return; // List is empty
    }

    if ((*head)->data == targetData) {
        deleteAtBeginning(head);
        return;
    }

    struct Node* current = *head;
    while (current->next != NULL && current->next->data != targetData) {
        current = current->next;
    }

    if (current->next != NULL) {
        struct Node* temp = current->next;
        current->next = current->next->next;
        free(temp);
    }
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Insert nodes
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);

    // Print the list
    printf("Linked List: ");
    printList(head);

    // Insert after a specific value (e.g., after 20)
    struct Node* targetNode = head->next;
    insertAfter(targetNode, 25);

    // Print the updated list
    printf("Updated Linked List: ");
    printList(head);

    // Delete nodes
    deleteAtBeginning(&head);
    deleteAtEnd(&head);
    deleteByValue(&head, 25);

    // Print the final list
    printf("Final Linked List: ");
    printList(head);

    // Clean up memory (free nodes)
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
