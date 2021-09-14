#pragma once
#include <iostream>

using namespace std;
const int MAX_DEGREE = 80; //다항식의 처리 가능한 최대 차수+1

class Polynomial
{
private:
	int degree; //최고차항계수
	float coef[]; //다항식을 저장할 배열
				  //배열의 인덱스가 다항식의 차수

public:
	Polynomial() //생성자
	{
		degree = 0;
	};
	void read() //다항식을 입력하는 함수
	{
		cout << "다항식의 최고 차수 : ";
		cin >> degree;
		cout << "각 항의 계수(내림차순으로 입력) : ";
		for (int i = degree; i>=0; i--)
		{
			cin >> coef[i];
		}
		cout << endl;
	};
	bool isZero() //최고차항이 0인지 확인하는 함수
	{
		return degree == 0;
	};
	void negate() //모든 계수의 부호를 바꾸는 함수
	{
		for (int i = 0; i <= degree; i++)
		{
			coef[i] *= (-1);
		}
	};
	void add(Polynomial p1, Polynomial p2) //다항식을 더하는 함수
	{
		if (p1.degree > p2.degree)
		{
			*this = p1;
			for (int i = 0; i < p2.degree; i++)
			{
				coef[i] += p2.coef[i];
			}
		}
		else
		{
			*this = p2;
			for (int i = 0; i < degree; i++)
			{
				coef[i] += p1.coef[i];
			}
		}
	};
	void mult(Polynomial p1, Polynomial p2) //다항식을 곱하는 함수
	{
		Polynomial temp1, temp2;
		Polynomial temp = temp1;
		for (int i = 0; i < p1.degree; i++)
		{
			for (int j = 0; j < p2.degree; j++)
			{
				temp.coef[i + j] = p1.coef[i] * p2.coef[j];
			}
			temp = temp2;
		}
		add(temp1, temp2);
	};
	void display() //다항식을 화면에 출력하는 함수
	{
		for (int i = degree; i >= 0; i--) //최고차항부터 출력
		{
			cout << coef[i] << "x^" << i << " + ";
		}
	};

};
