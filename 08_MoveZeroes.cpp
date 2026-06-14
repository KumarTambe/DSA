#include <iostream>
#include <vector>

using namespace std;

void moveZeroes(vector<int> &nums)
{
    int personA = 0;
    for (int personB = 0; personB < nums.size(); personB++)
    {
        if (nums[personB] != 0)
        {
            nums[personA] = nums[personB];
            personA++;
        }
    }
    while (personA < nums.size())
    {
        nums[personA] = 0;
        personA++;
    }
}

int main()
{
    vector<int> nums = {0, 1, 0, 3, 12};
    moveZeroes(nums);
    for (auto x : nums)
    {
        cout << x << endl;
    }
}