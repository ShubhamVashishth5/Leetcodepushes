class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int freq[101]={0};
        
        for(int x : heights)freq[x]++;
        int index=0, error=0;
        for(int i=0;i<101&& index<heights.size();i++){
            while(freq[i]-- &&index<heights.size()){
                if(i!=heights[index++])
                error++;
            }
        }

        return error;
    }
};