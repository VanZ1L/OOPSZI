#include <iostream>
using namespace std;
double x, y, result;
void f(void);
void main()
{
	x = 2;
	y = 4;
	f();
	cout << "x = 2 \ny = 4\nF= " << result << endl;
	cout << "x= ";
	cin >> x;
	cout << "y= ";
	cin >> y;
	f();
	cout << "F= " << result;
}
void f(void)
{
	result = pow((cos(x) - cos(y)), 2) - pow((sin(x) - sin(y)), 2);
}
