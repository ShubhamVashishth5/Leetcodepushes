class Solution {
public:
    int specialArray(vector<int>& nums) {
        // Sort the array
        sort(nums.begin(), nums.end());

        int n = nums.size();

        // Check for the condition where x = n
        if (nums[0] >= n) {
            return n;
        }

        // Iterate through the sorted array
        for (int i = 1; i <= n; i++) {
            if (nums[n - i] >= i && (n - i - 1 < 0 || nums[n - i - 1] < i)) {
                return i;
            }
        }
        return -1;
    }
};
