#include "INH08.h"


CETriangle::CETriangle(double a0) { 
	a = a0;
}

CETriangle::CETriangle(const CETriangle& AB) {
	a = AB.a;
}

CETriangle::CETriangle() {
	a = 0;
}

void CETriangle::set_a(double x) {
	this->a = x;
}

double CETriangle::height() {
	return (a * sqrt(3) / 2);
}

double CETriangle::bisector() {
	return (a * sqrt(3) / 2);
}

double CETriangle::perimeter() {
	return a * 3;
}

double CETriangle::area() {
	return (pow(a, 2) * sqrt(3) / 2);
}

void CETriangle::about() {
	cout << "����� ������� ��������������� ������������: " << a << endl;
	cout << "������ ��������������� ������������: " << height() << endl;
	cout << "�����������: " << bisector() << endl;
	cout << "��������: " << perimeter() << endl;
	cout << "�������: " << area() << endl << endl;
}


CTetrahedron::CTetrahedron(double a0, double h0) {
	a = a0;
	h = h0;
}

CTetrahedron::CTetrahedron(const CTetrahedron& AB) {
	a = AB.a;
	h = AB.h;
}

CTetrahedron::CTetrahedron() {
	a = 0;
	h = 0;
}

void CTetrahedron::set_h(double y) {
	this->h = y;
}

double CTetrahedron::area() {
	return ((a * a)*sqrt(3));
}

double CTetrahedron::volume() {
	return ((0.33333)*area() * h);
}

void CTetrahedron::about() {
	cout << "����� ������� ���������: " << a << endl;
	cout << "����� ������ ���������: " << h << endl;
	cout << "������� ���������: " << area() << endl;
	cout << "����� ���������: " << volume() << endl << endl;
}

void check(double x, double y) {
	if (x <= 0 && y <= 0) {
		cerr << "�������� ����� ������� � ������ �� <= 0!";
		exit(1);
	}

	if (x > 0 && y <= 0) {
		cerr << "�������� ������ �� <= 0!";
		exit(1);
	}

	if (x <= 0 && y > 0) {
		cerr << "�������� ����� ������� �� <= 0!";
		exit(1);
	}
}

void minimal_volume(CTetrahedron* B, int M) {
	int s = 0;
	int number = 0;
	int c = 0;
	for (int i = 0; i < M; i++) {
		if (B[i].volume() < B[s].volume()) {
			s = i;
			c = number;
		}
		number++;
	}
	cout << "����� ��������� � ����������� �������: " << c << ". �����: " << B[s].volume() << endl;
}