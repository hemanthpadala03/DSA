#include <stdio.h>
#define MAX 10 // Defining maximum size of queue

int queue[MAX], front = -1, rear = -1;

// Function to add an element to the queue
void enqueue(int val) {
   if(rear == MAX-1)
      printf("\nQueue Overflow.");
   else {
      if(front == -1)
         front = 0;
      rear++;
      queue[rear] = val;
      printf("\nInserted %d", val);
   }
}

// Function to delete an element from the queue
void dequeue() {
   if(front == -1 || front > rear)
      printf("\nQueue Underflow.");
   else {
      printf("\nDeleted : %d", queue[front]);
      front++;
   }
}

// Function to display the queue
void display() {
   if(front == -1 || front > rear)
      printf("\nQueue is empty.");
   else {
      printf("\nQueue elements are:");
      for(int i = front; i <= rear; i++)
         printf("%d ",queue[i]);
   }
}

int main() {
   int choice, val;
   printf("\n1) Enqueue in queue");
   printf("\n2) Dequeue from queue");
   printf("\n3) Display queue");
   printf("\n4) Exit");
   do {
      printf("\n\nEnter choice : ");
      scanf("%d", &choice);
      switch(choice) {
         case 1: {
            printf("Enter value to be enqueued:");
            scanf("%d", &val);
            enqueue(val);
            break;
         }
         case 2: {
            dequeue();
            break;
         }
         case 3: {
            display();
            break;
         }
         case 4: {
            printf("Exit");
            break;
         }
         default: {
            printf("\nInvalid Choice");
         }
      }
   } while(choice != 4);
   return 0;
}
