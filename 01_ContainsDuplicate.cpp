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