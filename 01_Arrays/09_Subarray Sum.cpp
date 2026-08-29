#include <iostream>
#include <vector>
using namespace std;

int subarraySum(vector<int> &nums)
{
    int currentSum = 0;
        int maxSum = nums[0];
        for(int i=0;i<nums.size();i++){
            currentSum += nums[i];
            maxSum = max(currentSum,maxSum);
            if( currentSum < 0){
                currentSum = 0;
            }
        }
        return maxSum;
}

int main()
{
    vector<int> nums = {4, -3, -2, 5, 2, 1, 7, -5};
    cout << subarraySum(nums);
}