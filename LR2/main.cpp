#include <iostream>
using namespace std;
void Task1(), Task2();
void main()
{
	int g;
	cout << "Select task\nTask1 [1]\nTask2 [2]\n";
	cin >> g;
	switch (g)
	{
	case 1: return Task1();
	case 2: return Task2();
	}
}