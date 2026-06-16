#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int sortColors(vector<int> &nums)
{
    unordered_map<int, int> map;
    for (auto x : nums)
    {
        map[x]++;
    }
    int i = 0;
    while (map[0]--)
    {
        nums[i++] = 0;
    }
    while (map[1]--)
    {
        nums[i++] = 1;
    }
    while (map[2]--)
    {
        nums[i++] = 2;
    }
    return 0;
}

int main()
{
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    sortColors(nums);
    for (auto x : nums)
    {
        cout << x << " ";
    }
}