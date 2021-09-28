#include "STR2-08.h"

void reduction(int L, string str)
{
		int fstcomma = 0;
		int sndcomma = 0;
		int count = 0;

		for (int i = 0; i < L; i++)
		{
			if (str[i] == ',')
			{
				fstcomma = i;
				break;
			}
		}

		str.erase(0, ++fstcomma);

		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == ',')
			{
					sndcomma = i;
					break;
			}
		}
		
		
		str.erase(sndcomma, str.size()-sndcomma);

		cout << "str: " << str;
	
	fstream f;

	f.open("output08.txt", ios_base::out);

	f << str << endl;
	f.close();

}

