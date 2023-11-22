#include <malloc.h>
#include <stdio.h>

struct node {
  int data;
  struct node *next;
};
struct node *start = NULL;
void enqueue(int);
void dequeue();
void display();

int main() {
  enqueue(17);
  enqueue(18);
  enqueue(30);

  display();
  dequeue();
  display();
  return 0;
}

void enqueue(int ele) {
  struct node *newnode;
  newnode = (struct node *)malloc(sizeof(struct node));
  newnode->data = ele;
  newnode->next = NULL;
  struct node *handle = start;
  if (handle == NULL) {
    start = newnode;
  } else {
    while (handle->next != NULL) {
      handle = handle->next;
    }
    handle->next = newnode;
  }
}
void dequeue() { start = start->next; }

void display() {
  struct node *temp = start;
  while (temp != NULL) {
    printf("->%d", temp->data);
    temp = temp->next;
  }
}
