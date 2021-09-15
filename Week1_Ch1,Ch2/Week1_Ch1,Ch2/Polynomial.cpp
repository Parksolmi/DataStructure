#include "Polynomial.h"

int main()
{
	Polynomial pnm1, pnm2, pnm3;

	cout << "���׽�1 �ۼ� => " << endl; pnm1.read();
	cout << "���׽�2 �ۼ� => " << endl; pnm2.read();
	cout << "���׽�1 : "; pnm1.display(); cout << endl;
	cout << "���׽�2 : "; pnm2.display();

	cout << endl << endl;
	pnm3.add(pnm1, pnm2);
	cout << "----���׽� 1�� 2�� ��----" << endl;
	pnm3.display();
	
	cout << endl <<endl;
	pnm3.mult(pnm1, pnm2);
	cout << "----���׽� 1�� 2�� ��----" << endl;
	pnm3.display();

	cout << endl << endl;
	cout << "----��ȣ�ٲٱ�----" << endl;
	pnm1.negate();
	pnm2.negate();
	cout << "���׽�1 : "; pnm1.display(); cout << endl;
	cout << "���׽�2 : "; pnm2.display();

	cout << endl << endl;
	cout << "----�ְ������� 0���� �˻�----" << endl;
	bool result = pnm1.isZero();
	cout << "���׽�1 : " << boolalpha << result << endl;
	result = pnm2.isZero();
	cout << "���׽�2 : " << boolalpha << result << endl;
}
