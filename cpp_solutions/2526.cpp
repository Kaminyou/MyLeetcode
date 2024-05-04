class DataStream {
public:
    queue<int> q;
    multiset<int> st;
    long long v;
    int K;
    DataStream(int value, int k) {
        v = value;
        K = k;
    }
    
    bool consec(int num) {
        q.push(num);
        st.insert(num);
        if (q.size() > K) {
            int x = q.front();
            q.pop();
            st.erase(st.find(x));
        }
        if (q.size() < K) return false;
        return *st.begin() == v && *st.rbegin() == v;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */

 class DataStream {
public:
    int cnt = 0;
    int value = -1;
    int k;
    DataStream(int value, int k) {
        this->value = value;
        this->k = k;
    }
    
    bool consec(int num) {
        if (num == value) cnt++;
        else cnt = 0;
        return cnt >= k;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */