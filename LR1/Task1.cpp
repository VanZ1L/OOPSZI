#include <iostream>
using namespace std;
void main()
{
	double x, y;
	cout << "x=2 \ny=4" << endl;
	x = 2;
	y = 4;
	cout << "F= " << pow((cos(x) - cos(y)), 2) - pow((sin(x) - sin(y)), 2) << endl;
	cout << "x= ";
	cin >> x;
	cout << "y= ";
	cin >> y;
	cout << "F= " << pow((cos(x) - cos(y)), 2) - pow((sin(x) - sin(y)), 2);;
}