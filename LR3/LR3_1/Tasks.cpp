#include <iostream>
using namespace std;
double summ(int n)
{
    double summ1 = 0;
    for (int i = 0; i < n; i++)
    {
        summ1 += pow(-1, i) * ((i + 1) / (pow(2, i - 1)));
    }
    return summ1;
}
void task1()
{
    int n;
    cout << "Enter n= ";
    cin >> n;
    cout << "Summ= " << summ(n);
}
double summ2(double eps)
{
    int i = 0;
    double summ3 = pow(-1, i) * ((i + 1) / (pow(2, i - 1)));
    for (int i = 1; abs(summ3) > eps; i++)
    {
        summ3 += pow(-1, i) * ((i + 1) / (pow(2, i - 1)));
        i++;

    }  return summ3;
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

    for (int i = 0; i < n; i++)
    {
        count = pow(-1, i) * ((i + 1) / (pow(2, i - 1)));
        if ((i + 1) % k == 0)
        {
            continue;
        }
        cout << count << " ";
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
    int i;
    for (i = 0; ; i++)
    {
        count = pow(-1, i) * ((i + 1) / (pow(2, i - 1)));
        if (abs(count) < eps)
        {
            break;
        }
    }
    return i + 1;
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
    int i;
    for (i = 0; ; i++)
    {
        count = pow(-1, i) * ((i + 1) / (pow(2, i - 1)));
        if (abs(count) < eps && count < 0)
        {
            return i + 1;
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
