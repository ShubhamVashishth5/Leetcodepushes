class Solution {
public:
    int numSteps(string s) {
        int steps = 0, end = s.size()-1,  start=0;
        for (;end > start;) {
            if (s[end] == '0') {
                end--;
                steps++;
            } else {
                int carry = 1;
                int  j=start;
                for(int i=end; i>j;i--){
                    if(carry==0)s[i]=s[i-1];
                    else{
                        if(s[i-1]=='0'){s[i]='1'; carry=0; start++;}
                        else{
                            s[i]='0';
                        }
                    }
                }
                steps+=2;
            }
        }
        return steps;
    }
};