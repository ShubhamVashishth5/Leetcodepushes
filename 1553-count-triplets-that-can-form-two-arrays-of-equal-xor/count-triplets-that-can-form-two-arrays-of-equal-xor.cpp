class Solution {
public:
    int countTriplets(vector<int>& arr) {
        vector<int> prefix;
        int size=arr.size();
        prefix.push_back(0);
        for(int i=0;i<size;i++){
            prefix.push_back(prefix[i]^arr[i]);
        }

        int count=0;
        for(int i=0;i<size;i++){
            for(int j=i+1;j<size;j++){
                if(prefix[i]==prefix[j+1])
                count+=(j-i);
            }
        }
        return count;
    }
};