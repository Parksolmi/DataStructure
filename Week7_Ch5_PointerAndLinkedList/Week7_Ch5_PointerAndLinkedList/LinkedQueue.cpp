// 05��-LinkedQueueMain.cpp
#include "LinkedQueue.h"

void main()
{
	LinkedQueue que; //ť ����
	for (int i = 1; i < 10; i++) 
		que.enqueue(new Node(i)); //ť�� 1���� 9���� ������ ����
	que.display(); //ť�� �ִ� ��ü ������ �����ֱ�
	delete que.dequeue(); //ť�� �ִ� ������ ����
	delete que.dequeue(); //ť�� �ִ� ������ ����
	delete que.dequeue(); //ť�� �ִ� ������ ����
	que.display(); //ť�� �ִ� ������ �����ֱ�
}
