#pragma once
#include <stdio.h>
#include <string.h>
#define MAX_STRING	100

class Student
{
	int		id;					// �й�
	char	name[MAX_STRING];	// �̸�
	char	dept[MAX_STRING];	// �Ҽ� �а�
public:
	Student(int i = 0, char* nam = (char*)"", char* dep = (char*)"") {
		set(i, nam, dep);
	}
	void set(int i, char* nam, char* dep) {
		id = i;
		strcpy_s(name, nam);
		strcpy_s(dept, dep);
	}
	void display() {
		printf(" �й�:%-15d ����:%-10s �а�:%-20s\n", id, name, dept);
	}
};
