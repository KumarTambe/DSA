#include <iostream>
#include <vector>
using namespace std;

int subarraySum(vector<int> &nums)
{
    int currentSum = nums[0];
    int maxSum = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        if (currentSum < 0)
        {
            currentSum = nums[i];
        }
        else
        {
            currentSum += nums[i];
        }
        if (currentSum > maxSum)
        {
            maxSum = currentSum;
        }
    }
    return maxSum;
}

int main()
{
    vector<int> nums = {4, -3, -2, 5, 2, 1, 7, -5};
    cout << subarraySum(nums);
}