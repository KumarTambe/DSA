
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums){
        int currentMinSum = nums[0];
        int currentSum = nums[0];
        int maxSum = nums[0];
        int minSum = nums[0];
        int total = nums[0];
        for(int i=1;i<nums.size();i++){
            if(currentMinSum > 0){
                currentMinSum = nums[i];
            }else{
                currentMinSum += nums[i];
            }
            minSum = min(currentMinSum , minSum);
        }
        for(int i =1;i<nums.size();i++){
            if(currentSum < 0){
                currentSum = nums[i];
            } else {
                currentSum += nums[i];
            }
            total += nums[i];
            maxSum = max(currentSum , maxSum);
        }
        if(total - minSum == 0){
            return maxSum;
        }
        return max(maxSum , total - minSum);
    }
};
