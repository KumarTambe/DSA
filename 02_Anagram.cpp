/*
 * Problem: LeetCode 242 - Valid Anagram
 * Pattern: Frequency Array (Fixed-Size Hashing)
 * * Concept:
 * Because the problem guarantees only lowercase English letters, we do not need
 * a heavy Hash Map. We can use a highly efficient, fixed-size integer array of 26 slots.
 * We iterate through both strings simultaneously: adding 1 to the tally for string 's',
 * and subtracting 1 for string 't'. If they are perfect anagrams, every slot in the
 * tally array will perfectly balance back to 0.
 * * Math Trick:
 * - Characters are stored as ASCII values. Subtracting the anchor 'a' (97) mathematically
 * converts any letter into a perfect 0-25 array index (e.g., 'a'-'a' = 0, 'z'-'a' = 25).
 * * Complexity:
 * - Time Complexity: O(N) -> We process both strings in a single pass.
 * - Space Complexity: O(1) -> The array is strictly bounded to 26 slots, regardless of
 * how massive the input strings become. Space does not scale with input.
 */

#include <vector>
#include <algorithm>
using namespace std;

bool isAnagram(string s, string t)
{
    if (s.length() != t.length())
    {
        return false;
    }

    vector<int> tally(26, 0);

    for (int i = 0; i < s.length(); i++)
    {
        tally[s[i] - 'a'] += 1;
        tally[t[i] - 'a'] -= 1;
    }

    for (int i = 0; i < 26; i++)
    {
        if (tally[i] != 0)
        {
            return false;
        }
    }
    return true;
}