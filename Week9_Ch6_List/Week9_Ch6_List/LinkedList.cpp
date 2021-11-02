#include "LinkedList.h"

int main()
{
	LinkedList	list;

	list.insert(0, new Node(20));
	list.insert(0, new Node(20));
	list.insert(1, new Node(30));
	list.insert(list.size(), new Node(40));
	list.insert(2, new Node(50));
	list.display();
	//�������� 1, 2��
	cout << "������ �� : " << list.calcSum() << endl;
	cout << "20�� �� : " << list.countNode(20) << endl;


	list.remove(2);
	list.remove(list.size() - 1);
	list.remove(0);
	list.replace(1, new Node(90));
	list.display();

	list.clear();
	list.display();
}

