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

	// Проверка перпендикулярности прямых. Если произведение угловых коэффициентов (а1*а2) равно -1, прямые перпендикулярны.
	bool operator!=(Line y1)  // 
	{
		return a * y1.a == -1;
	}

	// Определение угла между 2-мя прямыми
	double operator%(Line y1) 
	{
		 double temp = abs(atan(a) - atan(y1.a));
		 return temp * 180 / 3.1415;
	}

	// Метод вывода прямой в консоль
	void print();

	// Метод вывода прямой в файл
	void output();

	// Метод определения точек пересечения с осями
	void points();
};

#endif