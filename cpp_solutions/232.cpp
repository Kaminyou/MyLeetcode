class MyQueue {
public:
    int cnt = 0;
    stack<int> in;
    stack<int> out;
    MyQueue() {
        
    }
    
    void push(int x) {
        cnt++;
        in.push(x);
    }
    
    int pop() {
        trasfer();
        cnt--;
        int x = out.top();
        out.pop();
        return x;
    }
    
    int peek() {
        trasfer();
        return out.top();
    }
    
    bool empty() {
        return cnt == 0;
    }

    void trasfer() {
        if (out.empty()) {
            while (!in.empty()) {
                int x = in.top();
                in.pop();
                out.push(x);
            }
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */