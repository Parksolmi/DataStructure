#pragma once
#include <iostream>

using namespace std;

#define MAX_QUEUE_SIZE 10
inline void error(char* str)
{
	cout << str << endl;
	exit(1);
}

class CircularQueue
{
protected :
	int front; //ù ��° ��� ���� ��ġ�� ����Ű�� ����
	int rear;  //������ ����� ��ġ�� ����Ű�� ����
	int data[MAX_QUEUE_SIZE]; //�迭�� ������ ť

public :
	CircularQueue() { front = rear = 0; } //������ - ť�� front�� rear��� 0���� ����ϹǷ� 0���� �ʱ�ȭ.
	bool isEmpty() { return front == rear; } //������� Ȯ���ϴ� �Լ�
	bool isFull() { return front == (rear + 1) % MAX_QUEUE_SIZE; } //��ȭ���� Ȯ���ϴ� �Լ�
	void enqueue(int val) //ť�� ���(val) �����ϴ� �Լ�
	{
		if (isFull()) //��ȭ���¸� ��Ҹ� ������ �� �����Ƿ� �����޼����� ����Ѵ�.
		{
			error((char*)"��ȭ���¿����߻� : ��Ҹ� ������ �� ����");
		}
		else //��ȭ���°� �ƴϸ� ��� ����
		{
			rear = (rear + 1) % MAX_QUEUE_SIZE; //����ť�̱� ������ �ܼ��� ������Ű�°� �ƴ϶� 
												//%�����ڷ� ���� �ε����� ���ư� �� �ֵ��� ������ �Ѵ�.
			data[rear] = val;
		}
	}
	int dequeue() //ť�� ��Ҹ� �����ϴ� �Լ� - ���� ���� ��Һ��� �����Ѵ�.
	{
		if (isEmpty()) //������¸� ������ ��Ұ� �����Ƿ� �����޼����� ����Ѵ�.
		{
			error((char*)"������¿����߻� : ��Ҹ� ������ �� ����");
		}
		else //������°� �ƴϸ� ��� ���� - front�� ��ġ�� �ű����ν� ��Ҹ� �����ϴ� ȿ���� �����.
		{
			front = (front + 1) % MAX_QUEUE_SIZE;
			return data[front];
		}
	}
	int peek() //ù �׸��� ť���� ���� �ʰ� ��ȯ�ϴ� �Լ�
	{
		if (isEmpty()) //��������̸� Ȯ���� �׸� �����Ƿ� ���� �޼����� ����Ѵ�.
		{
			error((char*)"ť�� ��������Դϴ�");
		}
		else //������°� �ƴϸ� front�ٷ� �տ� �����͸� ��ȯ�Ѵ�.
			 //cf). �׻� front�ٷ� ���� �����Ͱ� ù �׸��̴�.
		{
			return data[(front + 1) % MAX_QUEUE_SIZE];
		}
	}
	void display()
	{
		cout << "ť�� ���� : ";
		int maxi = (front < rear) ? rear : rear + MAX_QUEUE_SIZE; //���� �ڿ� �ִ� �������� ��ġ�� ���� 
															   	  //for���� �� �� ������ �� �� ������ �ִ� ����
		for (int i = front + 1; i <= maxi; i++) //front���� maxi���� �����͸� ��� ���.
		{
			cout << "[ " << data[i % MAX_QUEUE_SIZE] << " ]"  << " ";
		}
		cout << endl;
	}
};
