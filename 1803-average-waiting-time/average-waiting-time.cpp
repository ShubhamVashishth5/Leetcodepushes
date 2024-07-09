class Solution {
public:

    vector<int> completion;
    double averageWaitingTime(vector<vector<int>>& customers) {
        
        double totalWaiting=0;
        double prevCompletion=customers[0][0];
        for(int i=0;i<customers.size();i++){
            totalWaiting += ( fmax(prevCompletion,customers[i][0] ) - customers[i][0] + customers[i][1]);
            prevCompletion = (fmax(prevCompletion, customers[i][0])+ customers[i][1]) ;
        }

        return double(totalWaiting)/customers.size();
    }
};