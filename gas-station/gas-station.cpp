class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int size= gas.size();
        int index=0; bool found=false;
        int tc=0, tg=0;
        int sum=0;
        for(int i=0;i<size;i++){

          tc+=cost[i];
          tg+=gas[i]; 
        if(sum+ gas[i]< cost[i])
        {index= i+1;sum=0;}
        else sum= sum + gas[i] - cost[i];
         }
        return (tg<tc)?-1:index;
    }
};