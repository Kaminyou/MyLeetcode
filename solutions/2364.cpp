class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        // bad pair: (i < j) && (j - i != nums[j] - nums[i])
        // not bad pair: (i < j) && (j - i == nums[j] - nums[i])
        // => (j - nums[j] == i - nums[i])
        unordered_map<long long, long long> mp;
        int n = nums.size();
        long long res;
        for (int i = 0; i < n; ++i) {
            long long diff = i - nums[i];
            res += mp[diff];
            mp[diff]++;
        }
        long long total = (long long)n * (n - 1) / 2;
        return total - res;
    }
};