#pragma once
#include <iostream>

using namespace std;

inline void error(char* message) //���� ó��
{
	cout << message;
	exit(1);
}

const int MAX_STACK_SIZE = 20;

class ArrayStack
{
private:
	int top; //�迭�� ���� ���� �ִ� ����� �ε���
	int data[MAX_STACK_SIZE]; //��Ҹ� ������ �迭

public:
	ArrayStack() //������
	{
		top = -1;
	} 
	~ArrayStack() {} //�Ҹ���
	bool isEmpty() //������ ������� Ȯ���ϴ� �Լ�
	{
		if (top == -1)
		{
			return true;
		}
		else
			return false;
	}
	bool isFull() //������ �� ���ִ��� Ȯ���ϴ� �Լ�
	{
		if (top == MAX_STACK_SIZE - 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void push(int element) //��Ҹ� �迭�� �ִ� �Լ�
	{
		if (isFull())
		{
			error((char*)"���� ��ȭ ����");
		}
		else
		{
			top++;
			data[top] = element;
		}
	}
	void pop() //�迭�� �� ���� �ִ� ��Ҹ� �����ϴ� �Լ�
	{
		if (isEmpty())
		{
			error((char*)"���� ���� ����");
		}
		else
		{
			top--;
		}
	}
	int peek() //�迭�� �� ���� �ִ� ��Ҹ� ��ȯ�ϴ� �Լ�
	{
		if (isEmpty())
		{
			error((char*)"���� ���� ����");
		}
		return data[top];
	}
	void display()
	{
		cout << "[���� �׸��� �� : " << top+1 << " ]" << endl;
		for (int i = 0; i <= top; i++)
		{
			cout << data[i] << " ";
		}
		cout << endl;
	}
};
