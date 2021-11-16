#pragma once
#include <stdio.h>

class BinaryNode
{
protected:
	int			data; //노드의 데이터를 저장하는 int형 변수
	BinaryNode* left; //왼쪽 노드를 가리키는 자체포인터 left변수
	BinaryNode* right; //오른쪽 노드를 가리키는 자체포인터 right변수

public:
	//생성자 : 데이터는 0, 양쪽 노드는 NULL로 초기화한다.
	BinaryNode(int val = 0, BinaryNode* l = NULL, BinaryNode* r = NULL)
		: data(val), left(l), right(r) { }
	//소멸자
	~BinaryNode() { }

	//매개변수로 받은 변수로 노드의 데이터를 set하는 함수
	void		setData(int val) { data = val; } 
	//매개변수로 받은 포인터 변수로 노드의 왼쪽 포인터를 set하는 함수
	void		setLeft(BinaryNode* l) { left = l; }
	//매개변수로 받은 포인터 변수로 노드의 오른쪽 포인터를 set하는 함수
	void		setRight(BinaryNode* r) { right = r; }
	//노드의 데이터를 가져오는 함수
	int			getData() { return data; }
	//노드의 왼쪽 노드를 가져오는 함수
	BinaryNode* getLeft() { return left; }
	//노드의 오른쪽 노드를 가져오는 함수
	BinaryNode* getRight() { return right; }
	//단말노드(자식이 없는 노드)인지 아닌지 확인하는 함수
	bool		isLeaf() { return left == NULL && right == NULL; }
};

