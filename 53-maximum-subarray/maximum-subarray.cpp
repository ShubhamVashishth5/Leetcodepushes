class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int total = 0;
        for (int i = 0; i < nums.size(); i++) {
            total += nums[i];
            
            maxSum = max(total, maxSum);
            if (total < 0)
                total = 0;
        }
        return maxSum;
    }
};