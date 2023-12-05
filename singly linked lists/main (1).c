#include <malloc.h>
#include <stdio.h>

// function prototype
void addatbegin(int);
void addatend(int);
void traverse();
void appendAfter(int, int);
void prepandbefore(int, int);
void deleteatbegin();
void deleteatend();
void deleteele(int);
void deleteatloc(int);

// structure
struct node {
  int data;
  struct node *next;
};
struct node *start = NULL;

int main() {
  // function call
  printf("after calling add at begin function\n");
  addatbegin(22);
   traverse();

  printf("after calling add at begin function\n");
  addatbegin(23);
  traverse();

  printf("after calling add at end function\n");
  addatend(55);
  traverse();

  printf("after calling add after ele function\n");
  appendAfter(23, 100);
  traverse();

  printf("after calling add before ele function\n");
  prepandbefore(100, 8999);
  traverse();

  printf("after calling delete at begin function\n");
  deleteatbegin();
  traverse();

  printf("after calling  delete at endfunction\n");
  deleteatend();
  traverse();

  printf("after calling deleting  any ele function\n");
   deleteele(22);
   traverse();
  
 printf("after calling add at begin function\n");
  addatbegin(909);
   traverse();

  printf(" after calling delete at any location\n");
   deleteatloc(3);
     traverse();
  
}

// function for adding an element at beginning of the list
void addatbegin(int ele)
{

  struct node *newnode;
  newnode = (struct node *)malloc(sizeof(struct node));
  newnode->data = ele;
  newnode->next = start;
  start = newnode;
};

// function for accessing elements of the list
void traverse() 
{
  printf("elements of the list are :\n");
  struct node *handle = start;
    while (handle != NULL) 
  {
    printf("%d\n", handle->data);
    handle = handle->next;
  };
};

// function for adding an element at end of the list
void addatend(int ele) 
{
  struct node *newnode;
  newnode = (struct node *)malloc(sizeof(struct node));
  newnode->data = ele;
  newnode->next = NULL;
  struct node *handle = start;
  while (handle->next != NULL)
  {
    handle = handle->next;
  }
  handle->next = newnode;
}

// function for adding an element after the element in the list
void appendAfter(int afterwhichele, int ele) 
{
  struct node *newnode;
  newnode = (struct node *)malloc(sizeof(struct node));
  newnode->data = ele;
  struct node *handle = start;
  while (handle != NULL) {
  if (handle->data == afterwhichele) 
  {
      newnode->next = handle->next;
      handle->next = newnode;
      break;
   }
    handle = handle->next;
  }
  if (handle == NULL) 
  {
    printf("number not found\n");
  }
}

// function  for adding an ele before a element in the list;
void prepandbefore(int beforewhichele, int ele)
{
  struct node *newnode;
  newnode = (struct node *)malloc(sizeof(struct node));
  newnode->data = ele;
  struct node *current = start;
  struct node *previous = start;
  while (current != NULL)
  {
   if (current->data == beforewhichele) 
  {
      newnode->next = previous->next;
      previous->next = newnode;
      break;
  }
    previous = current;
    current = current->next;
  }
  if (current == NULL) 
  {
    printf("number doesn`t exist\n");
  }
}
// function for deleting an element at beginning of the list
void deleteatbegin()
{
  struct node *deletedele = start;
  start = start->next;
  printf("deleted element is %d\n", deletedele->data);
};


//function for deleting an element at end of the list

void deleteatend()
{
  struct node *current = start;
  struct node *previous = start;
  
  while(current->next!= NULL)
  {
    previous =current;
    current = current->next;
  }
  previous->next=NULL;
  printf("deleted ele is %d\n",current->data);
}
//function for deletion of any ele from the list
void deleteele(int whichele)
{
  struct node *current = start;
  struct node *previous = start;
  while (current != NULL) 
  {
    if (current->data == whichele) 
    {
      previous->next = current->next;
      break;
    }
    previous = current;
    current = current->next;
  }
  if (current == NULL) 
  {
    printf("number doesn`t exist\n");
  }
};

//fuction for deletion at any location
void deleteatloc(int loc){
  struct node* temp ;
  struct node *current = start;
if(loc < 2){
  deleteatbegin();
}else{
  int i = 1;
  while(i < loc-1){
    current = current->next;
    i++;
  }

    
    temp = current->next;
    current->next = temp->next;
    free(temp);
    
    }
}