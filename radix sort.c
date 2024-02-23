#include <stdio.h>

void radixSort(int arr[], int n) {
    // Find the maximum element in the array
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Determine the number of digits required
    int digits = 0;
    while (max > 0) {
        max /= 10;
        digits++;
    }

    // Create count arrays
    int countArr[10] = {0};
    int tempArr[n];

    for (int digit = 0; digit < digits; digit++) {
        // Count the frequency of each digit
        for (int i = 0; i < n; i++) {
            int digitIdx = (arr[i] / (int)pow(10, digit)) % 10;
            countArr[digitIdx]++;
        }

        // Modify the count array to store the cumulative sum of occurrences
        for (int i = 1; i < 10; i++) {
            countArr[i] += countArr[i - 1];
        }

        // Place elements into the temporary array based on their digit values
        for (int i = n - 1; i >= 0; i--) {
            int digitIdx = (arr[i] / (int)pow(10, digit)) % 10;
            tempArr[countArr[digitIdx] - 1] = arr[i];
            countArr[digitIdx]--;
        }

        // Copy the sorted elements back into the original array
        for (int i = 0; i < n; i++) {
            arr[i] = tempArr[i];
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {6, 4, 3, 5, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: ");
    printArray(arr, n);

    radixSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}

