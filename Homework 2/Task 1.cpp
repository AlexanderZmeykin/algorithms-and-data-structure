#include <iostream>
using namespace std;

long long fibonacci(int n) 
{
    if (n <= 1)           
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() 
{
    int n;
    cout << "Введите номер числа Фибоначчи: ";
    cin >> n;

    if (n < 0) 
    {
        cout << "Число должно быть неотрицательным." << endl;
        return 1;
    }

    cout << "F(" << n << ") = " << fibonacci(n) << endl;
    return 0;
}