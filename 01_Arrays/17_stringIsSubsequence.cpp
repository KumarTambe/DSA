// LeetCode #392 - Is Subsequence
#include <iostream>
#include <string>
using namespace std;

bool isSubSequence(string s, string t)
{
    if (s.length() == 0)
        return true; // empty string edge case

    int left = 0;
    int right = 0;
    for (int i = 0; i < t.length(); i++)
    {
        if (s[left] == t[right])
        {
            left++;
            right++;
        }
        else
        {
            right++;
        }
        if (left == s.length())
        {
            return true;
        }
    }
    return false;
}

int main()
{
    cout << isSubSequence("abc", "ahbgdc");
}