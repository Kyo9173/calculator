#include "stdio.h"
#include "stack.h"
int main()
{
  Stack *p = InitStack();
  StackPush(p,'a');
  StackPop(p);
  StackPush(p,'b');
  StackPush(p,'a');
  StackPush(p,'c');
  StackPop(p);
  StackPop(p);
  StackPop(p);
  StackPop(p);
    test_StackAllOut(p);
  
  return 0;
}
