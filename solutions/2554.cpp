class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> st(banned.begin(), banned.end());
        int count = 0;
        for (int i = 1; i <= n; ++i) {
            if (maxSum < i) break;
            if (st.count(i)) continue;
            count++;
            maxSum -= i;
        }
        return count;
    }
};