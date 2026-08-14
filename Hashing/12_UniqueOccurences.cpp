#include<bits/stdc++.h>
using namespace std;

bool UniqueOccurences(vector<int>&nums){
    unordered_map<int,int> map;
    unordered_set<int> set;
    for(int i=0;i<nums.size();i++){
        map[nums[i]]++;
    }
    for(auto x: map){
        if(set.count(x.second) == 1){
            return false;
        } else {
            set.insert(x.second);
        }
    }
    return true;
}

int main(){
    vector<int> nums = {1,2};
    cout << UniqueOccurences(nums);
}