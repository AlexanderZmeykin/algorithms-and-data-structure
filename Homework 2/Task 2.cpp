#include <iostream>
#include <vector>
#include <cstdint>
#include <stdexcept>

std::uint64_t fibonacci(int n) 
{
    if (n < 0) 
    {
        throw std::invalid_argument("Число должно быть неотрицательным.");
    }
    std::vector<std::uint64_t> fib(n + 1);

    if (n >= 0) fib[0] = 0;
    if (n >= 1) fib[1] = 1;

    for (int i = 2; i <= n; ++i) 
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    return fib[n];
}

int main(int argc, char** argv)
{
    int n;
    std::cout << "Введите номер числа Фибоначчи: ";
    std::cin >> n;

    try 
    {
        std::uint64_t result = fibonacci(n);
        std::cout << "F(" << n << ") = " << result << std::endl;
    }
    catch (const std::exception& e) 
    {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}