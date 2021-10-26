#include "LinkedStack.h"

int main()
{
	LinkedStack stack; //���� ����
	stack.push(new Node(2015130007, (char*)"ȫ�浿", (char*)"��ǻ�Ͱ��а�")); //������ push
	stack.push(new Node(2015130100, (char*)"�̼���", (char*)"�����а�")); //������ push
	stack.push(new Node(2015130135, (char*)"Ȳ��", (char*)"���а�")); //������ push
	stack.display(); //���ÿ� �ִ� �����͸� �����ش�.

	Node* node = stack.pop(); //������ �� ���� �ִ� �����͸� pop�Ͽ� node�� �����Ѵ�.
	printf("[Pop�׸�]\n");
	node->display(); //node�� display�Ѵ�.
	printf("\n");
	delete node; //node�� �����.
	stack.display(); //���ÿ� ���� �����͸� display�Ѵ�.
}