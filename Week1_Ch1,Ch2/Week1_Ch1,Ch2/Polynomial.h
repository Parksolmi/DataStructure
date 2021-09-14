#pragma once
#include <iostream>

using namespace std;
const int MAX_DEGREE = 80; //���׽��� ó�� ������ �ִ� ����+1

class Polynomial
{
private:
	int degree; //�ְ����װ��
	float coef[]; //���׽��� ������ �迭
				  //�迭�� �ε����� ���׽��� ����

public:
	Polynomial() //������
	{
		degree = 0;
	};
	void read() //���׽��� �Է��ϴ� �Լ�
	{
		cout << "���׽��� �ְ� ���� : ";
		cin >> degree;
		cout << "�� ���� ���(������������ �Է�) : ";
		for (int i = degree; i>=0; i--)
		{
			cin >> coef[i];
		}
		cout << endl;
	};
	bool isZero() //�ְ������� 0���� Ȯ���ϴ� �Լ�
	{
		return degree == 0;
	};
	void negate() //��� ����� ��ȣ�� �ٲٴ� �Լ�
	{
		for (int i = 0; i <= degree; i++)
		{
			coef[i] *= (-1);
		}
	};
	void add(Polynomial p1, Polynomial p2) //���׽��� ���ϴ� �Լ�
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
	void mult(Polynomial p1, Polynomial p2) //���׽��� ���ϴ� �Լ�
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
	void display() //���׽��� ȭ�鿡 ����ϴ� �Լ�
	{
		for (int i = degree; i >= 0; i--) //�ְ����׺��� ���
		{
			cout << coef[i] << "x^" << i << " + ";
		}
	};

};
