#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error! unable to create a new node\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
    return head;
}

// Function to insert a node at the end of the list
Node* insertAtEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}

// Function to delete the first node
Node* deleteFirst(Node* head) {
    if (head == NULL) {
        printf("List is already empty\n");
    } else {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
    return head;
}

// Function to delete the last node
Node* deleteLast(Node* head) {
    if (head == NULL) {
        printf("List is already empty\n");
    } else {
        Node* temp = head;
        Node* prev = NULL;
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        if (prev != NULL) {
            prev->next = NULL;
        }
        free(temp);
    }
    return head;
}

// Function to traverse and print the list
void traverse(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to insert a node after a specific node
Node* insertAfter(Node* head, Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("Invalid operation: prevNode is NULL\n");
        return head;
    }
    Node* newNode = createNode(data);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    return head;
}

int main() {
    Node* head = NULL;
    head = insertAtBeginning(head, 1);
    head = insertAtBeginning(head, 2);
    head = insertAtEnd(head, 3);
    head = insertAtEnd(head, 4);
    traverse(head);
    head = deleteFirst(head);
    traverse(head);

    // Example usage of insertAfter
    // Assuming we want to insert a node with data 5 after the first node
    Node* prevNode = head; // The first node in the list
    head = insertAfter(head, prevNode, 5);
    traverse(head);

    return 0;
}
