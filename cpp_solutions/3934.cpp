class Solution {
public:
    bool valid(int length, vector<int>& nums, vector<long long>& prefix, vector<long long>& multi) {
        unordered_map<long long, int> cnt;
        long long mod = 1e9 + 7;
        int n = nums.size();
        for (int i = 0; i + length <= n; ++i) {
            // [i, i + length)
            long long hash = (prefix[i + length] - prefix[i] * multi[length] % mod + mod) % mod; 
            cnt[hash]++;
        }
        for (auto& [val, c] : cnt) {
            if (c == 1) return true;
        }
        return false;
    }
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        long long base = 1001;
        long long mod = 1e9 + 7;
        vector<long long> prefix(n + 1, 1);
        vector<long long> multi(n + 1, 1);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] * base + nums[i];
            multi[i + 1] = multi[i] * base;
            prefix[i + 1] %= mod;
            multi[i + 1] %= mod;
        }

        int left = 1;
        int right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (valid(mid, nums, prefix, multi)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};
