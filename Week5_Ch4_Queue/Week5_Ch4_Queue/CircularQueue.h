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
	int front; //첫 번째 요소 앞의 위치를 가리키는 변수
	int rear;  //마지막 요소의 위치를 가리키는 변수
	int data[MAX_QUEUE_SIZE]; //배열로 구현한 큐

public :
	CircularQueue() { front = rear = 0; } //생성자 - 큐는 front와 rear모두 0에서 출발하므로 0으로 초기화.
	bool isEmpty() { return front == rear; } //공백상태 확인하는 함수
	bool isFull() { return front == (rear + 1) % MAX_QUEUE_SIZE; } //포화상태 확인하는 함수
	void enqueue(int val) //큐에 요소(val) 삽입하는 함수
	{
		if (isFull()) //포화상태면 요소를 삽입할 수 없으므로 에러메세지를 출력한다.
		{
			error((char*)"포화상태에러발생 : 요소를 삽입할 수 없음");
		}
		else //포화상태가 아니면 요소 삽입
		{
			rear = (rear + 1) % MAX_QUEUE_SIZE; //원형큐이기 때문에 단순히 증가시키는게 아니라 
												//%연산자로 앞의 인덱스로 돌아갈 수 있도록 만들어야 한다.
			data[rear] = val;
		}
	}
	int dequeue() //큐의 요소를 삭제하는 함수 - 제일 앞의 요소부터 삭제한다.
	{
		if (isEmpty()) //공백상태면 삭제할 요소가 없으므로 에러메세지를 출력한다.
		{
			error((char*)"공백상태에러발생 : 요소를 삭제할 수 없음");
		}
		else //공백상태가 아니면 요소 삭제 - front의 위치를 옮김으로써 요소를 삭제하는 효과를 만든다.
		{
			front = (front + 1) % MAX_QUEUE_SIZE;
			return data[front];
		}
	}
	int peek() //첫 항목을 큐에서 빼지 않고 반환하는 함수
	{
		if (isEmpty()) //공백상태이면 확인할 항목도 없으므로 에러 메세지를 출력한다.
		{
			error((char*)"큐가 공백상태입니다");
		}
		else //공백상태가 아니면 front바로 앞에 데이터를 반환한다.
			 //cf). 항상 front바로 앞의 데이터가 첫 항목이다.
		{
			return data[(front + 1) % MAX_QUEUE_SIZE];
		}
	}
	void display()
	{
		cout << "큐의 내용 : ";
		int maxi = (front < rear) ? rear : rear + MAX_QUEUE_SIZE; //가장 뒤에 있는 데이터의 위치에 따라 
															   	  //for문을 몇 번 돌려야 할 지 결정해 주는 변수
		for (int i = front + 1; i <= maxi; i++) //front부터 maxi까지 데이터를 모두 출력.
		{
			cout << "[ " << data[i % MAX_QUEUE_SIZE] << " ]"  << " ";
		}
		cout << endl;
	}
};
