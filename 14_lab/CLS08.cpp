#include "CLS08.h"


void Line::points() {
	cout << "����� ����������� ������ � ���� y: " << -b / a << "\n";
	cout << "����� ����������� ������  � ���� y: " << b << "\n";
	cout << endl;
}

void Line::print() {
	fstream f;
	cout << "y = " << a << " * x + " << b << endl;
	f << "y = " << a << " * x + " << b;
}

void Line::output() {
	fstream fout;
	fout << "y = " << a << " * x + " << b << endl;
	fout << "����� ����������� ������ � ���� x: " << -b / a << "\n";
	fout << "����� ����������� ������  � ���� y: " << b << "\n";
}

