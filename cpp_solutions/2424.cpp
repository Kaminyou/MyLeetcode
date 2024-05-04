class DisjointSet {
private:
    vector<int> parent;
    vector<int> rank;
    vector<int> size;
    int parentZeroSize = 1;
public:
    DisjointSet(int size) {
        parent.resize(size, 0);
        rank.resize(size, 0);
        this->size.resize(size, 1);
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
        }
    }
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void join(int x, int y) {
        int pX = find(x);
        int pY = find(y);
        if (pX == pY) return;
        if (rank[pX] > rank[pY]) {
            parent[pY] = pX;
            size[pX] += size[pY];
        }
        else if (rank[pX] < rank[pY]) {
            parent[pX] = pY;
            size[pY] += size[pX];
        }
        else {
            parent[pY] = pX;
            rank[pX]++;
            size[pX] += size[pY];
        }
    }
    int getParentZeroSize() {
        return size[find(0)];
    }
    
};
class LUPrefix {
public:
    DisjointSet* disjointSet;
    unordered_set<int> st;
    int res = 0;
    LUPrefix(int n) {
        disjointSet = new DisjointSet(n + 1);
        st.insert(0);
    }
    
    void upload(int video) {
        st.insert(video);
        if (st.find(video - 1) != st.end()) disjointSet->join(video, video - 1);
        if (st.find(video + 1) != st.end()) disjointSet->join(video, video + 1);
    }
    
    int longest() {
        return disjointSet->getParentZeroSize() - 1;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */