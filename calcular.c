#include"stdio.h"
#include"ctype.h"
#include"stack.h"
#include"numlimit.h"
#include"boolar.h"
#include"expre.h"
#include"string.h"
void input();
int OutBina(int in_count,char c,char temp[]);
void opear();

int main()
{
  printf("------CALCULAR------\n");
  input();
  opear();
  
  

  

  return 0;
}

void input()
{
  char c;
  char temp[BOOLAR_NUM_SIZE];
  int in_count=0;
  int temp_o;
  Stack *p_stack = InitStack();
  
  while((c=getchar())!=EOF)
    {
      ShowExpreAll();
      //printf("///////当前读入////// %c\n",c);
      if(isspace(c))continue;
      if(isdigit(c))
	{
	  temp[in_count] = c;
	  in_count++;
	 
	}
      else
	{
	  in_count = OutBina(in_count,c,temp);
	  switch(c)
	    {
	    case '(':
	      {
		StackPush(p_stack,c);
		break;
	      }
	    case ')':
	      {	      
		while(ShowStackPop(p_stack) != '(')	  	     
		  {		
		    ExpreIn(StackPop(p_stack));
		  }	 		
		  StackPop(p_stack);
		  break;				
	      }
	    case '+':
	    case '-':
	    case '*':
	    case '/':	      


	      //栈顶优先级大于等于此操作符时，弹出直到发现优先级低的
	      temp_o = ShowStackPop(p_stack);
	      while(ExpreO(temp_o)>=ExpreO(c) && temp_o!= '(')	    
		{
		  ExpreIn(StackPop(p_stack));//弹出至E
		  temp_o = (ExpreO(ShowStackPop(p_stack)));
		}
	      StackPush(p_stack,c);//压栈
	    }
	}
  	 
    }
  //收尾
  OutBina(in_count,c,temp);
  StackAllOut(p_stack);
  ShowExpreAll();
}

int OutBina(int in_count,char c,char temp[])
{
  if(in_count!=0)
    {
      //处理遗留的二进制串
      int BinaWord;
      BinaWord = ReadBina(temp,in_count-1);
      memset(temp,0,sizeof(char));
      ExpreIn((BinaWord));
      in_count=0;
     }
  return in_count;
}
  
void opear()
{
  Stack *p_stack2 = InitStack();
  int a,b;
  int Expre = GiveCount();
  for(int i=0;i!=Expre;i++)
    {
      //printf("////////测到%d////////\n",E[i]);
      if(E[i]<=50 && E[i]>=40)//运算符
	{
	  a = StackPop(p_stack2);
	  b = StackPop(p_stack2);
	  //	  printf("现在收到符号%c,\n A=%d B=%d\n",E[i],a,b);
	  //	  printf("0 - ");ShowBina(0);
	  //	  printf("1 - ");ShowBina(1);
	  //	  printf("2 - ");ShowBina(2);
	  switch(E[i])
	    {
	      
	    case '-':
	      BaMinus(b,a);
	      break;
	    case '+':
	      BaAdd(a,b);
	      break;
	    case '*':
	      BaMulti(a,b);
	      break;
	    case '/':
	      BaDivid(a,b);
	      break;
	    }
	  StackPush(p_stack2,Min(a,b));
	
	}
      else//占位符
	{
	  //printf("opear:");     
	  StackPush(p_stack2,E[i]);
	}
    }
  // printf("计算后 A=%d B=%d\n",a,b);
  //	  printf("0 - ");ShowBina(0);
  //	  printf("1 - ");ShowBina(1);
  //	  printf("2 - ");ShowBina(2);
  printf("ANS=");
  ShowBina(StackPop(p_stack2));

}

