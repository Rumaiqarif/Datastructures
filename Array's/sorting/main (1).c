#include <stdio.h>
#define max 10
int arr[max] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int place = max - 1;
void reverse();
int main() {

  reverse();

  for (int i = 0; i <= place; i++) {
    printf("%d ", arr[i]);
  }
}

void reverse() {
  for (int i = 0; i < place; i++) {
    for (int j = 0; j < place; j++) {
      if (arr[j] < arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}