/*
 Problem: LeetCode 15 - 3Sum
 Pattern: Anchored Fixed-Pointer + Two-Pointer Inward Convergence
 * Concept:
    Sort the input array to establish a reliable mathematical gradient. We iterate
    through the array using a fixed anchor pointer 'i'. For every distinct anchor,
    we execute an inward Two Sum II scan using 'left' and 'right' pointers on the
    remaining elements. To guarantee absolute uniqueness across all triplets,
    we apply conditional filters to skip duplicate values for the anchor,
    the left pointer, and the right pointer.
 */

/*
* Complexity:
- Time Complexity: O(N^2) -> Sorting requires O(N log N). The nested loop layout
  scans pairs for each anchor, yielding an O(N * N) phase which dominates overall time.
- Space Complexity: O(1) auxiliary -> Operates in-place (excluding the memory used
  to store the final output vector).
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {

            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right)
            {
                int currentSum = nums[i] + nums[left] + nums[right];

                if (currentSum == 0)
                {

                    result.push_back({nums[i], nums[left], nums[right]});

                    while (left < right && nums[left] == nums[left + 1])
                    {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right - 1])
                    {
                        right--;
                    }

                    left++;
                    right--;
                }
                else if (currentSum < 0)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
        return result;
    }
};