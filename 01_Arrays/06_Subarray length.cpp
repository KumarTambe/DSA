/*
 Problem: LeetCode 209 - Minimum Size Subarray Sum
 Pattern: Dynamic Sliding Window (Caterpillar Method)
 * Concept:
    Use two pointers to create a dynamic window. The 'right' pointer continuously
    stretches the window to the right, adding to a running sum. As soon as the sum
    meets or exceeds the target, we record the window size. We then trigger a 'while'
    loop to shrink the window from the 'left' side to find the absolute minimum
    length that still satisfies the condition.
 */

/*
* Complexity:
- Time Complexity: O(N) -> Even though there is a nested 'while' loop, both the 'left'
  and 'right' pointers only ever move forward. Each element is processed at most twice.
- Space Complexity: O(1) -> We only use a few integer variables to track sums and lengths.
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int left = 0;
        int currentSum = 0;
        int minLength = nums.size() + 1;
        for (int right = 0; right < nums.size(); right++)
        {
            currentSum += nums[right];
            while (currentSum >= target)
            {
                minLength = min(minLength, right - left + 1);
                currentSum -= nums[left];
                left++;
            }
        }
        if (minLength == nums.size() + 1)
        {
            return 0;
        }
        else
        {
            return minLength;
        }
    }
};