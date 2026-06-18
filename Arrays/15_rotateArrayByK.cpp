// LeetCode #189 - Rotate Array
#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> result(n);
    k = k % n;

    for (int i = 0; i < n; i++)
    {
        result[(i + k) % n] = nums[i];
    }

    nums = result; // copy back into original array
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    rotate(nums, 7);
    for (auto x : nums)
    {
        cout << x << endl;
    }
}