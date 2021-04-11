#include "math.h"
double x, y, result;
void f(void)
{
	result = pow((cos(x) - cos(y)), 2) - pow((sin(x) - sin(y)), 2);
}
