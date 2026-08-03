#include<bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums){
    unordered_set<int> set(nums.begin(), nums.end());
    int maxLen = 0;
    
    for(int num : nums){
        if(set.count(num-1) == 0){
            int currentNum = num;
            int currentLength = 1;
            while(set.count(currentNum+1) == 1){
                currentNum++;
                currentLength++;
            }
            maxLen = max(currentLength,maxLen);
        }
    }
    return maxLen;
}

int main(){
    vector<int> nums = {22,11,2,3,4,5,6,1};
    cout << longestConsecutive(nums);
}
