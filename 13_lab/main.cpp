#include "CSV08.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// ��� �������� �����
	string input_file_name = "input08.csv";

	int n = strings(input_file_name);

	Customer* tmp = read_file(input_file_name);

	display_struct(tmp, n);

	// ��� ��������� ����� = ����� �������� ����� (���� �������������� ��� ����)
	string output_file_name = "output08.csv";

	// �������� ������ �� ��������� �������
	delete_element(input_file_name, input_file_name);

	// ���������� �������� ����� ��������� ��������
	add_element(input_file_name, output_file_name);

	cout << endl << "������." << endl;

	system("pause");

	return 0;
}