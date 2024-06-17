class Solution {
public:
    bool judgeSquareSum(int c) {
        long long i=0, j=sqrt(c);
        while(i<=j){
            long long cal= i*i+j*j;
            if(cal == c)return true;
            else if(cal >c)j=j-1;
            else i=i+1;
        }   
        return false;
    }
};