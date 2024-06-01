class Solution {
public:
    int hammingWeight(int n) {
        long rev=0;
        int count=0;
        while(n!=0){
            n= (n^ (n& -n));
            count++;
        }
        return count;
    }
};