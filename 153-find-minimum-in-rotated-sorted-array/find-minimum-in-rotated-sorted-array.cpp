class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0, high=nums.size()-1;
        int mid=(high+low)/2;
        while(low<high){
            int mid=(high+low)/2;
            if(nums[low]<nums[high])return nums[low];
            else{
                if(nums[low]<=nums[mid]){
                    low=mid+1;
                }
                else high = mid;
            }
        }

        return nums[low];
    }
};