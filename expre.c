#include"expre.h"
#include"stdio.h"

int ExpreCount=0;
void ShowExpreAll()
{
}
/* //  printf("表达式从左到右\n");
  for(int i=0;i!=ExpreCount;i++)
    {
      if(E[i]<=50 && E[i]>=40)
	//	printf("%c",E[i]);
      else
	//printf("%d",E[i]);
    }
  printf("\n");
}*/
void ExpreIn(int c)
{
  E[ExpreCount]=c;
  ExpreCount++;
}
//注意ExpreCount

int ExpreO(char c)
{
  switch(c)
    {
    case '+':
    case '-':
      return 1;
    case '/':
    case '*':
      return 2;
    case '(':
    case ')':
      return 3;
    case -1:
      return -1;
    }
}

int GiveCount()
{
  return ExpreCount;
}
