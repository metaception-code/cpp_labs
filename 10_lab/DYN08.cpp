#include "DYN08.h"


void Multiply_Matrix(double** P1, double** P, double** E, double m)
{
	for (int i = 0; i < 3; i++) 
	{
		for (int j = 0; j < m; j++)
		{
			P1[i][j] = 0;
			for (int k = 0; k < 3; k++)
			{
				P1[i][j] += P[k][j] * E[i][k];
			}
		}
	}
}

void Rotate(double** P2, double** P1, double** R, double m)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < m; j++) 
		{
			P2[i][j] = 0;
			for (int k = 0; k < 3; k++) 
			{
				P2[i][j] += P1[k][j] * R[i][k];
			}
		}
	}
}

void Multiply_Matrix2(double** P4, double** E, double** P2, double m)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < m; j++)
		{
			P4[i][j] = 0;
			for (int k = 0; k < 3; k++)
			{
				P4[i][j] += P2[k][j] * E[i][k];
			}
		}
	}
}

void Output_E(int m, double **E)
{
	cout << endl;

	for (int j = 0; j < m; j++)
	{
		cout << endl;

		for (int i = 0; i < 3; i++)
		{
			cout << E[i][j] << " ";
		}
	}

	cout << endl;
}

void Transfer(int m, int h, double** FM, double** P4)
{
	double** TM = new double* [3];

	for (int i = 0; i < 3; i++)
	{
		TM[i] = new double[m];
	}


	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < m + 1; j++)
		{
			if (i == j)
				TM[i][j] = 1;
			else
				TM[i][j] = 0;

		}
	}	
	

		TM[0][m-1] = h;


		for (int i = 0; i < 3; i++)
		{
			FM[i] = new double[m];
		}


		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < m; j++)
			{
				FM[i][j] = 0;
				for (int k = 0; k < 3; k++)
				{
					FM[i][j] += P4[k][j] * TM[i][k];
				}
			}
		}

		for (int j = 0; j < m; j++)
		{
			cout << endl;

			for (int i = 0; i < 3; i++)
			{
				cout << FM[i][j] << " ";
			}
		}

	
}

void Output_Final_Matrix(int m, double** FM, double** P4) 
{

	fstream f;

	f.open("output.txt", ios_base::out);

	f << "1)" << endl;

	for (int j = 0; j < m; j++)
	{
		f << endl;

		for (int i = 0; i < 3; i++)
		{
			f << P4[i][j] << " ";
		}
	}

	f << endl;

	f << "2)" << endl;

	for (int j = 0; j < m; j++)
	{
		f << endl;

		for (int i = 0; i < 3; i++)
		{
			f << FM[i][j] << " ";
		}
	}
	
	f.close();
}



/*
	void Console_Input()
	{
		cout << "Enter vertex amount \n";
		cin >> m;

		for (int j = 0; j < m; j++)
		{
			cout << "Enter X, Y: " << endl;
			cin >> P[0][j];
			cin >> P[1][j];
			cout << endl;
		}
			for (int j = 0; j < m; j++) // Присваиваем 1 столбцу нормирующего коэффициента
			{
				P[2][j] = 1;
			}
	}
*/

/*
	E *int **E = new int*[2]; // Создаем единичную матрицу

	for (int i = 0; i < 3; i++)
	{
		E[i] = new int[m]; // Создание массива столбцов
	}


	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < m+1; j++)
		{
			if (i == j ) // Диагональные элементы
				E[i][j] = 1;
			else
				E[i][j] = 0;
			cout << E[i][j] << " ";
		}
		cout << endl;
	}

	*/
