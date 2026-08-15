#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool validAnagram(string s, string t)
{
    unordered_map<char, int> map;

    if (s.length() != t.length())
    {
        return false;
    }
    for (int i = 0; i < s.length(); i++)
    {
        map[s[i]]++;
        map[t[i]]--;
    }
    for (auto x : map)
    {
        if (x.second != 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    cout << validAnagram("anagram", "nagaram") << endl;
    cout << validAnagram("rat", "cat");
}