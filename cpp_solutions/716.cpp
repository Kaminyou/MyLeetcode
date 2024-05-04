class MaxStack {
public:
    list<int> st;
    map<int, vector<list<int>::iterator>> mp;
    MaxStack() {
        
    }
    
    void push(int x) {
        st.insert(st.begin(), x);
        mp[x].push_back(st.begin());
    }
    
    int pop() {
        int x = st.front();
        st.pop_front();
        mp[x].pop_back();
        if (mp[x].size() == 0) mp.erase(x);
        return x;
    }
    
    int top() {
        return st.front();
    }
    
    int peekMax() {
        return mp.rbegin()->first;
    }
    
    int popMax() {
        int x = mp.rbegin()->first;
        auto it = mp.rbegin()->second.back();
        st.erase(it);
        mp[x].pop_back();
        if (mp[x].size() == 0) mp.erase(x);
        return x;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */