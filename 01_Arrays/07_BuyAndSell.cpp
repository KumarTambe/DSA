#include <iostream>
#include <vector>
using namespace std;

int buyAndSell(vector<int> &prices)
{
    int min = prices[0];
    int profit = 0;
    for (int i = 0; i < prices.size(); i++)
    {
        if (prices[i] < min)
        {
            min = prices[i];
        }
        if (prices[i] - min > profit)
        {
            profit = prices[i] - min;
        }
    }
    return profit;
}

int main()
{
    vector<int> nums = {3, 10, 1, 4};
    cout << buyAndSell(nums);
}