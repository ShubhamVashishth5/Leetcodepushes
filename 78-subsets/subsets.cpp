class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> initial;
        vector<vector<int>> result;
        getSubsets(nums, 0, initial, result);
        return result;
    }

    void getSubsets(vector<int>& nums, int index, vector<int> &current, vector<vector<int>> &result){
        
        for(int i=index;i<nums.size();i++){
            current.push_back(nums[i]);
            getSubsets(nums, i+1, current, result);
            current.pop_back();
        }
        result.push_back(current);
    }

};