class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int total=0, index=0;
        vector<int> current;
        backTrack(nums, total, index, current,k);
        return total;
    }

    void backTrack(vector<int>& nums,int &total, int index, vector<int>& current, int k){
        if(current.size()!=0)total++;

        for(int i=index;i<nums.size();i++){
        bool isDiff= true;
        for(int number:current){
            if(abs(number-nums[i])==k)
            isDiff= false;
        }
        if(isDiff){
            
            current.push_back(nums[i]);
            backTrack(nums,total,i+1,current,k);
            current.pop_back();
        }
        }
    }
};