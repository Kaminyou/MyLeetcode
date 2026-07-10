class Solution {
    int up[100005][18];
public:
    int step(int u, int s) {
        for (int i = 0; i <= 17; ++i) {
            if ((s >> i) & 1) {
                u = up[u][i];
            }
        }
        return u;
    }
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; ++i) {
            arr.push_back({nums[i], i});
        }
        sort(arr.begin(), arr.end());
        vector<int> indexMapping(n, -1);
        for (int i = 0; i < n; ++i) {
            indexMapping[arr[i].second] = i;
        }
        int right = 0;
        for (int left = 0; left < n; ++left) {
            while (right + 1 < n && arr[right + 1].first - arr[left].first <= maxDiff) right++;
            up[left][0] = right;
        }

        for (int k = 1; k <= 17; ++k) {
            for (int i = 0; i < n; ++i) {
                up[i][k] = up[up[i][k - 1]][k - 1];
            }
        }

        vector<int> res;
        for (auto& q : queries) {
            int x = indexMapping[q[0]];
            int y = indexMapping[q[1]];
            if (x > y) swap(x, y);
            if (x == y) {
                res.push_back(0);
                continue;
            }
            int low = 1;
            int high = 1e5;
            while (low < high) {
                int mid = low + (high - low) / 2;
                int reach = step(x, mid);
                if (arr[reach].first >= arr[y].first) high = mid;
                else low = mid + 1;
            }
            int reach = step(x, low);
            if (arr[reach].first >= arr[y].first) {
                res.push_back(low);
            }
            else {
                res.push_back(-1);
            }
        }
        return res;
    }
};
