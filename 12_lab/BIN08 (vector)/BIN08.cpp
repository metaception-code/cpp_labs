#include "BIN08.h"



void print(vector <Customer> element, int n) 
{
	for (int i = 0; i < n; i++)
		print(element[i]);
}


void new_print(vector <Customer> element)
{
	int n = 13u;
	for (int i = 0; i < n; i++)
		print(element[i]);
}


void print(Customer element)
{
	cout << left << setw(15) << element.surname << setw(15) << element.name << setw(40) << element.home_adress << setw(25) << element.phone_number << setw(15) << element.card_number << endl;
}


Customer readCustomer(vector<Customer> customers)
{
	Customer new_element;

	cout << "¬ведите фамилию\n";
	cin >> new_element.surname;

	cout << "¬ведите им€\n";
	cin >> new_element.name;

	cout << "¬ведите домашний адрес\n";
	cin >> new_element.home_adress;

	cout << "¬ведите номер телефона\n";
	cin >> new_element.phone_number;

	cout << "¬ведите номер карты\n";
	cin >> new_element.card_number;

	return new_element;
	
	customers.push_back(new_element);

}


void del_by_card(vector<Customer> customers)
{
	int n = 10;
	int c_number = 0;

	cout << "¬ведите номер карты:\n";
	cin >> c_number;

	for (int i = 0; i < n; i++)
		if (customers[i].card_number == c_number)
		{
			customers.erase(customers.begin() + i);
			n--;
		}

	print(customers, n); // ¬ывод после удалени€ элемента по карте
}

