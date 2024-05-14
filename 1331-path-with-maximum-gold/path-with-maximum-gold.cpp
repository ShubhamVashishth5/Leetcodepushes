class Solution {
public:
    int maxSum =0, row, col;
    int getMaximumGold(vector<vector<int>>& grid) {
        row= grid.size();
        col= grid[0].size(); 
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                getMaxGold(grid,i,j,0);
            }
        }
        return maxSum;
    }

    void getMaxGold(vector<vector<int>> &grid, int i, int j, int sum){
        if( i<0 || i==row||j<0||j==col || grid[i][j]==0 )return;
        sum += grid[i][j];
        int temp = grid[i][j];
        maxSum= max(sum, maxSum);
        grid[i][j]=0;
        getMaxGold(grid, i+1,j, sum);
        getMaxGold(grid,i,j+1, sum);
        getMaxGold(grid,i-1,j, sum);
        getMaxGold(grid,i,j-1,sum);
        grid[i][j]=temp;
    }

};