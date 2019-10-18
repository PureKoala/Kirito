#include "myhead.h"
void InitializeStack(Stack * ps)
{
	ps->top = 0;
	for (int i = 0; i < MAXSTACK; i++)
	{
		ps->items[i] = '\0';
	}
}
bool FullStack(const Stack * ps)
{
	if (ps->top == MAXSTACK)
		return true;
	else
		return false;
}
bool EmptyStack(const Stack *ps)
{
	if (ps->top == 0)
		return true;
	else
		return false;
}
bool Pop(Stack * ps)
{
	if (EmptyStack(ps))
	{
		printf("Nothing to delect!");
		return false;
	}
	else
	{
		ps->items[ps->top] = '\0';
		
		return true;
	}
}
bool Push(int item,Stack *ps)
{
	if (FullStack(ps))
	{
		printf("The stack is full!");
		return false;
	}
	else
	{
		ps->items[ps->top] = item;
		ps->top++;
		return true;
	}
}