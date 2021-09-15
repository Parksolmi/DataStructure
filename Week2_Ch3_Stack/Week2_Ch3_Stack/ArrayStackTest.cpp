#include "ArrayStack.h"

int main()
{
	ArrayStack stack; //°´Ã¼ »ý¼º
	for (int i = 1; i <= 10; i++)
	{
		stack.push(i);
	}
	stack.display();
	stack.pop();
	stack.pop();
	stack.pop();
	stack.display();
}