#include "CSV08.h"

int strings(string iname) {
	int num = 0;
	string bufferfer;

	fstream fin;
	fin.open(iname, ios_base::in);
	if (!fin) {
		cerr << "Ошибка открытия файла " << iname << "!" << endl;
		exit(EXIT_FAILURE);
	}
	while (!fin.eof()) {
		getline(fin, bufferfer);
		num++;
	}
	return num;
}



Customer* read_file(string iname) {
	string bufferfer;
	fstream fin;
	fin.open(iname, ios_base::in);
	if (!fin) {
		cerr << "Ошибка открытия файла " << iname << "!" << endl;
		exit(EXIT_FAILURE);
	}

	int n = strings(iname);
	Customer* tmp = new Customer[n]; // Массив элементов введенных с клавиатуры
	while (!fin.eof()) {
		for (int i = 0; i < n; i++) {
			getline(fin, bufferfer, ';');
			tmp[i].surname = bufferfer;
			getline(fin, bufferfer, ';');
			tmp[i].name = bufferfer;
			getline(fin, bufferfer, ';');
			tmp[i].home_adress = bufferfer;
			getline(fin, bufferfer, ';');
			tmp[i].phone_number = bufferfer;     
			getline(fin, bufferfer);
			tmp[i].card_number = bufferfer; 
		}
	}
	fin.close();
	return tmp; 
}

void display(Customer tmp[], int n){
	cout << left
		<< setw(15) << tmp[n].surname
		<< setw(15) << tmp[n].name
		<< setw(40) << tmp[n].home_adress
		<< setw(25) << tmp[n].phone_number
		<< setw(20) << tmp[n].card_number;
	cout << endl;
}

void display_struct(Customer tmp[], int n) {

	for (int i = 0; i < n; i++) {
		cout << left
			<< setw(15) << tmp[i].surname
			<< setw(15) << tmp[i].name
			<< setw(40) << tmp[i].home_adress
			<< setw(25) << tmp[i].phone_number
			<< setw(20) << tmp[i].card_number;
		cout << endl;
	}
}

void delete_element(string iname, string oname) {

	int n = strings(iname);
	Customer* tmp = read_file(iname);

	int element_number = 0;
	cout << endl << "Введите номер удаляемого элемента: " << endl << "-> ";
	cin >> element_number;

	fstream fout;
	fout.open(oname, ios_base::out);
	if (!fout) {
		cerr << "Ошибка открытия файла " << oname << "!" << endl;
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < n; i++) {
		if (i != (element_number-1)) {
			display(tmp, i);
			fout << tmp[i].surname << ";";
			fout << tmp[i].name << ";";
			fout << tmp[i].home_adress << ";";
			fout << tmp[i].phone_number << ";";
			fout << tmp[i].card_number;
			fout << "\n";
		}
	}
	delete[]tmp;
	fout.close();
}

/*
void add_element(string iname, string oname) {
	cout << endl << "Укажите номер записи, после которой нужно вставить данные: " << endl << "-> ";
	int element = 0;
	cin >> element;

	int n = strings(iname);
	Customer* tmp = read_file(iname);

	fstream fin;
	fin.open(iname, ios_base::in | ios_base::out);
	if (!fin) {
		cerr << "Ошибка открытия файла " << iname << "!" << endl;
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < n; i++) {

		display(tmp, i);
		fin << tmp[i].surname << ";";
		fin << tmp[i].name << ";";
		fin << tmp[i].home_adress << ";";
		fin << tmp[i].phone_number << ";";
		fin << tmp[i].card_number;
		fin << "\n";
	}
	delete[]tmp;
	fin.close();
}
*/



void add_element(string iname, string oname) {
	cout << endl << "Укажите номер записи, после которой нужно вставить данные: " << endl << "-> ";
	int element_number = 0;
	cin >> element_number;

	int n = strings(iname);
	string buffer;

	fstream fin;
	fin.open(iname, ios_base::in | ios_base::out); // Один поток на ввод и вывод
	if (!fin) {
		cerr << "Ошибка открытия файла " << iname << "!" << endl;
		exit(EXIT_FAILURE);
	}
	

	Customer* tmp = new Customer[n + 1];          		
	for (int i = 0; i < n + 1; i++) {  	  		
		getline(fin, buffer, ';');
		tmp[i].surname = buffer;
		getline(fin, buffer, ';');
		tmp[i].name = buffer;
		getline(fin, buffer, ';');
		tmp[i].home_adress = buffer;
		getline(fin, buffer, ';');
		tmp[i].phone_number = buffer;
		getline(fin, buffer);
		tmp[i].card_number = buffer;
	}

	for (int i = n; i > 0; i--) {				
		tmp[i] = tmp[i - 1];
		if (i == element_number) {
			tmp[i] = get_struct();
			break;
		}
	}

	fstream fout;
	fout.open(oname, ios_base::out);
	if (!fout) {
		cerr << "Ошибка открытия файла " << oname << "!" << endl;
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < n + 1; i++) {
		display(tmp, i);
		fout << tmp[i].surname << ";";
		fout << tmp[i].name << ";";
		fin << tmp[i].home_adress << ";";
		fin << tmp[i].phone_number << ";";
		fin << tmp[i].card_number;
		fin << "\n";
	}

	delete[]tmp;
	fin.close();
	fout.close();
}


Customer get_struct()
{
	cin.ignore();
	Customer tmp = { "", "", "", "", "" };
	cout << endl;
	cout << "\tФамилия: -> ";
	getline(cin, tmp.surname);
	cout << "\tИмя: -> ";
	getline(cin, tmp.name);
	cout << "\tДомашний адрес: -> ";
	getline(cin, tmp.home_adress);
	cout << "\tНомер телефона: -> ";
	getline(cin, tmp.phone_number);
	cout << "\tНомер карты: -> ";
	getline(cin, tmp.card_number);
	cout << endl;
	return tmp;
}
