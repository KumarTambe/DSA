#include <iostream>
using namespace std;

// DAY 2 — Recursion Part 2
// =========================

// Print 1 to N parameterised
void printNto1Param(int n, int current)
{
    if (current > n)
        return;
    cout << current << " ";
    printNto1Param(n, current + 1);
}

// isPalindrome
bool isPalindrome(string s, int left, int right)
{
    if (left >= right)
        return true;
    if (s[left] != s[right])
        return false;
    return isPalindrome(s, left + 1, right - 1);
}

// Power
int power(int base, int exp)
{
    if (exp == 0)
        return 1;
    return base * power(base, exp - 1);
}

// Reverse Number
int reverseNumber(int n, int reversed)
{
    if (n == 0)
        return reversed;
    reversed = reversed * 10 + n % 10;
    return reverseNumber(n / 10, reversed);
}

// Print All Subsets
void printSubsets(string s, string current, int index)
{
    if (index == s.length())
    {
        cout << current << " ";
        return;
    }
    printSubsets(s, current + s[index], index + 1); // include
    printSubsets(s, current, index + 1);            // exclude
}