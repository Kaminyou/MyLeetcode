class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        vector<bool> suitables(n, false);
        for (int i = 0; i < n; ++i) {
            if (nums[i] % modulo == k) suitables[i] = true;
        }
        unordered_map<int, int> mp;
        long long res = 0;
        int accum = 0;
        mp[0] = 1;
        for (int i = 0; i < n; ++i) {
            if (suitables[i]) accum += 1;
            if (accum >= k) {
                int target = (accum - k) % modulo;
                res += mp[target];
            }
            mp[accum % modulo]++;
        }
        return res;
    }
};

