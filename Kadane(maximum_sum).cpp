#include <stdio.h>

int maxSubArraySum(int a[], int size) {
    int max_so_far = -2147483648; // Minimum value for an object of type int
    int max_ending_here = 0;

    for (int i = 0; i < size; i++) {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here){
            max_so_far = max_ending_here;
        }

        if (max_ending_here < 0){
            max_ending_here = 0;
        }
    }
    return max_so_far;
}

int main() {
    int a[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
    int n = sizeof(a) / sizeof(a[0]);

    // Function Call
    int max_sum = maxSubArraySum(a, n);
    printf("Maximum contiguous sum is %d\n", max_sum);
    return 0;
}
