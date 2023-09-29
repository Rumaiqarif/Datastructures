#include <stdio.h>

int arr[100];
int capacity = 100;
int flag = 0;
void insertelement();
void traversel();
void insertatend();
void insertatbegin();
void insertatanypostion();
void deleteatend();
void deleteatbegin();
void deleteatloc();

int main() {
  printf("capacity of array is 100\n");
  insertelement();
  traversel();
  insertatend();
  traversel();
  insertatbegin();
  traversel();
  insertatanypostion();
  traversel();
  deleteatend();
  traversel();
  deleteatbegin();
  traversel();
  deleteatloc();
  traversel();
};

// function to insert elements in the array
void insertelement() {
  int size;
  printf("Enter size of array\n");
  scanf("%d", &size);
  if (size < 0 || size > capacity) {
    printf("invalid size\t");
  } else {
    printf("Enter elements of the array\n");
    for (int i = 0; i < size; i++) {
      scanf("%d", &arr[flag]);
      flag = flag + 1;
    }
  }
}

// fuction to access elements of the array

void traversel() {
  printf("Elements of array are : \n");
  for (int i = 0; i < flag; i++) {
    printf("%d\t", arr[i]);
  }
}

// function to insert element a the end
void insertatend() {
  int ele;
  printf("\nEnter element to be inserted at end\t");
  scanf("%d", &ele);

  arr[flag] = ele;
  flag = flag + 1;
};

// function to add element at the beginning
void insertatbegin() {
  int ele;
  printf("\nEnter element to be inserted at begin\t");
  scanf("%d", &ele);
  for (int i = flag; i >= 0; i--) {
    arr[i + 1] = arr[i];
  }
  arr[0] = ele;
  flag = flag + 1;
}
// function to insert element at any position in the array
void insertatanypostion() {
  int position, ele;
  printf("\nEnter element to insert at any position  ");
  scanf("%d", &ele);
  printf("\nEnter position  ");
  scanf("%d", &position);
  if (position < 0 || position > flag + 1) {
    printf("invalid postion\n");
  } else {
    for (int i = flag; i >= position - 1; i--) {
      arr[i + 1] = arr[i];
    }
    arr[position - 1] = ele;
    flag = flag + 1;
  }
};
// function for deleting an  element at end
void deleteatend() { flag = flag - 1; };

// function for deleting an  element at begin
void deleteatbegin() {

  for (int i = 0; i <= flag; i++) {
    arr[i] = arr[i + 1];
  }
  flag = flag - 1;
};

// function for deleting at any position
void deleteatloc() {
  int loc;
  printf("\nEnter location of ele to be deleted ");
  scanf("%d", &loc);
  for (int i = loc; i < flag; i++) {
    arr[i - 1] = arr[i];
  }
  flag = flag - 1;
}
