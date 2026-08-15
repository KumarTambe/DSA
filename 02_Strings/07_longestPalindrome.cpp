#include <iostream>
#include <string>
using namespace std;

int expand(string &s, int left, int right)
{
    while (left >= 0 && right < s.length() && s[left] == s[right])
    {
        left--;
        right++;
    }
    return right - left - 1;
}

string longestPalindrome(string s)
{
    int start = 0;
    int maxLen = 1;
    for (int i = 0; i < s.length(); i++)
    {
        int odd = expand(s, i, i);
        int even = expand(s, i, i + 1);

        if (odd > maxLen)
        {
            maxLen = odd;
            start = i - (odd - 1) / 2;
        }
        if (even > maxLen)
        {
            maxLen = even;
            start = i - (even / 2) + 1;
        }
    }
    return s.substr(start, maxLen);
}