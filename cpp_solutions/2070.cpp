class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<pair<int, int>> Q;
        int n = queries.size();
        int m = items.size();
        for (int i = 0; i < n; ++i) {
            Q.push_back({queries[i], i});
        }
        sort(items.begin(), items.end());
        sort(Q.begin(), Q.end());
        set<int> st;
        int index = 0;
        vector<int> res(n, 0);
        for (auto& q : Q) {
            while (index < m && items[index][0] <= q.first) {
                st.insert(items[index][1]);
                index++;
            }
            if (!st.empty()) {
                res[q.second] = *st.rbegin();
            }
        }
        return res;
    }
};
