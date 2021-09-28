#include "STR1-08.h"

void Substring(int L, int index, string str, string str2)
{
	if (L % 2 == 0)
	{
		int temp = 0;

		for (int i = 0; i < L; i++)
		{
			index++;

			if (str[i] == ' ')
			{
				temp++;

				if (temp == 2)
				{
					str2 = str.substr(index);
				}
			}

		}

		cout << "str2: " << str2;

	}

	fstream f;

	f.open("output.txt", ios_base::out);

	f << str << endl;
	f << L << endl;
	f << str2 << endl;

	f.close();

}

