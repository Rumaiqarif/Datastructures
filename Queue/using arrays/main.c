#include <stdio.h>
#define size 10
int queue[size];
int front = -1,rear = -1;
void enqueue(int);
void dequeue();
void display();

int main(void) {
  enqueue(1);
  enqueue(2);
  enqueue(3);
  enqueue(4);
  enqueue(5);
  enqueue(6);
  enqueue(7);
  enqueue(8);
  enqueue(9);
  enqueue(10);
  dequeue();
  display();
  enqueue(30);
  display();
  
  
}

//insert ele in queue
void enqueue(int ele){
  if(rear == size -1 && front == 0)
  {
    printf("overflow\n");
  }
  else if(rear == -1 && front == -1)
  {
     rear = front = 0;
    queue[rear]= ele;
    
  }
  else{
    rear = rear+1 % size;
    queue[rear]= ele;
  }
}

//delete ele from queue
void dequeue(){
  if(rear == -1 && front == -1){
    printf("underflow\n");
  }
  else if(front == rear){
    front = rear = -1;
  }
  else{
   front = front+1 % size; 
  }
}

void display(){
  int i;
  if(rear == -1 && front == -1){
    printf("queue is empty\n");
  }
  else{
    for(i = front ;i < rear+1 ; i++){
      printf("%d\n",queue[i]);
    }
  }
}












