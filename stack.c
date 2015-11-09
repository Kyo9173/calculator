#include "stdio.h"
#include "stack.h"
#include "stdlib.h"
#include "expre.h"
Stack *InitStack()
{
  Stack *p_stack;
  p_stack = malloc(sizeof(Stack));
  p_stack -> size = 0;
  return p_stack;
}

void StackPush(Stack* p_stack,char c)
{
  //   printf("StackPush:%d压栈\n",c);
  PNode p_node = malloc(sizeof(Node));
  p_node -> Item = c;
  p_node -> Down = p_stack -> top;
  p_stack -> size++;
  p_stack -> top = p_node;
}

char StackPop(Stack* p_stack)
{
  //  printf("StackPop:%d出栈\n",p_stack->top->Item);
  if(p_stack->size==0)
    printf("StackPop BOOM\n");
  char c;
  c = p_stack -> top -> Item;
  
  PNode* p_stack_top_temp = (p_stack -> top);
  (p_stack -> top) = (p_stack -> top -> Down);
  p_stack -> size--;
  free(p_stack_top_temp);
  return c;
}

char ShowStackPop(Stack* p_stack)
{
  //printf("%c",(p_stack -> top -> Item));
  if((p_stack->size)>0)
  return p_stack -> top -> Item;
  else
    {
      // printf("ShowStackPop BOOM\n");
      
      return -1;
    }
}

void test_StackAllOut(Stack* p_stack)
{
  int i = (p_stack->size);
  for(;i!=0;i--)
    {
      //printf("%c",ShowStackPop(p_stack));
      //printf("\n");
      StackPop(p_stack);
    }
}

void StackAllOut(Stack* p_stack)
{
  while(p_stack->size > 0)
    {
      ExpreIn(StackPop(p_stack));
    }
}
