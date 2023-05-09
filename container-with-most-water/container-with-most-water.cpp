class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0, j= height.size()-1;
        int small= height[i]<height[j]?height[i]:height[j];
        int area= j*small;
        while(i<j){
           
           area = max(area, min(height[i], height[j])*(j-i));
           if(height[i]>height[j])j--;
           else i++;

        }
        return area;
    }
};