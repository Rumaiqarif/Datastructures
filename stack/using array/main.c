#include <stdio.h>
#define max_size 10
int stack[max_size];
int top = -1;
void push(int);
void pop();
void peek();

int main(void) {
  push(10);
  push(20);
  peek();
  pop();
  peek();
}

void push(int ele){
  if(top >= max_size-1 ){
    printf("stack is full");
  
  }
  else{
    top = top+1;
    stack[top] = ele;
  }
};

void pop(){
  if(top < 0){
    printf("stack is empty");
  }
  else{
    top = top-1;
  }
};
void peek(){
  if(top < 0){
    printf( "stack is empty");
  }
  else{
    for(int i= 0; i<= top;i++){
      printf("%d\t",stack[i]);
    }
  }
}









