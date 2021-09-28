#pragma once
#include <iostream>
#include <fstream>
#include <windows.h>
#include <vector>
#include <iomanip>

using namespace std;

struct Customer 
{
	char surname[30];
	char name[30];
	char home_adress[40];
	char phone_number[30];
	int card_number;
};

void print(vector <Customer> element, int n);
void print(Customer element);
void del_by_card(vector<Customer> customers);
//void save_three_elements(vector<Customer> for_output, vector<Customer> customers);
Customer readCustomer(vector<Customer> customers);
void new_print(vector <Customer> element);