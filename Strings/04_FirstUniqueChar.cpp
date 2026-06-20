#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int firstUniqueCharacter(string s)
{
    unordered_map<char, int> map;

    for (int i = 0; i < s.length(); i++)
    {
        map[s[i]]++;
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (map[s[i]] == 1)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    cout << firstUniqueCharacter("leetcode");
}