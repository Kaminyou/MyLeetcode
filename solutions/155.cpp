class MinStack {
public:
    stack<int> st;
    stack<int> stMin;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if (stMin.empty()) stMin.push(val);
        else {
            int top = stMin.top();
            stMin.push(min(top, val));
        }
    }
    
    void pop() {
        st.pop();
        stMin.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return stMin.top();
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