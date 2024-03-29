#include "StackType.h"

StackType::StackType()
{
	top = -1;
}

bool StackType::IsFull() const
{
	if (top == 4)
		return true;
	return false;
}

bool StackType::IsEmpty() const
{
	if (top == -1)
		return true;
	return false;
}

void StackType::Push(char item)
{
	if (IsFull())
		throw FullStack();
	top += 1;
	items[top] = item;
}

void StackType::Pop()
{
	if (IsEmpty())
		throw EmptyStack();
	top -= 1;
}

char StackType::Top()
{
	if (IsEmpty())
		throw EmptyStack();
	return items[top];
}