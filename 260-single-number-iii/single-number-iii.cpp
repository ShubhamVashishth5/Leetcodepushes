class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long xOr=0, size=nums.size(); 

        for(int i=0;i<size;i++){
            xOr= xOr^nums[i];
        }

        long lsb= (xOr & (-xOr) ); 

        int setOneXor=0, setTwoXor=0;
        for(int i=0;i<size;i++){
            if((nums[i]&lsb) !=0){
                setOneXor= setOneXor^nums[i];
            }
            else{
                setTwoXor= setTwoXor^nums[i];
            }
        }

        vector<int> ans = {setOneXor,setTwoXor};
        return ans;

    }
};