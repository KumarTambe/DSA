/*
 * Problem: LeetCode 217 - Contains Duplicate
 * Pattern: Hash Set (The "Magic Notebook")
 * * Concept:
 * We use an unordered_set to track numbers we have already seen. As we iterate
 * through the array, we check if the current number exists in our set. If it does,
 * we found a duplicate. If not, we insert it and move on.
 * * Trade-offs:
 * - Time Complexity: O(N) -> We traverse the array exactly once, and set lookups are O(1).
 * - Space Complexity: O(N) -> We trade space for speed. In the worst case (no duplicates),
 * we must store every single element in the set.
 * * Edge Cases Handled:
 * - Empty array: The loop condition (0 < 0) immediately fails, naturally returning false.
 */

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool containsDuplicate(vector<int> &nums)
{

    unordered_set<int> notebook;

    for (int i = 0; i < nums.size(); i++)
    {

        if (notebook.count(nums[i]) == 1)
        {
            return true;
        }
        else
        {
            notebook.insert(nums[i]);
        }
    }
    return false;
}

// time complexity : O(N) best case and O(N^2) for worst case
// space complexity : O(N)

// another method for O(1) space complexity

bool containDuplicateNew(vector<int> &nums)
{

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] == nums[i + 1])
        {
            return true;
        }
    }

    return false;
}