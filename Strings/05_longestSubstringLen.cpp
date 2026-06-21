// Dynamic Sliding Window imp Qs

#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    unordered_set<char> set;
    int left = 0;
    int maxLength = 0;
    for (int right = 0; right < s.length(); right++)
    {
        while (set.count(s[right]) > 0)
        {
            set.erase(s[left]);
            left++;
        }
        set.insert(s[right]);
        maxLength = max(maxLength, right - left + 1);
    }
    return maxLength;
}