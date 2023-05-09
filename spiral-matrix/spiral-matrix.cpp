class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> answer;

        

        int col= matrix[0].size();
                int row= matrix.size();
                int run =(row%2==0)?row/2:row/2+1;
            

        for(int i=0;i<run;i++){

    for(int j=i;j<col-i;j++){
    answer.push_back(matrix[i][j]);
    }
    for(int j=i+1;j<row-i && col-i-1>=col/2;j++){
        answer.push_back(matrix[j][col-i-1]);
    }
    if(i+1<=(row-i-1)){
    for(int j=col-i-2;j>=i;j--)
        answer.push_back(matrix[row-i-1][j]);

if(i+1<=(col-i-1))
    for(int j= row-i-2; j>i ;j--)
        answer.push_back(matrix[j][i]);}

    }
    return answer;
    }
};