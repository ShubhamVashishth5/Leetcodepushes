class Solution {
public:
    int minOperations(vector<string>& logs) {
        int distance=0;
        for(string s: logs){
            if(s=="../"){distance = max(distance-1,0 );}
            else if(s=="./") continue;
            else distance++;
        }
        return distance;
    }
};