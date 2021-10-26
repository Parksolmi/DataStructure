#include "Student.h"

class Node : public Student { //Student클래스를 상속받아 사용
	Node* link; //노드 포인터 객체로 다음 노드를 가리키는 포인터 변수이다.

public:
	Node(int id = 0, char* name = (char*)"", char* dept = (char*)"") //생성자
		: Student(id, name, dept) {
		link = NULL;
	}
	~Node(void) {} //소멸자
	Node* getLink() { return link; } //현재 노드가 가리키고 있는 데이터를 get하는 함수
	void setLink(Node* p) { link = p; } //현재 노드가 가리키고 있는 데이터를 set하는 함수
};