#pragma once

#include <stdio.h>

class Node
{
	Node* link; //노드 포인터 객체
	int		data; //데이터(int형)

public:
	Node(int val = 0) : data(val), link(NULL) { } //생성자 : data는 0으로 설정, link는 NULL을 가리키도록 함
	Node* getLink() { return link; } //노드를 get하는 함수
	void setLink(Node* next) { link = next; } //노드를 set하는 함수
	void display() { printf(" <%2d>", data); } //큐에 들어 있는 데이터(int)를 display하는 함수
};
