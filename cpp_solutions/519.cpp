class Solution {
public:
    int size;
    int row;
    int col;
    unordered_map<int, int> mp;
    Solution(int m, int n) {
        row = m;
        col = n;
        size = m * n;
    }
    
    vector<int> flip() {
        int index = rand() % size;
        int temp = index;
        size--;
        if (mp.find(index) != mp.end()) index = mp[index];
        mp[temp] = mp.count(size) ? mp[size] : size;
        return {index / col, index % col};
    }
    
    void reset() {
        mp.clear();
        size = row * col;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */