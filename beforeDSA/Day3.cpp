// find largest in array
// input = {3,1,7,2,9,4} ; output = 9
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
int largest(vector<int> &nums)
{
    int largestNumber = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > largestNumber)
        {
            largestNumber = nums[i];
        }
    }
    return largestNumber;
}
vector<int> sumOfArray(vector<int> &num)
{
    for (int i = 0; i < num.size(); i++)
    {
        num[i + 1] = num[i + 1] + num[i];
    }
    return num;
}
bool containsDuplicate(vector<int> &test)
{
    unordered_set<int> notebook;
    for (int i = 0; i < test.size(); i++)
    {
        if (notebook.count(test[i]) == 1)
        {
            return true;
        }
        else
        {
            notebook.insert(test[i]);
        }
    }
    return false;
}
int main()
{
    vector<int> nums = {3, 1, 7, 2, 9, 4};
    // cout << largest(nums);

    vector<int> num = {1, 2, 3, 4};
    for (auto x : sumOfArray(num))
    {
        cout << x << endl;
    }

    vector<int> test = {1, 2, 33, 4, 33};
    cout << containsDuplicate(test);
}
