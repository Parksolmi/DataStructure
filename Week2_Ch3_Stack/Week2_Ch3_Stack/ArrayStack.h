#pragma once
#include <iostream>

using namespace std;

inline void error(char* message) //오류 처리
{
	cout << message;
	exit(1);
}

const int MAX_STACK_SIZE = 20;

class ArrayStack
{
private:
	int top; //배열에 가장 끝에 있는 요소의 인덱스
	int data[MAX_STACK_SIZE]; //요소를 저장할 배열

public:
	ArrayStack() //생성자
	{
		top = -1;
	} 
	~ArrayStack() {} //소멸자
	bool isEmpty() //스택이 비었는지 확인하는 함수
	{
		if (top == -1)
		{
			return true;
		}
		else
			return false;
	}
	bool isFull() //스택이 꽉 차있는지 확인하는 함수
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
	void push(int element) //요소를 배열에 넣는 함수
	{
		if (isFull())
		{
			error((char*)"스택 포화 에러");
		}
		else
		{
			top++;
			data[top] = element;
		}
	}
	void pop() //배열의 맨 끝에 있는 요소를 삭제하는 함수
	{
		if (isEmpty())
		{
			error((char*)"스택 공백 에러");
		}
		else
		{
			top--;
		}
	}
	int peek() //배열의 맨 끝에 있는 요소를 반환하는 함수
	{
		if (isEmpty())
		{
			error((char*)"스택 공백 에러");
		}
		return data[top];
	}
	void display()
	{
		cout << "[스택 항목의 수 : " << top+1 << " ]" << endl;
		for (int i = 0; i <= top; i++)
		{
			cout << data[i] << " ";
		}
		cout << endl;
	}
};
