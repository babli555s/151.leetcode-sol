#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Function to heapify a subtree rooted at index 'i'
void heapify(int arr[], int n, int i) {
  int largest = i; // Initialize largest as current node
  int left = 2 * i + 1;  // Index of left child
  int right = 2 * i + 2; // Index of right child

  // If left child is larger than the root
  if (left < n && arr[left] > arr[largest]) {
    largest = left;
  }

  // If right child is larger than the largest so far
  if (right < n && arr[right] > arr[largest]) {
    largest = right;
  }

  // If largest is not the root
  if (largest != i) {
    swap(&arr[i], &arr[largest]);
    heapify(arr, n, largest); // Recursively heapify the affected subtrees
  }
}

// Function to build a max heap
void buildMaxHeap(int arr[], int n) {
  // Start from the last parent node and heapify all parents
  for (int i = n / 2 - 1; i >= 0; i--) {
    heapify(arr, n, i);
  }
}

// Function to perform heap sort
void heapSort(int arr[], int n) {
  // Build a max heap
  buildMaxHeap(arr, n);

  // One by one extract the maximum element from the heap and place it in the end
  for (int i = n - 1; i >= 1; i--) {
    // Extract the maximum element and place it at the end
    swap(&arr[0], &arr[i]);

    // Heapify the reduced heap
    heapify(arr, i, 0);
  }
}

// Function to print an array
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

  heapSort(arr, n);

  printf("Sorted array: ");
  printArray(arr, n);

  return 0;
}

