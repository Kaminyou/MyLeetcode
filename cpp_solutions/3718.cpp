class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st(nums.begin(), nums.end());
        int step = k;
        while (st.count(k)) {
            k += step;
        }
        return k;
    }
};
