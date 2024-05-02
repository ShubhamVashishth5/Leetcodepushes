class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows= matrix.size();
        int column= matrix[0].size();
        int count= rows*column;
        int start= 0;
        int end= count;
        int mid= start+ (end-start)/2;
        //std::cout<<rows<<column<<start<<mid<<end<<getAtIndex(mid, column, matrix);

        while(start<end){
            int curr= matrix[mid/column][mid%column]; //getAtIndex(mid, column, matrix);
            std::cout<<mid;
            if(curr>target){
                end= mid;
                mid= start+ (end-start)/2;;
            }
            else if(curr<target){
                start=mid+1;
                mid= start+ (end-start)/2;
            }
            else if(curr==target) return true;

        }
        return false;
    }

    int getAtIndex(int index, int col, vector<vector<int>>& matrix){
        return matrix[index/col][index%col];
    }

};