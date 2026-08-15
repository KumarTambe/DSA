#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int majorityElementBruteForce(vector<int> &nums)
{
    unordered_map<int, int> Tracker;
    for (auto x : nums)
    {
        Tracker[x]++;
    }
    for (auto x : Tracker)
    {
        if (x.second > nums.size() / 2)
        {
            return x.first;
        }
    }
    return -1;
}

int majorityElement(vector<int> &nums)
{
    int candidate = nums[0];
    int count = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (count == 0)
        {
            candidate = nums[i];
        }
        else if (nums[i] == candidate)
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    return candidate;
}

int main()
{
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    cout << majorityElement(nums);
}
