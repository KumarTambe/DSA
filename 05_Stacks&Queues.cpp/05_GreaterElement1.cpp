#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1,vector<int>& nums2) {
    unordered_map<int,int> map;
    stack<int> st;
    int n = nums2.size();
    for(int i=n-1; i>=0;i--){
        while(!st.empty() && st.top() <= nums2[i]){
            st.pop();
        }
        if(st.empty()) {
            map[nums2[i]] = -1;
        }
        else {
            map[nums2[i]] = st.top();
        }
        st.push(nums2[i]);
    }
    for(int i=0;i<nums1.size();i++){
        if(map.count(nums1[i]) == 1){
            nums1[i] = map[nums1[i]];
        }
    }
    return nums1;
}

