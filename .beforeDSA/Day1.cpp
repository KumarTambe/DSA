#include <iostream>
using namespace std;

// DAY 1 — Basic Recursion
// ========================

// Factorial
int factorial(int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

// Fibonacci
int fibonacci(int n)
{
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Print N to 1
void printNto1(int n)
{
    if (n == 0)
        return;
    cout << n << " ";
    printNto1(n - 1);
}

// Sum of Digits
int sumOfDigits(int n)
{
    if (n == 0)
        return 0;
    return (n % 10) + sumOfDigits(n / 10);
}