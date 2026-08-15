#include<bits/stdc++.h>
using namespace std;

vector<int> intersection2(vector<int>&nums1,vector<int>&nums2){
    vector<int> res;
    unordered_map<int,int> map;
    for(auto x : nums1){
        map[x]++;
    }
    for(int i=0;i<nums2.size();i++){
        if(map[nums2[i]] > 0){
            res.push_back(nums2[i]);
            map[nums2[i]]--;
        }
    }
    return res;
    
}