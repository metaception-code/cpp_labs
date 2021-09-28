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

// ������� ����� � *.csv �����
int strings(string);

// ������ ���������
Customer* read_file(string);

// �������� ��������� �� ���������� ����������
Customer get_struct();

// ����� ��������� �� �����
void display_struct(Customer[], int);

// ���������� ��������
void add_element(string, string);

// �������� ��������
void delete_element(string, string);

// ����� ��������� ��������
//void output_element(const char*, const char*);

#endif 