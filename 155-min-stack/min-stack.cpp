class MinStack {
public:

    vector<int> stack;
    vector<int> minStack;
    int min;

    MinStack() {
        min=INT_MAX;
    }
    
    void push(int val) {
        stack.push_back(val);
        if(val<min)min=val;
        minStack.push_back(min);
    }
    
    void pop() {
        stack.pop_back();
        minStack.pop_back();
        if(stack.empty())
        min=INT_MAX;
        else min=minStack.back();
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return minStack.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */