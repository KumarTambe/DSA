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