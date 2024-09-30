class CustomStack {
public:
    stack<int> st;
    vector<int> v;
    int maxSize;
    CustomStack(int max_size) {
        v.resize(max_size, 0);
        maxSize = max_size;
    }
    
    void push(int x) {
        if (st.size() < maxSize) {
            st.push(x);
        }
    }
    
    int pop() {
        if (st.empty()) return -1;
        int index = st.size() - 1;
        int result = st.top() + v[index];
        st.pop();
        if (index > 0) {
            v[index - 1] += v[index];
        }
        v[index] = 0;
        return result;
    }
    
    void increment(int k, int val) {
        int limit = min(k, int(st.size()));
        if (limit > 0) {
            v[limit - 1] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
