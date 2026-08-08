#include<bits/stdc++.h>
using namespace std;

bool containsDuplicate2(vector<int> &nums, target k){
    unordered_map<int,int> map;
    for(int i=0;i<nums.size();i++){
        if(map.count(nums[i]) && i - map[nums[i]] <= k){
            return true;
        }
        map[nums[i]] = i;
    }
    return false;
}

int main(){
    vector<int> nums = {1,2,3,1};
    cout << containsDuplicate2(nums,3);
}