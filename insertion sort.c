#include<stdio.h>


void insertion_sort(int arr[], int n)

{
  for (int i = 1; i < n; i++) {
    int key = arr[i];
    int j = i - 1;

    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr [j];
      j--;
    }

    arr[j + 1] = key;
  }
}

void print_array(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int arr[] = {10, 7, 8, 9, 1, 5};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("Unsorted array: ");
  print_array(arr, n);

  insertion_sort(arr, n);

  printf("Sorted array: ");
  print_array(arr, n);

  return

0;
}

