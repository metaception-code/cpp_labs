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
	void about();         // Сведения о треугольнике
	double height();      // Высота
	double bisector();    // Биссектриса
	double perimeter();   // Периметр
	double area();        // Площадь
};

class CTetrahedron : public CETriangle{
private:
	double h;
public:
	CTetrahedron(double, double);
	CTetrahedron(const CTetrahedron&);
	CTetrahedron();
	void set_h(double);   // Высота тэтраэдра
	void about();         // Сведения о тэтраэдре

	double volume();      // Объем    
	double area();        // Площадь
};

void check(double, double);

//void middle_area(CETriangle* A, int  N);

void minimal_volume(CTetrahedron*, int);
#endif