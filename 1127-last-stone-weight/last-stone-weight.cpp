class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int x: stones){
            pq.push(x);
        }
        int n=pq.size();
        std::cout<<pq.size();

        while(!pq.empty()){
            if(pq.size()==1)return pq.top();
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            if(first-second!=0){pq.push(first-second); n--;}
            else n=n-2;
        }
        return pq.empty()?0:pq.top();
    }
};