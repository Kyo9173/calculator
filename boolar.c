#include"stdio.h"
#include"stdbool.h"
#include"boolar.h"
#include"string.h"
#include"stdlib.h"
int BaCount=0;
//memset(N,0,sizeof(_Bool)*BOOLAR_NUM_NUM*BOOLAR_NUM_SIZE));
//size:二进制位数，从0算起
int ReadBina(char temp[],int size)//int sym=0
{
  N_SIZE[BaCount] = size;
  //printf("READBINA:N_SIZE[%d]=%d\n",BaCount,size);
  for(int i=0;size!=(-1);size--,i++)
    {
      N[BaCount][i] = temp[size]-'0';
    }
  BaCount++;
  return BaCount-1;
}

void BaAdd(int a,int b)
{
  //两数size不同时，将大size应用于两数 
  int OpearSize = Max(N_SIZE[a],N_SIZE[b]);
  //int MinSize = Min(N_SIZE[a],N_SIZE[n]);
  //N_SIZE[MinSize] = OpearSize;

  int c[BOOLAR_NUM_SIZE];
  memset(c,0,sizeof(c));
  
  for(int i=0;i!=OpearSize+2;i++)
    {
      c[i] = c[i] + N[a][i] + N[b][i];
      c[i+1] = (int)(c[i]/2);
      c[i] = c[i]%2;
      // printf("N[a][i]= %d N[b][i]= %d c[%d] now = %d\n",N[a][i],N[b][i],i,c[i]);
    }

  int min = Min(a,b);
      
  for(int i=0;i!=OpearSize+2;i++)
    {
      N[min][i] = c[i];
      //SHOW ADDED
      //  printf("%d",N[min][i]);
      
    }
  //printf("---\n");
     
}

void BaMinus(int a,int b)//a-b
{
  int OpearSize = Max(N_SIZE[a],N_SIZE[b]);
  //printf("BaMinus:OS=%d,N_SIZE[%d]=%d,N_SIZE[%d]=%d\n",OpearSize,a,N_SIZE[a],b,N_SIZE[b]);
  int min = Min(a,b);
  if(MaxBinaPre(a,b)==0) //将得到负数
    {
      N_SYM[min] = 1; //设置为1表负数
      int temp = a;       //转换大小数 确认使用绝对值大减小
      a = b;
      b = temp;
    }

  int c[BOOLAR_NUM_SIZE];
  memset(c,0,sizeof(c));
  
  for(int i=0;i!=OpearSize+1;i++)
    {
      c[i] = N[a][i] - N[b][i];
      //    printf("BaMinus:c[%d]=%d\n",i,c[i]);
    }
  
  for(int i=OpearSize;i!=(-1);i--)
    {
      // printf("BaMinus:OpearSize = %d\n",OpearSize);
      //  printf("BaMinus:C[%d]=%d\n",i,c[i]);
      if(c[i]==(-1))//找到了一个-1
	{
	  c[i]=1;//直接借位为1
	  for(int it=i+1;;it++)//往前搜索是否有1 每过一个0设置为1 
	    {
	      //printf("/BaMinus:C[%d]=%d\n",it,c[it]);
	      if(c[it]==1)     //遇到1就借位
		{c[it]=0;break;}
	      else
		c[it]=1;
	    }
	  
	}
    }
  
     
  for(int i=0;i!=OpearSize+1;i++)
    {
      N[min][i] = c[i];
      //SHOW ADDED
      
      //printf("%d\n",N[min][i]);
    }

  N_SIZE[Min(a,b)]=OpearSize;
  
}
  


int Min(int a,int b)
{
  if(b>a)
    return a;
  else return b;
}

int Max(int a,int b)
{
  if(a>b)
    return a;
  else return b;
}
//判断是否前面的Bina更大或相等 返回1(true or 0(false 
int MaxBinaPre(int a,int b)
{
  int aSize = N_SIZE[a];
  int bSize = N_SIZE[b];
  int OpearSize = Max(N_SIZE[a],N_SIZE[b]);
  
  if(aSize!=bSize)
    {
      if(aSize > bSize)
	  return 1;
      else
	return 0;
    }
  else
    {
      for(;OpearSize!=(-1);OpearSize--)
	{
	  if(N[a][OpearSize]>N[b][OpearSize])
	     return 1;
	  if(N[a][OpearSize]<N[b][OpearSize])
	    return 0;
	}
      return 1;
    }
}
	     
	     
void ShowBina(int a)
{
  int i=N_SIZE[a]+10;
  int flag=0;
  if(N_SYM[a]==1)printf("-");
  for(;i!=(-1);i--)
    {
      //printf("SHOWBINA:NOW I = %d Flag = %d\n",i,flag);
      //printf("EXP = %d",(flag==0)&&(i==0));
      
      if(flag==0&&N[a][i]==1){flag=1;}
      if((flag==0)&&(i==0)){printf("%d",N[a][i]);break;}
      if(flag==0&&N[a][i]==0&&i!=0)continue;
      
      printf("%d",N[a][i]);
    }
  printf("\n");
}
    
void BaMulti(int a,int b)
{
  //两数size不同时，将大size应用于两数 
  int OpearSize = 4*Max(N_SIZE[a],N_SIZE[b]);

  int c[BOOLAR_NUM_SIZE+BOOLAR_NUM_SIZE];
  memset(c,0,sizeof(c));
  
  for(int i=0;i!=(OpearSize);i++)
    {
      for(int i2=0;i2!=(OpearSize);i2++)
	{
	  c[i+i2] = c[i+i2] + (N[a][i]*N[b][i2]);
	  //  printf("i+i2 = %d ,c[i+i2]=%d\n",(i+i2),c[i+i2]);
	}
    }

 
  ///  for(int i=0;i!=OpearSize+10;i++)
  //    printf("/c[%d]=%d\n",i,c[i]);

  for(int i=0;i!=OpearSize+10;i++)
    {
      c[i+1] = c[i+1]+(c[i]/2);
      c[i]   = (c[i]%2);
    }
  int min = Min(a,b);
  
  for(int i=0;i!=OpearSize*2;i++)
    {
      N[min][i] = c[i];
      //SHOW ADDED
      //printf("%d",N[min][i]);
    }
  //printf("---\n");
   
}
void BaDivid(int a,int b)
{
  
}
