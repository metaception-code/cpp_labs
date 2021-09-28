#include "A2D08.h"

/*

Input in the console:

void OutData(int even, int*evenVect, int*oddVect, int m, int n) {
	cout << "Even in arrays: " << even << ", and odd: " << n*m - even << "\nEven sum in line:\n";
	for (int i = 0; i < n; i++) {
		cout  << evenVect[i] << " ";
	}

	cout << "\nOdd sum in col\n";
	for (int j = 0; j < m; j++) {
		cout << oddVect[j] << " ";
	}
	cout << endl;
}
*/

void OutData(int even, int*evenVect, int*oddVect, int m, int n) 
{

	fstream f;

	f.open("output.txt", ios_base::out);

	int odd = n * m - even;
	f << "Even: " << even << endl;
	f << "Odd: " << odd << endl;

	f << "M1[n]:\n ";

	for (int i = 0; i < n; i++) {
		f << evenVect[i] << " ";
	}

	f << endl;
	f << "M2[m]:\n ";
	for (int j = 0; j < m; j++) {
		f << oddVect[j] << " ";
	}

	f.close();
}


void calc(int** Arr, int n, int m)
{
	int even = 0, *oddVect = new int[n], *evenVect = new int[m];
	for (int i = 0; i < n; i++)
		oddVect[i] = 0;
	for (int j = 0; j < m; j++)
		evenVect[j] = 0;

	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++) 
		{
			if (Arr[i][j] % 2 != 0 || Arr[i][j] == 0) 
			{
				even++;
				evenVect[j] += Arr[i][j];
			}
			else
				oddVect[i] += Arr[i][j];
		}
	}
	OutData(even, oddVect, evenVect, m, n);
}