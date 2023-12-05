#include <stdio.h>
#include<malloc.h>
struct node {
  int data;
  struct node *adress;
  
};

struct node *head = NULL;
void insert();
void display();
void sort();

int main()
{
  insert();
  insert();
  insert();
  insert();
  display();
  sort();
  display();
  
}
void insert()
{
  struct node* newnode;
  int element;
  printf("enter element ");
  scanf("%d",&element);
  newnode = (struct node*)malloc(sizeof(struct node));
  newnode->data=element;
  newnode->adress=head;
  head=newnode;
  
}



void display()
{
  struct node *temp= head;
   while(temp!=NULL)
   {
      printf("%d",temp->data);
      temp=temp->adress;

    }
  }
  
  void sort()
{
    struct node *current = head, *index = NULL;

    int temp;

        while (current != NULL)
          {
            index = current->adress;
            while (index != NULL)
              {
                if (current->data > index->data) 
                {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
                index = index->adress;
            }
            current = current->adress;
        }
    }

 









  
