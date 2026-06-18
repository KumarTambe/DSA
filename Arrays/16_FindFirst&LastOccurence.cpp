// LeetCode #34 - Find First and Last Position of Element in Sorted Array
#include <iostream>
#include <vector>
using namespace std;

int findFirst(vector<int> &nums, int target)
{
    int n = nums.size();
    int left = 0;
    int right = n - 1;
    int result = -1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] == target)
        {
            result = mid;
            right = mid - 1; // keep searching left
        }
        else if (target < nums[mid])
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return result;
}

int findLast(vector<int> &nums, int target)
{
    int n = nums.size();
    int left = 0;
    int right = n - 1;
    int result = -1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] == target)
        {
            result = mid;
            left = mid + 1; // keep searching right
        }
        else if (target < nums[mid])
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return result;
}

vector<int> searchRange(vector<int> &nums, int target)
{
    int first = findFirst(nums, target);
    int last = findLast(nums, target);
    return {first, last};
}

int main()
{
    vector<int> nums = {5, 5, 7, 7, 8, 10};
    vector<int> result = searchRange(nums, 7);
    for (auto x : result)
    {
        cout << x << endl;
    }
}