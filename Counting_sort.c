#include <stdio.h>
#define MAX 255

// Function to perform Counting Sort
void countSort(int array[], int size) {
    int output[MAX];
    int count[MAX];
    int max = array[0]; // Initialize max with the first element

    // Find the largest item in the array
    for (int i = 1; i < size; i++) {
        if (array[i] > max)
            max = array[i];
    }

    // Initialize the count array for each element
    for (int i = 0; i <= max; ++i) {
        count[i] = 0;
    }

    // Store the count of each element
    for (int i = 0; i < size; i++) {
        count[array[i]]++;
    }

    // Calculate cumulative count
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Build the sorted array based on the count array
    for (int i = size - 1; i >= 0; i--) {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    // Copy the sorted elements back to the original array
    for (int i = 0; i < size; i++) {
        array[i] = output[i];
    }
}

// Display the sorted array
void display(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int array[] = {2, 5, 2, 8, 1, 4, 1};
    int n = sizeof(array) / sizeof(array[0]);

    printf("Original array: ");
    display(array, n);

    countSort(array, n);

    printf("Sorted array: ");
    display(array, n);

    return 0;
}
