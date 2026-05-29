class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n, 1);
        vector<pair<int, int>> arrIdx;
        for (int i = 0; i < n; ++i) {
            arrIdx.push_back({arr[i], i});
        }
        sort(arrIdx.begin(), arrIdx.end());
        int res = 1;
        for (auto [num, idx] : arrIdx) {
            int first = max(0, idx - d);
            int last = min(n - 1, idx + d);
            for (int cur = idx - 1; cur >= first; cur--) {
                if (arr[cur] > num) {
                    dp[cur] = max(dp[cur], dp[idx] + 1);
                    res = max(res, dp[cur]);
                    break;
                }
            }
            for (int cur = idx + 1; cur <= last; cur++) {
                if (arr[cur] > num) {
                    dp[cur] = max(dp[cur], dp[idx] + 1);
                    res = max(res, dp[cur]);
                    break;
                }
            }
        }
        return res;
        
    }
};
