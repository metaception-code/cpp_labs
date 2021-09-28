#include"INH08.h"
/*
������ �.�. ��.18-1, �.08.
INH08. ������� ����� ��������������� ����������� (class CETriangle), ���� ������ � ����� ������� a.
������������� � ������ ������ ���������� � ������ �������� � ������ � ������, �����������, ���������, �������.

������� ����������� ����� � ��������� (class CTetrahedron), �������� � ����� ����� ����������� ������ ������, ����������� ������ ������� ������� � ������ �������� � ������.

��������� ��������� ������������� ������ � ����� ��������:
�) ���� N �������������� �������������; ����� ������� ������� ���� �������������;
�) ���� M �������; ����� �������� � ���������� �������.
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
		cerr << "������ ������ �����";
		return -1;
	}
	fin1 >> N;
	cout << "���������� ���������: " << N << endl;
	A = new CETriangle[N];

	double x, y;
	for (int i = 0; i < N; i++) {
		fin1 >> x;
		if (x <= 0) {
			cerr << "������! �������� ����� ������� �������� �� ����� ���� ������ ��� ����� ����!";
			return -1;
		}
		A[i].set_a(x);
	}
	fin1.close();
	

	fstream fin2;
	fin2.open("input08(1).txt", ios_base::in);
	if (!fin2) {
		cerr << "������ ������ �����";
		return -1;
	}

	fin2 >> M;
	B = new CTetrahedron [M];

	cout << "���������� ����������������: " << M << endl;

	for (int i = 0; i < M; i++) {

		fin2 >> x >> y;

		B[i].set_a(x);
		B[i].set_h(y);

	}
	fin2.close();

	cout << "������� �): " << endl << endl;

	
	double middle = 0;

	for (int i = 0; i < N; ++i) {
		double sum = 0;
		A[i].about();
		 sum = A[i].area();
		 middle += sum;
		if (i == N - 1) {
			cout << "������� ������� �������������: " << middle / N;
		}
		cout << endl;
	}



	//middle_area(A, N);
	cout << endl << endl;

	cout << "������� �): " << endl << endl;

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
