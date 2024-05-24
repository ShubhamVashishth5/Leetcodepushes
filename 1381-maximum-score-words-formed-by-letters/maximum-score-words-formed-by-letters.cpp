class Solution {
public:

    int maxScoreWords(vector<string>& words, vector<char>& letters,
                      vector<int>& score) {
        vector<int> lettersCount(26, 0);

        for (int i = 0; i < letters.size(); i++) {
            lettersCount[letters[i] - 'a']++;
        }
        int current = 0, maxx = 0, index = 0;
        maxScore(words, current, score, lettersCount, maxx, index);
        return maxx;
    }

    void maxScore(vector<string>& words, int& current, vector<int>& score,
                  vector<int>& letters, int& maxx, int index) {

        maxx = max(maxx, current);
        for (int i = index; i < words.size(); i++) {
            bool shouldInsert = true;
            
            for (char s : words[i]) {
                letters[s - 'a']--;
                current += score[s - 'a'];
            }
            for (int i = 0; i < 26; i++) {
                if (letters[i] < 0)
                    shouldInsert = false;
            }
            if (shouldInsert)
                maxScore(words, current, score, letters, maxx, i + 1);

            for (char s : words[i]) {
                letters[s - 'a']++;
                current -= score[s - 'a'];
            }
        }
    }
};