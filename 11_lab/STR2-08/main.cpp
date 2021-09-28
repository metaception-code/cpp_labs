#include "STR2-08.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int index = 0;

	string str;

	fstream f;
	f.open("input08.txt", ios_base::in);

	getline(f, str);

	f.close();

	int L = size(str);

	cout << "str: " << str << endl;


	reduction(L, str);

	return 0;
}