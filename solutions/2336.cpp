class SmallestInfiniteSet {
public:
    
    set<int> st;
    SmallestInfiniteSet() {
        for (int i = 1; i <= 1000; ++i) st.insert(i);
    }
    
    int popSmallest() {
        int left = *st.begin();
        st.erase(st.begin());
        return left;
    }
    
    void addBack(int num) {
        st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */