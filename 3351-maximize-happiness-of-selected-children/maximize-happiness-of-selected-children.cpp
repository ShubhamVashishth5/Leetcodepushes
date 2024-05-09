class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long maxHappiness=0;
        priority_queue<int> pq;
        for(int i:happiness){
            pq.push(i);
        }
        int i=0;
        while(i<k){
            maxHappiness += max( (pq.top()-i),0);
            i++;
            pq.pop();
        }
        return maxHappiness;
    }
};