#include "LinkedList.h"
int main()
{
	LinkedList	list, list2;

	list.insert( 0, new Node(10) );	
	list.insert( 0, new Node(20) );
	list.insert( 1, new Node(30) );
	list.insert( list.size(), new Node(40) );
	list.insert( 2, new Node(50) );
	list.display((char*)"List(??)");

	list.reverse();
	list.display((char*)"List(??)");

	list2.insert(0, new Node(70));
	list2.insert(1, new Node(80));
	list2.insert(2, new Node(90));
	list2.display((char*)"List(that)");

	list.merge(&list2);
	list.display((char*)"List(reverse+that)");
	list2.display((char*)"List(that)");

	list.clear();
	list2.clear();
	list.display((char*)"List(??)");
	return 0;
}

