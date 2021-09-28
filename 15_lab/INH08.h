#ifndef NEW_FORMS_H_INCLUDED
#define NEW_FORMS_H_INCLUDED

#include <iostream>
#include <fstream>
#include <windows.h>
#include <cstdlib>
#include <cmath>

using namespace std;

class CETriangle {
protected:
	double a;
public:
	CETriangle(double);
	CETriangle(const CETriangle&);
	CETriangle();
	void set_a(double);
	void about();         // �������� � ������������
	double height();      // ������
	double bisector();    // �����������
	double perimeter();   // ��������
	double area();        // �������
};

class CTetrahedron : public CETriangle{
private:
	double h;
public:
	CTetrahedron(double, double);
	CTetrahedron(const CTetrahedron&);
	CTetrahedron();
	void set_h(double);   // ������ ���������
	void about();         // �������� � ���������

	double volume();      // �����    
	double area();        // �������
};

void check(double, double);

//void middle_area(CETriangle* A, int  N);

void minimal_volume(CTetrahedron*, int);
#endif