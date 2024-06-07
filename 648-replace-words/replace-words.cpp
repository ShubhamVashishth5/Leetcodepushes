class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> stringSet(dictionary.begin(), dictionary.end());
        string result;
        int start = 0;

        while (start < sentence.size()) {
            int end = start;
            while (end < sentence.size() && sentence[end] != ' ') {
                ++end;
            }
            
            string word = sentence.substr(start, end - start);
            string prefix = word;

            for (int len = 1; len <= word.length(); ++len) {
                string sub = word.substr(0, len);
                if (stringSet.find(sub) != stringSet.end()) {
                    prefix = sub;
                    break;
                }
            }

            if (!result.empty()) {
                result += ' ';
            }
            result += prefix;

            start = end + 1;
        }

        return result;
    }
};