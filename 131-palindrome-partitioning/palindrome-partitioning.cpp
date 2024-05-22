class Solution {
public:
    int dp[17][17] = {0};

    vector<vector<string>> partition(string s) {
        vector<vector<string>> answer;
        setDp(s);
        vector<string> current;
        partitionString(s, 0, current, answer);
        return answer;
    }

    void partitionString(string s, int index, vector<string> &current, vector<vector<string>> &answer) {
        if (index == s.size()) {
            answer.push_back(current);
            return;
        }

        for (int i = index; i < s.size(); i++) {
            if (dp[index][i]) {
                current.push_back(s.substr(index, i - index + 1));
                partitionString(s, i + 1, current, answer);
                current.pop_back();
            }
        }
    }

    void setDp(string s) {
        int n = s.size();
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = 1;
            }
        }

        for (int len = 3; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = 1;
                }
            }
        }
    }
};
