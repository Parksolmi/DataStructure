#include "CircularQueue.h"

int main()
{
	CircularQueue que; //CircularQueue.h�� �ִ� CircularQueueŬ������ ��ü�� �����Ͽ� ����ť �ڷᱸ���� �����Ѵ�.

	//for������ ť�� 1��° �ε������� 9��° �ε������� 1~9���� �� �����͸� �����Ѵ�.
	for (int i = 1; i < 10; i++)
	{
		que.enqueue(i);
	}

	que.display(); //display�Լ��� �̿��Ͽ� ť�� ���ԵǾ� �ִ� �����͸� ��� �����ش�.
	que.dequeue(); //dequeue�Լ��� �̿��Ͽ� ť�� �� ���� �����͸� �����Ѵ�.
	que.dequeue();
	que.dequeue();
	que.display(); //dequeue�Լ��� 3���� �տ� �ִ� �׸��� �����߱� ������ 
				   //4��° �ε������� 9��° �ε������� 4~9������ ���ڰ� �����ִ�.
				   //display�Լ��� �̿��Ͽ� ť�� �����ִ� �����͸� ��� �����ش�.
}