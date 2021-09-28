#include "CLS08.h"


void Line::points() {
	cout << "Точка пересечения прямой с осью y: " << -b / a << "\n";
	cout << "Точка пересечения прямой  с осью y: " << b << "\n";
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
	fout << "Точка пересечения прямой с осью x: " << -b / a << "\n";
	fout << "Точка пересечения прямой  с осью y: " << b << "\n";
}

