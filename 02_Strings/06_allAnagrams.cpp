#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

vector<int> allAnagrams(string s, string p)
{
    vector<int> result;
    unordered_map<char, int> Freq_p, window_freq;

    for (int i = 0; i < p.length(); i++)
    {
        Freq_p[p[i]]++;
    }

    int left = 0;
    for (int right = 0; right < s.length(); right++)
    {
        window_freq[s[right]]++;
        while ((right - left + 1) > p.length())
        {
            window_freq[s[left]]--;
            if (window_freq[s[left]] == 0)
            {
                window_freq.erase(s[left]);
            }
            left++;
        }
        if (window_freq == Freq_p)
        {
            result.push_back(left);
        }
    }
    return result;
}

int main()
{
    vector<int> result = allAnagrams("abceabc", "abc");
    for (auto x : result)
    {
        cout << x << endl;
    }
}