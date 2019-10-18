#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
#define MAXSTACK 10
typedef struct stack
{
	int items[MAXSTACK];
	int top;
}Stack;
void InitializeStack(Stack * ps);
bool FullStack(const Stack * ps);
bool EmptyStack(const Stack *ps);
bool Push(int item, Stack *ps);
bool Pop(Stack *ps);
char * s_gets(char * st, int n);
