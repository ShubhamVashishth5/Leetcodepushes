class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        //   priority_queue<pair<int, int>,
        //   vector<pair<int,int>,decltype(&compare)> pq;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       decltype(&comparePairs)>
            pq(&comparePairs);

        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                pair<int, int> fraction = pair(arr[i], arr[j]);
                if (pq.size() < k || comparePairs(fraction, pq.top())) pq.push(fraction);
                if(pq.size()>k)pq.pop();
            }
        }
        return {pq.top().first, pq.top().second};
    }

    static bool comparePairs(const pair<int, int>& one,
                             const pair<int, int>& two) {
        return one.first * two.second < two.first * one.second;
    }
};