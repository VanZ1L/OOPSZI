#include <iostream>
using namespace std;
extern double x, y, result;
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
