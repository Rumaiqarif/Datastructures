#include <stdio.h>
#include <stdlib.h>

struct node {
  struct node *previous;
  int data;
  struct node *next;
};

struct node *start = NULL;

void insert_at_beginning();
void display();
void insert_at_end();
void delete_at_beginning();
void deleteatloc();
void insertatloc();

int main() {
  insert_at_beginning();
  insert_at_beginning();
  display();
  insert_at_end();
  display();
  delete_at_beginning();
  display();
  insert_at_beginning();
  insert_at_beginning();
  display();
  deleteatloc();
  display();
  insertatloc();
  display();
}

// insert element at beginning
void insert_at_beginning() {
  int element;
  printf("enter element ");
  scanf("%d", &element);
  struct node *newnode;
  newnode = (struct node *)malloc(sizeof(struct node));
  newnode->data = element;
  newnode->previous = NULL;
  if (start == NULL) {
    newnode->next = start;
    start = newnode;
  } else {
    start->previous = newnode;
    newnode->next = start;
    start = newnode;
  }
}

// display elemets of list
void display() {
  struct node *temp = start;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
}
// insert at end
void insert_at_end() {
  int element;
  printf("enter element ");
  scanf("%d", &element);
  struct node *newnode;
  newnode = (struct node *)malloc(sizeof(struct node));
  newnode->data = element;
  newnode->next = NULL;
  if (start == NULL) {
    newnode->previous = start;
    start = newnode;
  } else {
    struct node *handle = start;
    while (handle->next != NULL) {
      handle = handle->next;
    }
    handle->next = newnode;
    newnode->previous = handle;
  }
}

// delete at beginning
void delete_at_beginning() {
  if (start == NULL) {
    printf("list empty");
  } else {
    start = start->next;
    start->previous = NULL;
  }
};

// delete at end
void delete_at_end() {
  if (start == NULL) {
    printf("list empty");

  } else {
    struct node *handle = start;
    while (handle->next != NULL) {
      handle = handle->next;
    }
    handle->previous->next = NULL;
  }
}

// delete at location
void deleteatloc() {
  int loc;
  printf("enter location ");
  scanf("%d", &loc);
  struct node *current = start;
  if (loc < 2) {
    start = start->next;
    start->previous = NULL;
  } else {
    int i = 0;
    while (i < loc - 1) {
      current = current->next;
      i++;
    }
    current->previous->next = current->next;
    current->next->previous = current->previous;
  };
}

// inser at location
void insertatloc() {
  int loc, element;
  struct node *current = start;
  printf("enter element ");
  scanf("%d", &element);
  printf("enter location ");
  scanf("%d", &loc);
  struct node *newnode;
  newnode = (struct node *)malloc(sizeof(struct node));
  newnode->data = element;

  if (loc < 2) {
    insert_at_beginning();
  } else {
    int i = 1;
    while (i < loc - 1) {
      current = current->next;
      i++;
    }
    struct node *temp;
    temp = current->next;
    current->next = newnode;
    newnode->previous = current;
    newnode->next = temp;
    temp->previous = newnode;
  };
}
