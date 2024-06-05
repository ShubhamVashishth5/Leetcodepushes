class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int count[101][26] = {0}; 
        int size = words.size();

        for (int i = 0; i < size; i++) {
            for (char c : words[i]) {
                count[i][c - 'a']++;
            }
        }

        vector<string> ans;

        for (int i = 0; i < 26; i++) {
            int minCount = INT_MAX;
            for (int j = 0; j < size; j++) {
                minCount = min(minCount, count[j][i]);
            }
            for (int k = 0; k < minCount; k++) {
                ans.push_back(string(1, i + 'a'));
            }
        }

        return ans;
    }
};
