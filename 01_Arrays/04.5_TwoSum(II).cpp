/*
 Problem: LeetCode 167 - Two Sum II - Input Array Is Sorted
 Pattern: Two Pointers (Inward Convergence)
 * Concept:
    Leverages the mathematical gradient of a pre-sorted array. By initializing
    a 'left' pointer at the minimum value and a 'right' pointer at the maximum
    value, we evaluate their sum against the target. If the sum is too small,
    we shift 'left' inward to increase it; if too large, we shift 'right'
    inward to decrease it.
 */

/*
* Complexity:
- Time Complexity: O(N) -> In the worst case, the two pointers converge by moving
  through the array elements exactly once.
- Space Complexity: O(1) -> Operates directly on the input vector memory using
  only two auxiliary integer tracker variables.
*/

#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right)
        {
            int currentSum = numbers[left] + numbers[right];

            // Match found: Return 1-indexed positions
            if (currentSum == target)
            {
                return {left + 1, right + 1};
            }
            // Sum is too small: Move left pointer to step up to a larger value
            else if (currentSum < target)
            {
                left++;
            }
            // Sum is too large: Move right pointer to step down to a smaller value
            else
            {
                right--;
            }
        }
        return {};
    }
};