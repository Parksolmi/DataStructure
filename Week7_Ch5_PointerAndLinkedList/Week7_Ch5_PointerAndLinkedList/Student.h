#pragma once
#include <stdio.h>
#include <string.h>
#define MAX_STRING	100

class Student
{
	int		id;					// 학번
	char	name[MAX_STRING];	// 이름
	char	dept[MAX_STRING];	// 소속 학과
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
		printf(" 학번:%-15d 성명:%-10s 학과:%-20s\n", id, name, dept);
	}
};
