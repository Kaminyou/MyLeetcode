class MyStack {
public:
    int count;
    queue<int> q;
    MyStack() {
        count = 0;
    }
    
    void push(int x) {
        q.push(x);
        count++;
    }
    
    int pop() {
        for (int i = 0; i < count - 1; i++) {
            int x = q.front();
            q.pop();
            q.push(x);
        }
        int x = q.front();
        q.pop();
        count--;
        return x;
    }
    
    int top() {
        for (int i = 0; i < count - 1; i++) {
            int x = q.front();
            q.pop();
            q.push(x);
        }
        int x = q.front();
        q.pop();
        q.push(x);
        return x;
    }
    
    bool empty() {
        return count == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */