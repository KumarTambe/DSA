// LeetCode #349 - Intersection of Two Arrays
#include <bits/stdc++.h>
using namespace std;

vector<int> commonNums(vector<int>& nums1, vector<int>& nums2){
    unordered_set<int> intersectionSet(nums1.begin(), nums1.end());
    unordered_set<int> Result;
    
    for(int i = 0; i < nums2.size(); i++){
        if(intersectionSet.count(nums2[i]) == 1){
            if(Result.count(nums2[i]) == 1){
                continue;
            } else {
                Result.insert(nums2[i]);
            }
        }
    }
    vector<int> res(Result.begin(), Result.end());
    return res;
}

int main(){
    vector<int> nums1 = {4,9,5};
    vector<int> nums2 = {9,4,9,8,4};
    vector<int> Res = commonNums(nums1, nums2);
    for(auto x : Res){
        cout << x << endl;
    }
}
