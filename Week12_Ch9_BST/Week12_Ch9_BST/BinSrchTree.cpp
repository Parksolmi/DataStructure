#include "BinSrchTree.h"

void main()
{
	//���� Ž�� Ʈ�� ����
	BinSrchTree tree;

	// ���� ���� �׽�Ʈ
	tree.insert(new BinaryNode(35)); //��Ʈ ���� ���Եȴ�.
	//��Ʈ ��带 ��������(��Ʈ ��� �Ʒ��� �� ��尡 �ִٸ� �� �ش� ��带 ��������) ���� ������ �������� ū ������ �����ʿ� ���� �ȴ�.
	tree.insert(new BinaryNode(18));
	tree.insert(new BinaryNode(7));
	tree.insert(new BinaryNode(26));
	tree.insert(new BinaryNode(12));
	tree.insert(new BinaryNode(3));
	tree.insert(new BinaryNode(68));
	tree.insert(new BinaryNode(22));
	tree.insert(new BinaryNode(30));
	tree.insert(new BinaryNode(99));

	printf(" ����� ���� = %d\n", tree.getCount()); //���� Ž�� Ʈ���� ��� ���� ���
	printf(" �ܸ��� ���� = %d\n", tree.getLeafCount()); //���� Ž�� Ʈ���� �ܸ� ����� ���� ���
	printf(" Ʈ���� ���� = %d", tree.getHeight()); //���� Ž�� Ʈ���� ���� ���

	tree.inorder(); //���� ��ȸ ����
	tree.preorder(); //���� ��ȸ ����
	tree.postorder(); //���� ��ȸ ����
	tree.levelorder(); //���� ��ȸ ����

	tree.search(26); //��� 26 Ž��
	tree.search(25); //��� 25 Ž��

	// ���� ���� �׽�Ʈ
	printf(" ����: case 1 ==> ���  3 ����");
	tree.remove(3);
	tree.levelorder();
	printf(" ����: case 2 ==> ��� 68 ����");
	tree.remove(68);
	tree.levelorder();
	printf(" ����: case 3 ==> ��� 18 ����");
	tree.remove(18);
	tree.levelorder();
	printf(" ����: case 3 ==> ��� 35 ���� (��Ʈ ��� ����)");
	tree.remove(35);
	tree.levelorder();

	// ���� Ʈ�� ���� ���
	printf(" ����� ���� = %d\n", tree.getCount());
	printf(" �ܸ��� ���� = %d\n", tree.getLeafCount());
	printf(" Ʈ���� ���� = %d\n", tree.getHeight());
}
