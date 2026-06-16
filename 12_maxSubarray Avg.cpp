#include <iostream>
#include <vector>

using namespace std;

int maxSubArrayAvg(vector<int> &nums, int k)
{
    double currentSum = 0;
    for (int i = 0; i < k; i++)
    {
        currentSum += nums[i];
    }
    double maxAvg = currentSum / k;
    for (int i = k; i < nums.size(); i++)
    {
        currentSum += nums[i];
        currentSum -= nums[i - k];
        maxAvg = max(maxAvg, currentSum / k);
    }
    return maxAvg;
}