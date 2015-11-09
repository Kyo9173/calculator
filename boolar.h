#ifndef _BOOLAR_H
#define _BOOLAR_H
#include"numlimit.h"
#include"stdbool.h"
_Bool N[BOOLAR_NUM_NUM][BOOLAR_NUM_SIZE];
int N_SIZE[BOOLAR_NUM_NUM];
int N_SYM[BOOLAR_NUM_NUM];
//读取Temp中反二进制数，并提供size，返回存在N里的指针
int ReadBina(char temp[],int size);
void BaAdd(int a,int b);
void BaMinus(int a,int b);
void BaMulti(int a,int b);
void BaDivid(int a,int b);
int Min(int a,int b);
int Max(int a,int b);
int MaxBinaPre(int a,int b);
//通过size检测符号位 转换为大size反码
//void BaChange(int a,int b);
void ShowBina(int a);

#endif


//BaMinus
//二进制减法 使用反码运算（负数表达）
//最后一位为符号位
//检测size（符号位）
//
//存储要考虑负数 -101010
