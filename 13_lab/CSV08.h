#ifndef CSV08_H_INCLUDED
#define CSV08_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <windows.h>

using namespace std;

struct Customer
{
	string surname;
	string name;
	string home_adress;
	string phone_number;
	string card_number;
};

// Подсчет строк в *.csv файле
int strings(string);

// Чтение структуры
Customer* read_file(string);

// Создание структуры по задаваемым параметрам
Customer get_struct();

// Вывод структуры на экран
void display_struct(Customer[], int);

// Добавление элемента
void add_element(string, string);

// Удаление элемента
void delete_element(string, string);

// Вывод заданного элемента
//void output_element(const char*, const char*);

#endif 