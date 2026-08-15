// LeetCode #238 - Product of Array Except Self
#include <vector>
#include <iostream>
using namespace std;

vector<int> multiplyElement(vector<int> &nums)
{
    int n = nums.size();

    vector<int> leftProducts(n);
    leftProducts[0] = 1;
    for (int i = 1; i < n; i++)
    {
        leftProducts[i] = leftProducts[i - 1] * nums[i - 1];
    }

    vector<int> rightProducts(n);
    rightProducts[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        rightProducts[i] = rightProducts[i + 1] * nums[i + 1];
    }

    vector<int> result(n);
    for (int i = 0; i < n; i++)
    {
        result[i] = leftProducts[i] * rightProducts[i];
    }

    return result;
}

int main()
{
    vector<int> nums = {4, 5, 2};
    vector<int> arr = multiplyElement(nums);
    for (auto x : arr)
    {
        cout << x << endl;
    }
}