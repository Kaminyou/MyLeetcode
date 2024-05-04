class ExamRoom {
public:
    set<int> st;
    int n;
    ExamRoom(int n) {
        this->n = n;
    }
    
    int seat() {
        int current = 0;
        int maxInterval = 0;
        int idx = 0;
        for (auto& position : st) {
            if (current == 0) {
                if (position - current > maxInterval) {
                    maxInterval = position - current;
                    idx = 0;
                }
            }
            else {
                if ((position - current + 1) / 2 > maxInterval) {
                    maxInterval = (position - current + 1) / 2;
                    idx = current + maxInterval - 1;
                }
            }
            current = position + 1;
        }
        if (current > 0 && n - current > maxInterval) {
            maxInterval = n - current;
            idx = n - 1;
        }
        st.insert(idx);
        return idx;
    }
    
    void leave(int p) {
        st.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
