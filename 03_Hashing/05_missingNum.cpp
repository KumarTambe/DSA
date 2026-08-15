#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> &nums){
    unordered_set<int> set(nums.begin(),nums.end());
    int n = nums.size();
    for( int i = 0; i <= n;i++){
        if(set.count(i) == 0){
            return i;
        }
    }
    return -1;
}

int main(){
    vector<int> nums = {3,0,1};
    cout << missingNumber(nums);
}
