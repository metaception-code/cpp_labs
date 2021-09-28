#include "BIN08.h"
int main() 
{
	int n = 10;

	setlocale(LC_ALL, "rus");

	fstream input("input08.bin", ios_base::in | ios_base::binary);

	vector<Customer> customers;
	vector<Customer> for_output;

	if (!input.is_open()) 
	{
		cout << "Не удалось открыть файл";
		return 1;
	}

	Customer temp;

	for (int i = 0; ; i++) // Считывание элементов структуры в переменную temp
	{
		input.read(reinterpret_cast<char*>(&temp), sizeof(Customer));
		if (input.eof())
			break;
		customers.push_back(temp);
	}
	
	for_output.push_back(customers[6]);	//Добавляем в вектор 7 элемент 
	for_output.push_back(customers[8]); //Добавляем в вектор 9 элемент 
	for_output.push_back(customers[9]); //Добавляем в вектор 10 элемент 

	print(customers, n); // Вывод списка элементов

	del_by_card(customers); // Удаление элемента


	for (short i = 0u; i < 3; i++)
	{
		customers.push_back(readCustomer(customers));
	}

	new_print(customers);


	cout << "7, 9, 10 элементы:\n";
	print(for_output, 3);


	system("pause");
	return 0;
}