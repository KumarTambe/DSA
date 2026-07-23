#include<bits/stdc++.h>
using namespace std;

int pivotElement(vector<int>&nums){
    int totalSum = 0;
    for(auto x : nums){
        totalSum += x;
    }
    int leftSum = 0;
    for(int i = 0;i<nums.size();i++){
        int rightSum = totalSum - leftSum - nums[i];
        if(rightSum == leftSum){
            return i;
        }
        leftSum += nums[i];
    }
    return -1;
}

int main(){
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    cout << pivotElement(nums);
}