#include<bits/stdc++.h>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2){
    unordered_set<int> set(nums2.begin(),nums2.end());
    unordered_set<int> result;
    
    for(int i=0;i<nums1.size();i++){
        if(set.count(nums1[i]) == 1){
            if(result.count(nums1[i]) == 1){
                continue;
            } else{
                result.insert(nums1[i]);
            }
        }
    }
    vector<int> Result(result.begin(),result.end());
    return Result;
}

int main(){
    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};
    vector<int> res = intersection(nums1,nums2);
    for(auto x: res){
        cout << x << " ";
    }
}