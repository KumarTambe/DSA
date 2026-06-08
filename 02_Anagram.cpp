/*
 * Problem: LeetCode 217 - Contains Duplicate
 * Pattern: Sorting & Linear Scan
 * * Concept:
 * When strict memory limits exist (O(1) extra space), we cannot use a Hash Set.
 * Instead, we sort the array in-place so that any duplicate numbers are forced
 * to sit directly next to each other. We then do a simple scan to check if any
 * element matches its right-side neighbor.
 * * Trade-offs:
 * - Time Complexity: O(N log N) -> C++ std::sort() dominates the execution time.
 * - Space Complexity: O(1) -> Sorting is done in-place. Zero extra memory used.
 * * Critical Bug Averted:
 * - The loop stops at `nums.size() - 1` to prevent an out-of-bounds crash when
 * checking `nums[i + 1]` on the final iteration.
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