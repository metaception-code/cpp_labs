#include "CSV08.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// Имя входного файла
	string input_file_name = "input08.csv";

	int n = strings(input_file_name);

	Customer* tmp = read_file(input_file_name);

	display_struct(tmp, n);

	// Имя выходного файла = имени входного файла (файл перезаписывает сам себя)
	string output_file_name = "output08.csv";

	// Удаление записи по заданному индексу
	delete_element(input_file_name, input_file_name);

	// Добавление элемента после заданного элемента
	add_element(input_file_name, output_file_name);

	cout << endl << "Готово." << endl;

	system("pause");

	return 0;
}