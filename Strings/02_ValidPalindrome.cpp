// LeetCode #125 - Valid Palindrome
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool validPalindrome(string s)
{
    int left = 0;
    int right = s.size() - 1;
    while (left < right)
    {
        while (left < right && !isalnum(s[left]))
        {
            left++;
        }
        while (left < right && !isalnum(s[right]))
        {
            right--;
        }
        if (tolower(s[left]) != tolower(s[right]))
        {
            return false;
        }
        else
        {
            left++;
            right--;
        }
    }
    return true;
}

int main()
{
    cout << validPalindrome("A man, a plan, a canal: Panama") << endl;
    cout << validPalindrome("race a car") << endl;
}