#include <iostream>
using namespace std;
void task1();
void task2();
void task3();
void task4();
void task5();
int main()
{
	int number;
	setlocale(LC_CTYPE, "rus");
	while (true)
	{
		system("cls");
		cout << "Меню ЛР3 циклы While" << endl
			<< "[1] Задание 1 " << endl
			<< "[2] Задание 2 " << endl
			<< "[3] Задание 3 " << endl
			<< "[4] Задание 4 " << endl
			<< "[5] Задание 5 " << endl
			<< "[6] Выход " << endl
			<< "Введите номер подпункта: ";
		cin >> number;
		system("cls");
		switch (number)
		{
		case 1:
		{
			task1();
			break;
		}
		case 2:
		{
			task2();
			break;
		}
		case 3:
		{
			task3();
			break;
		}
		case 4:
		{
			task4();
			break;
		}
		case 5:
		{
			task5();
			break;
		}
		case 6:
		{
			return true;
		}
		}
		cout << endl;
		system("pause");
	}
}
