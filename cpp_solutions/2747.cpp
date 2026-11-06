class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b) {
        if (a[1] != b[1]) return a[1] < b[1];
        return a[0] < b[0];
    }
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int k = logs.size();
        sort(logs.begin(), logs.end(), compare);
        int m = queries.size();
        vector<pair<int, int>> indexQ;
        for (int i = 0; i < m; ++i) indexQ.push_back({queries[i], i});
        sort(indexQ.begin(), indexQ.end());

        vector<int> res(m, 0);
        unordered_map<int, int> mp;
        int left = 0;
        int right = 0;
        // [left, right)
        for (int i = 0; i < m; ++i) {
            int index = indexQ[i].second;
            int end = indexQ[i].first;
            int start = end - x;
            while (right < k && logs[right][1] <= end) {
                int val = logs[right][0];
                mp[val]++;
                right++;
            }
            while (left < k && logs[left][1] < start) {
                int val = logs[left][0];
                mp[val]--;
                if (mp[val] == 0) mp.erase(val);
                left++;
            }
            res[index] = n - mp.size();
        }
        return res;
    }
};

