#include <stdio.h>
#include<malloc.h>
struct node {
  int data;
  struct node *next;
};
struct node *start = NULL;
void push(int);
void pop();
void peek();

int main(void) { 

  push(10);
  push(30);
  push(40);
  peek();
  
  return 0; 
}

void push(int ele){
  struct node* newnode;
  newnode = (struct node*)malloc(sizeof(struct node));
  newnode->data = ele;
  newnode->next = start;
  start = newnode;
};

void pop(){
  start = start->next;
};

void peek(){
  struct node* temp = start;
  while(temp!= NULL){
    printf("%d\t",temp->data);
    temp = temp->next; 
  }
}












