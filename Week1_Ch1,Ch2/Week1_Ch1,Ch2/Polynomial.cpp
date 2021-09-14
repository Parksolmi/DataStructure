#include "Polynomial.h"

void main()
{
	Polynomial pnm1, pnm2, pnm3;

	cout << "다항식1 작성 => " << endl; pnm1.read();
	cout << "다항식2 작성 => " << endl; pnm2.read();
	cout << "다항식1 : "; pnm1.display();
	cout << "다항식2 : "; pnm2.display();

	cout << endl;
	pnm3.add(pnm1, pnm2);
	cout << "----다항식 1과 2의 합----" << endl;
	pnm3.display();
	
	cout << endl;
	pnm3.mult(pnm1, pnm2);
	cout << "----다항식 1과 2의 곱----" << endl;
	pnm3.display();

	cout << endl;
	cout << "----부호바꾸기----" << endl;
	pnm1.negate();
	pnm2.negate();
	cout << "다항식1 : "; pnm1.display();
	cout << "다항식2 : "; pnm2.display();

	cout << endl;
	cout << "----최고차항이 0인지 검사----" << endl;
	cout << "다항식1 : "; pnm1.isZero();
	cout << "다항식2 : "; pnm2.isZero();
}
