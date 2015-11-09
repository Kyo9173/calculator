#ifndef _STACK_H
#define _STACK_H

typedef struct node *PNode;

typedef struct node
{
  char Item;
  PNode Down;
}Node;

typedef struct stack
{
  PNode top;
  int size; //NODE数量
}Stack;

Stack *InitStack();
void StackPush(Stack* p_stack,char Item);
char StackPop(Stack* p_stack);
char ShowStackPop(Stack* p_stack);
void test_StackAllOut(Stack* p_stack);
void StackAllOut(Stack* p_stack);
#endif
