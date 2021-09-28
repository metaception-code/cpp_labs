#ifndef 	NEW_FORMS_H_INCLUDED
#define 	NEW_FORMS_H_INCLUDED

#include <iostream>
#include <windows.h>
#include <fstream>
#include <cmath>

using namespace std;

class Line
{
	double a, b;
public:
	Line(double a, double b)
	{
		this->a = a;
		this->b = b;
	}

	// �������� ������������������ ������. ���� ������������ ������� ������������� (�1*�2) ����� -1, ������ ���������������.
	bool operator!=(Line y1)  // 
	{
		return a * y1.a == -1;
	}

	// ����������� ���� ����� 2-�� �������
	double operator%(Line y1) 
	{
		 double temp = abs(atan(a) - atan(y1.a));
		 return temp * 180 / 3.1415;
	}

	// ����� ������ ������ � �������
	void print();

	// ����� ������ ������ � ����
	void output();

	// ����� ����������� ����� ����������� � �����
	void points();
};

#endif