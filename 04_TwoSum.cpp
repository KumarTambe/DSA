#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(int target, vector<int> &nums)
{
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++)
    {
        int complement = target - nums[i];

        if (map.count(complement))
        {
            return {map[complement], i};
        }
        else
        {
            map.insert({nums[i], i});
        }
    }
    return {};
}

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    auto result = twoSum(18, nums);
    for (auto x : result)
    {
        cout << x << " ";
    }
}