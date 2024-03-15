#include <stdio.h>
#define MAX 10 // Defining maximum size of stack

int stack[MAX], top = -1;

// Function to add an element to the stack
void push(int val) {
   if(top >= MAX-1)
      printf("\nStack Overflow.");
   else {
      top++;
      stack[top] = val;
      printf("\nInserted %d", val);
   }
}

// Function to delete an element from the stack
void pop() {
   if(top <= -1)
      printf("\nStack Underflow.");
   else {
      printf("\nDeleted : %d", stack[top]);
      top--;
   }
}

// Function to display the stack
void display() {
   if(top >= 0) {
      printf("\nStack elements are:");
      for(int i = top; i >= 0; i--)
         printf("%d ",stack[i]);
   } else
      printf("\nStack is empty.");
}

int main() {
   int choice, val;
   printf("\n1) Push in stack");
   printf("\n2) Pop from stack");
   printf("\n3) Display stack");
   printf("\n4) Exit");
   do {
      printf("\n\nEnter choice : ");
      scanf("%d", &choice);
      switch(choice) {
         case 1: {
            printf("Enter value to be pushed:");
            scanf("%d", &val);
            push(val);
            break;
         }
         case 2: {
            pop();
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
