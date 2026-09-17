class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        unordered_map<int,int> map;
        for(int i = 0;i<nums.size();i++){
            map[nums[i]]++;
        }
        for(auto x : map){
            if(x.second > (n/3)){
                result.push_back(x.first);
            }
        }
        return result;
    }
};