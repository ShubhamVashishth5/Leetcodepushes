class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int total=0, curr=0;
        int index=0;
        return subsetXorSum(nums, index, curr);
            }

    int subsetXorSum(vector<int>& nums, int index, int curr){
        if(index== nums.size())return curr;
        return subsetXorSum(nums, index+1, curr) + subsetXorSum(nums, index+1, curr^nums[index]);
    }

};