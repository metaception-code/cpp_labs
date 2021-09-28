#include "STR1-08.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int index = 0;

	string str;
	string str2;

	fstream f;
	f.open("input.txt", ios_base::in);

	getline(f, str);

	f.close();

	cout << "str: " << str << endl;

	int L = size(str);

	cout <<"String length: " << L << endl;	 

	Substring(L, index, str, str2);

	return 0;
}