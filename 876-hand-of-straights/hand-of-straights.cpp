class Solution {
public:
      bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) {
            return false;
        }
        
        // Count the frequency of each card
        unordered_map<int, int> cardCount;
        for (int card : hand) {
            cardCount[card]++;
        }
        
        // Min-heap to store the card values
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (const auto& pair : cardCount) {
            minHeap.push(pair.first);
        }
        
        // Try to form groups
        while (!minHeap.empty()) {
            int first = minHeap.top();
            
            for (int i = 0; i < groupSize; i++) {
                int card = first + i;
                if (cardCount[card] == 0) {
                    return false;
                }
                cardCount[card]--;
                if (cardCount[card] == 0) {
                    if (card != minHeap.top()) {
                        return false;
                    }
                    minHeap.pop();
                }
            }
        }
        
        return true;
    }
};