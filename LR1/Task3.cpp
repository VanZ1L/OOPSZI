#include <iostream>
using namespace std;
double f(double x, double y);
void main()
{
	double x, y;
	x = 2;
	y = 4;
	cout << "x = 2 \ny = 4\nF= " << f(x, y) << endl;
	cout << "x= ";
	cin >> x;
	cout << "y= ";
	cin >> y;
	cout << "F= " << f(x, y);
}
double f(double x, double y)
{
	return  pow((cos(x) - cos(y)), 2) - pow((sin(x) - sin(y)), 2);
}
