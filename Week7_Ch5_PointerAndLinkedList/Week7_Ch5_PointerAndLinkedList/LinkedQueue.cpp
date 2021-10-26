// 05장-LinkedQueueMain.cpp
#include "LinkedQueue.h"

void main()
{
	LinkedQueue que; //큐 생성
	for (int i = 1; i < 10; i++) 
		que.enqueue(new Node(i)); //큐에 1부터 9까지 데이터 삽입
	que.display(); //큐에 있는 전체 데이터 보여주기
	delete que.dequeue(); //큐에 있는 데이터 삭제
	delete que.dequeue(); //큐에 있는 데이터 삭제
	delete que.dequeue(); //큐에 있는 데이터 삭제
	que.display(); //큐에 있는 데이터 보여주기
}
