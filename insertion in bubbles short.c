#include <stdio.h>

void bubbleSort(int array[], int size) {
  int swapped; // Flag to indicate if any swaps were made in a pass
  int i, j;  // Loop counters

  do {
    swapped = 0; // Reset swapped flag for each pass

    // Iterate through the array, comparing adjacent elements
    for (i = 0; i < size - 1; i++) {
      if (array[i] > array[i + 1]) {
        // Swap the elements if they are in the wrong order
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;

        swapped = 1; // Set swapped flag to indicate a swap
      }
    }
  } while (swapped); // Continue the loop as long as swaps occur
}

void printArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

int main() {
  int array[] = {6, 4, 3, 5, 1, 2};
  int size = sizeof(array) / sizeof(array[0]);

  printf("Unsorted array: ");
  printArray(array, size);

  bubbleSort(array, size);

  printf("Sorted array: ");
  printArray(array, size);

  return 0;
}

