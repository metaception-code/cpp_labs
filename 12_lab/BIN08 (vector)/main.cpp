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
		cout << "�� ������� ������� ����";
		return 1;
	}

	Customer temp;

	for (int i = 0; ; i++) // ���������� ��������� ��������� � ���������� temp
	{
		input.read(reinterpret_cast<char*>(&temp), sizeof(Customer));
		if (input.eof())
			break;
		customers.push_back(temp);
	}
	
	for_output.push_back(customers[6]);	//��������� � ������ 7 ������� 
	for_output.push_back(customers[8]); //��������� � ������ 9 ������� 
	for_output.push_back(customers[9]); //��������� � ������ 10 ������� 

	print(customers, n); // ����� ������ ���������

	del_by_card(customers); // �������� ��������


	for (short i = 0u; i < 3; i++)
	{
		customers.push_back(readCustomer(customers));
	}

	new_print(customers);


	cout << "7, 9, 10 ��������:\n";
	print(for_output, 3);


	system("pause");
	return 0;
}