class Solution {
public:
    bool valid(vector<int>& v, int mid, int target, vector<int>& heights) {
        return heights[v[mid]] < target;
    }
    int binarySearch(vector<int>& v, vector<int>& heights, int target) {
        int left = 0;
        int right = v.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (valid(v, mid, target, heights)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int m = queries.size();
        vector<int> res(m, -1);
        vector<pair<int, pair<int, int>>> q2;
        for (int i = 0; i < m; ++i) {
            int x = queries[i][0];
            int y = queries[i][1];
            if (x == y) res[i] = y;
            else{
                if (x > y) swap(x, y);
                // y >= x
                if (heights[y] > heights[x]) res[i] = y;
                else {
                    q2.push_back({y, {i, heights[x]}});
                }
            }
        }
        sort(q2.begin(), q2.end(), greater());
        int n = heights.size();
        int current = n - 1;
        vector<int> st;
        for (auto& q : q2) {
            int index = q.second.first;
            int now = q.first;
            int height = q.second.second;
            while (current >= now) {
                while (!st.empty() && heights[st[st.size() - 1]] < heights[current]) {
                    st.pop_back();
                }
                st.push_back(current);
                current--;
            }
            int k = st.size();
            int t = binarySearch(st, heights, height + 1);
            if (t != 0) res[index] = st[t - 1];
        }
        return res;
    }
};
