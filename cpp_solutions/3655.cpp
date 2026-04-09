class Solution {
public:
    long long mod = 1e9 + 7;
    long long inv(long long a) {
        if (a == 1) return 1;
        return (mod - mod / a) * inv(mod % a) % mod;
    }
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int threshold = 320;
        vector<vector<vector<int>>> smallQueries(threshold + 1);
        int n = nums.size();
        vector<long long> multiply(n, 1);
        
        for (auto q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            if (k <= threshold) {
                smallQueries[k].push_back(q);
            }
            else {
                for (int index = l; index <= r; index += k) {
                    multiply[index] *= v;
                    multiply[index] %= mod;
                }
            }
        }

        for (int thres = 0; thres <= threshold; ++thres) {
            if (smallQueries[thres].empty()) continue;
            vector<long long> diff(n + 1, 1);
            for (auto& q : smallQueries[thres]) {
                int l = q[0], r = q[1], k = q[2], v = q[3];
                int rr = (r - l) / k * k + l;
                diff[l] *= v;
                diff[l] %= mod;
                if (rr + k <= n) diff[rr + k] = diff[rr + k] * inv(v) % mod;
            }
            vector<long long> tempMultiply(n + 1, 1);
            for (int i = 0; i < n; ++i) {
                tempMultiply[i] = (i >= thres ? tempMultiply[i - thres] : 1) * diff[i] % mod;
            }
            for (int i = 0; i < n; ++i) {
                multiply[i] = multiply[i] * tempMultiply[i] % mod;
            }
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            long long val = nums[i] * multiply[i] % mod;
            res ^= (int)val;
        }
        return res;
    }
};
