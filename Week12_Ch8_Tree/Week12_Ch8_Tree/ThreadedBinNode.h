#pragma once
#include <stdio.h>

//스레드 이진트리의 노드를 위한 노드클래스
class ThreadedBinNode
{
protected:
	int			data; //이진 트리의 데이터를 넣을 변수
	ThreadedBinNode* left; //이진 트리의 왼쪽 노드를 가리킬 자체 포인터 변수
	ThreadedBinNode* right; //이진 트리의 오른쪽 노드를 가리킬 자체 포인터 변수
public:
	bool		bThread; //스레드 연결 여부를 확인할 논리형 변수
	ThreadedBinNode(int val = 0, ThreadedBinNode* l = NULL, ThreadedBinNode* r = NULL, bool bTh = false) //생성자
		// : 노드의 데이터는 0으로, 왼쪽과 오른쪽 노드는 각각 NULL로, 스레드 연결을 나타내는 변수는 false로 초기화한다.
		: data(val), left(l), right(r), bThread(bTh) { }

	int	 getData() { return data; } //노드의 데이터를 get해오는 함수
	void setRight(ThreadedBinNode* r) { right = r; } //스레드를 설정하는 함수 : 해당 노드의 오른쪽 링크가 매개변수로 받은 값을 가리키도록 한다.
	ThreadedBinNode* getLeft() { return left; } //왼쪽 노드를 get하는 함수
	ThreadedBinNode* getRight() { return right; } //오른쪽 노드를 get하는 함수
};