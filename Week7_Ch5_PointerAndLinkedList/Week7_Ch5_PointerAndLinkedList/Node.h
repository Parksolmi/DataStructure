#include "Student.h"

class Node : public Student { //StudentŬ������ ��ӹ޾� ���
	Node* link; //��� ������ ��ü�� ���� ��带 ����Ű�� ������ �����̴�.

public:
	Node(int id = 0, char* name = (char*)"", char* dept = (char*)"") //������
		: Student(id, name, dept) {
		link = NULL;
	}
	~Node(void) {} //�Ҹ���
	Node* getLink() { return link; } //���� ��尡 ����Ű�� �ִ� �����͸� get�ϴ� �Լ�
	void setLink(Node* p) { link = p; } //���� ��尡 ����Ű�� �ִ� �����͸� set�ϴ� �Լ�
};