class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for(char c:s){
            if(c==')'){
                if(!stack.empty() && stack.top()=='(')
                stack.pop();
                else return false;
            }
            else if(c=='}'){
                if(!stack.empty() && stack.top()=='{')
                stack.pop();
                else return false;

            }else if(!stack.empty() &&  c==']'){
                if(stack.top()=='[')
                stack.pop();
                else return false;

            }
            else stack.push(c);
        }
        if(stack.empty())
        return true;
        else return false;
    }
};