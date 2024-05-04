class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        for (int i = 1000; i >= 1; --i) {
            if (st.find(i) != st.end() && st.find(-i) != st.end()) return i;
        }
        return -1;
    }
};