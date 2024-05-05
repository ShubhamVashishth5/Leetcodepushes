class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int low = 1,  high= piles.back();
        int mid=low + (high-low)/2;
        while(low<high){
            int sum =0;
        for(int i=0;i<piles.size();i++){
            sum+= piles[i]/mid + (piles[i]%mid != 0);
        }

            if (sum>h){
                low=mid+1;
            }
            else{
                high= mid;
            }
            mid = low + (high-low)/2;
        }
        return mid;
    }

    int getTime(vector<int>& piles, int h){
        int sum =0;
        for(int i=0;i<piles.size();i++){
            sum+= piles[i]/h + (piles[i]%h != 0);
        }
        return sum;
    }

};