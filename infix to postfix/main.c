#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 200

char stack[max],infix[max],postfix[max];
int top=-1;
void push(char);
void print();
char pop();
void intopostfix();





int main(){
  printf("enter the infix expression ");
  scanf("%s",infix);
  intopostfix();
   print();
  
  return 0;
}

//function to convert infix to postfix expression

void intopostfix(){
  int i,j=0;
  
  for(i=0;i<strlen(infix);i++){

    if(infix[i]=='('){
      push(infix[i]);
    }
    else if(infix[i]==')'){
      char next;
      while((next=pop())!='('){
        postfix[j]=next;
        j++;
      
    }
    }
    else if(infix[i]=='+'){
      if(stack[top]=='*'||stack[top]=='/'||stack[top]=='-'){
       postfix[j]=pop();
        j++;
      push(infix[i]);
      }
      else
      {
        push(infix[i]);
      }
  }
      else if(infix[i]=='-'){
          if(stack[top]=='*'||stack[top]=='/'||stack[top]=='+'){
           postfix[j]=pop();
            j++;
          push(infix[i]);
          }
          else
          {
            push(infix[i]);
          }
      }
 else if(infix[i]=='*'){
   if(stack[top]=='/'){
     postfix[j]=pop();
     j++;
     push(infix[i]);
   }
   else
   {
     push(infix[i]);
   }
   
  }
   else if(infix[i]=='/'){
    if(stack[top]=='*'){
      postfix[j]=pop();
      j++;
      push(infix[i]);
    }
     else
     {
       push(infix[i]);
     }

   }
else
   {
   postfix[j]=infix[i];
   j++;
   }
    
  }
  }

  
  //function for push onto the stack
  void push(char item){
    top=top+1;
    stack[top]=item;
  }


  
//function for display 
  void print(){
    for(int j= 0; j< strlen(postfix);j++){
      printf("%c",postfix[j]);
    }
    for(int i = top;i>=0;i--){
      printf("%c",stack[i]);
    }
  }


//function for pop from the stack
  char pop(){
    char item;
    item=stack[top];
    top=top-1;
    return item;
  }






  
