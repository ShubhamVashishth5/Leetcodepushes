class Solution {
public:
        int costD[1002]={0};

    int minCostClimbingStairs(vector<int>& cost) {
        int size= cost.size();
        for(int i=cost.size()-1;i>=0;i--){
            costD[i]= cost[i]+ min(costD[i+1],costD[i+2]);
        }
        return min(costD[0], costD[1]);
    }
};