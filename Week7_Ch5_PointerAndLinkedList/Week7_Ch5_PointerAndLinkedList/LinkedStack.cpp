#include "LinkedStack.h"

int main()
{
	LinkedStack stack;
	stack.push(new Node(2015130007, (char*)"홍길동", (char*)"컴퓨터공학과"));
	stack.push(new Node(2015130100, (char*)"이순신", (char*)"기계공학과"));
	stack.push(new Node(2015130135, (char*)"황희", (char*)"법학과"));
	stack.display();

	Node* node = stack.pop();
	printf("[Pop항목]\n");
	node->display();
	printf("\n");
	delete node;
	stack.display();
}