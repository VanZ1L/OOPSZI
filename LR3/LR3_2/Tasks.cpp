#include <iostream>
using namespace std;

double summ1(int n)
{
	double summ = 0;
	double i = 0;
	while (i < n)
	{
		summ += pow(-1, i) * ((i + 1) / (pow(2, i - 1)));
		i++;
	} return summ;
}
void task1()
{
	int n;
	cout << "Enter n= ";
	cin >> n;
	cout << "Summ= " << summ1(n);
}
double summ2(double eps)
{
	int i = 0;
	double summ = pow(-1, i) * ((i + 1) / (pow(2, i - 1)));
	while (abs(summ) > eps)
	{
		i++;
		summ += pow(-1, i) * ((i + 1) / (pow(2, i - 1)));
	} return summ;
}
void task2()
{
	double eps;
	cout << "Enter eps= ";
	cin >> eps;
	cout << "Summ= " << summ2(eps);
}
void print(int n, int k)
{
	double count = 0;
	int i = 0;
	while (i < n)
	{
		count = pow(-1, i) * ((i + 1) / (pow(2, i - 1)));
		if ((i + 1) % k == 0)
		{
			i++;
			continue;
		}
		cout << count << " ";
		i++;
	}
}
void task3()
{
	int n, k = 0;
	cout << "Enter n = ";
	cin >> n;
	cout << "Enter k = ";
	cin >> k;
	print(n, k);
}
int findFirstElement(double eps)
{
	double count = 0;
	int i = 0;
	while (true)
	{
		count = pow(-1, i) * ((i + 1) / (pow(2, i - 1)));
		i++;
		if (abs(count) < eps)
		{
			break;
		}
	}
	return i;
}
void task4()
{
	double eps;
	cout << "Enter eps= ";
	cin >> eps;
	cout << "Number= " << findFirstElement(eps);
}
int findFirstNegativeElement(double eps)
{
	double count = 0;
	int i = 0;
	while (true)
	{
		count = pow(-1, i) * ((i + 1) / (pow(2, i - 1)));
		i++;
		if (abs(count) < eps && count < 0)
		{
			return i;
		}
	}
}
void task5()
{
	double eps;
	cout << "Enter eps= ";
	cin >> eps;
	cout << "Number= " << findFirstNegativeElement(eps);
}
