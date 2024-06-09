class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        long sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int remainder = sum % k;
            if (remainder < 0)
                remainder = k + remainder;

            count+= mp[remainder];
            mp[remainder]++;
        }
        return count;
    }
};