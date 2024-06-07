class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> stringSet(dictionary.begin(), dictionary.end());
        string result;
        int n = sentence.size();
        int start = 0;

        while (start < n) {
                       int end = start;
            while (end < n && sentence[end] != ' ') {
                ++end;
            }

            string word = sentence.substr(start, end - start);
            string prefix;
            bool found = false;

            for (int len = 1; len <= word.length(); ++len) {
                string sub = word.substr(0, len);
                if (stringSet.find(sub) != stringSet.end()) {
                    prefix = sub;
                    found = true;
                    break;
                }
            }

            // Append the prefix or the original word to the result
            if (!result.empty()) {
                result += ' ';
            }
            result += found ? prefix : word;

            // Move to the next word
            start = end + 1;
        }

        return result;
    }
};
