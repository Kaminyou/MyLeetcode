class Solution {
public:
    unordered_map<int, int> mp;
    set<int> st;
    int validSize = 0;
    Solution(int n, vector<int>& blacklist) {
        validSize = n - blacklist.size();
        int idx = validSize;
        for (auto& num : blacklist) st.insert(num);
        for (auto& num : st) {
            if (num < validSize) {
                while (st.find(idx) != st.end()) idx++;
                mp[num] = idx;
                idx++;
            }
        }
    }
    
    int pick() {
        int rnd = rand() % validSize;
        if (mp.find(rnd) != mp.end()) return mp[rnd];
        return rnd;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */
