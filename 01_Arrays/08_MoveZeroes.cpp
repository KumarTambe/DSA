#include<bits/stdc++.h>
using namespace std;

vector<int> moveZeroes(vector<int>&nums){
    int left = 0;
    for(int right = 0; right <nums.size();right++){
        if(nums[right] != 0){
            swap(nums[left],nums[right]);
            left++;
        }
    }
    while(left < nums.size()){
        nums[left] = 0;
        left++;
    }
    return nums;
}

int main(){
    vector<int> nums = {0, 0, 1};
    vector<int> result = moveZeroes(nums);
    for( auto X : result){
        cout << X << " ";
    }
}