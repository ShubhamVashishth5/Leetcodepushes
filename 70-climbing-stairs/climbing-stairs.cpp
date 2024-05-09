class Solution {
public:
    int climbStairs(int n) {
        int a=1;int b=2;
        int next;
        for(int i=0;i<n-2;i++){
            next=a+b;
            a=b;
            b=next;
        }
        return next;
    }

};