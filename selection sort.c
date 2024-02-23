#include <stdio.h>

void selectionSort(int array[], int size) {
  int i, j, minIndex;

  for (i = 0; i < size - 1; i++) {
    minIndex = i;

    for (j = i + 1; j < size; j++) {
      if (array[j] < array[minIndex]) {
        minIndex = j;
      }
    }

    if (minIndex != i) {
      int temp = array[i];
      array[i] = array[minIndex];
      array[minIndex] = temp;
    }
  }
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

  selectionSort(array, size);

  printf("Sorted array: ");
  printArray(array, size);

  return 0;
}
