#include <stdio.h>

void countSort(int arr[], int n) {
  // Find the maximum element in the array
  int max = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }

  // Create a count array to store the frequency of each element
  int countArr[max + 1] = {0};

  // Count the frequency of each element in the array
  for (int i = 0; i < n; i++) {
    countArr[arr[i]]++;
  }

  // Modify the count array to store the cumulative sum of occurrences
  for (int i = 1; i <= max; i++) {
    countArr[i] += countArr[i - 1];
  }

  // Create a temporary array to store the sorted elements
  int sortedArr[n];

  // Iterate through the original array and place elements into the sorted array based on their counts
  for (int i = n - 1; i >= 0; i--) {
    sortedArr[countArr[arr[i]] - 1] = arr[i];
    countArr[arr[i]]--;
  }

  // Copy the sorted elements back into the original array
  for (int i = 0; i < n; i++) {
    arr[i] = sortedArr[i];
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

  countSort(arr, n);

  printf("Sorted array: ");
  printArray(arr, n);

  return 0;
}

