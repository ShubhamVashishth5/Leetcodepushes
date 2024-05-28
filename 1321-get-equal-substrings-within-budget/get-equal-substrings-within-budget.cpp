class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int start = 0, end = 0, currentCost = 0, maxLength = 0;

        while (end < s.length()) {
            // Add the cost of transforming the current character
            currentCost += abs(s[end] - t[end]);

            // If the current cost exceeds maxCost, move the start pointer to the right
            while (currentCost > maxCost) {
                currentCost -= abs(s[start] - t[start]);
                start++;
            }

            // Calculate the maximum length of the valid window
            maxLength = max(maxLength, end - start + 1);

            // Move the end pointer to the right
            end++;
        }

        return maxLength;
    }
};
