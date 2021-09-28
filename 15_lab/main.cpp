#include"INH08.h"
/*
Рачков М.С. гр.18-1, в.08.
INH08. Создать класс «равносторонний треугольник» (class CETriangle), член класса — длина стороны a.
Предусмотреть в классе методы вычисления и вывода сведений о фигуре — высоты, биссектрисы, периметра, площади.

Создать производный класс — «тетраэдр» (class CTetrahedron), добавить в класс метод определения объема фигуры, перегрузить методы расчета площади и вывода сведений о фигуре.

Дополнить программу демонстрацией работы с этими классами:
а) дано N равносторонних треугольников; найти среднюю площадь всех треугольников;
б) дано M пирамид; найти тетраэдр с наименьшим объемом.
*/

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

    int N;
	int M;
	CETriangle* A;
	CTetrahedron* B;



	fstream fin1;
	fin1.open("input08.txt", ios_base::in);
	if (!fin1) {
		cerr << "Ошибка чтения файла";
		return -1;
	}
	fin1 >> N;
	cout << "Количество квадратов: " << N << endl;
	A = new CETriangle[N];

	double x, y;
	for (int i = 0; i < N; i++) {
		fin1 >> x;
		if (x <= 0) {
			cerr << "Ошибка! Значение длины стороны квадрата не может быть меньше или равно нулю!";
			return -1;
		}
		A[i].set_a(x);
	}
	fin1.close();
	

	fstream fin2;
	fin2.open("input08(1).txt", ios_base::in);
	if (!fin2) {
		cerr << "Ошибка чтения файла";
		return -1;
	}

	fin2 >> M;
	B = new CTetrahedron [M];

	cout << "Количество параллелепипедов: " << M << endl;

	for (int i = 0; i < M; i++) {

		fin2 >> x >> y;

		B[i].set_a(x);
		B[i].set_h(y);

	}
	fin2.close();

	cout << "Задание а): " << endl << endl;

	
	double middle = 0;

	for (int i = 0; i < N; ++i) {
		double sum = 0;
		A[i].about();
		 sum = A[i].area();
		 middle += sum;
		if (i == N - 1) {
			cout << "Средняя площадь треугольников: " << middle / N;
		}
		cout << endl;
	}



	//middle_area(A, N);
	cout << endl << endl;

	cout << "Задание б): " << endl << endl;

	for (int i = 0; i < M; ++i) {
		B[i].about();
		cout << endl;
	}

	minimal_volume(B, M);
	cout << endl << endl;

	delete[]A;
	delete[]B;

	system("PAUSE");
	return 0;
}
