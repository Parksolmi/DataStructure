#include "LinkedStack.h"

int main()
{
	LinkedStack stack;
	stack.push(new Node(2015130007, (char*)"ȫ�浿", (char*)"��ǻ�Ͱ��а�"));
	stack.push(new Node(2015130100, (char*)"�̼���", (char*)"�����а�"));
	stack.push(new Node(2015130135, (char*)"Ȳ��", (char*)"���а�"));
	stack.display();

	Node* node = stack.pop();
	printf("[Pop�׸�]\n");
	node->display();
	printf("\n");
	delete node;
	stack.display();
}