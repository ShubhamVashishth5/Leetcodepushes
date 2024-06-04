class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> counter;
        for(int i=0;i<s.length();i++){
            counter[s[i]]++;
        }
        bool odd=false;
        int total=0;
         for (auto x : counter) {
            if(x.second%2!=0)
            {odd=true;
            total+= (x.second-1);
            }
            else total+=x.second;
         }
        return odd?total+1:total;
    }
};