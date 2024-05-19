class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long sum = 0;
        int minDifference = INT_MAX;
        int beneficialCount = 0;

        // Iterate over all nodes to calculate the possible maximum sum
        for (int i = 0; i < nums.size(); i++) {
            int originalValue = nums[i];
            int xorValue = nums[i] ^ k;

            if (xorValue > originalValue) {
                sum += xorValue;
                beneficialCount++;
                minDifference = min(minDifference, xorValue - originalValue);
            } else {
                sum += originalValue;
                minDifference = min(minDifference, originalValue - xorValue);
            }
        }

        // If the count of beneficial operations is odd, adjust the sum
        if (beneficialCount % 2 == 1) {
            sum -= minDifference;
        }

        return sum;
    }
};
