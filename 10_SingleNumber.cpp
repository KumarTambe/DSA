#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int singleNumber(vector<int> &nums)
{
    unordered_map<int, int> Tracker;
    for (auto x : nums)
    {
        Tracker[x]++;
    }
    for (auto x : Tracker)
    {
        if (x.second == 1)
        {
            return x.first;
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {1, 2, 3, 1, 2};
    cout << singleNumber(nums);
}
