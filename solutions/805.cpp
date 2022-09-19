class Solution {
public:
    unordered_map<string, int> memo;
    // use k element from arr[0, i] to achieve target
    bool dp(vector<int>& nums, int i, int n, int target, int k) {
        if (k == 0) return target == 0;
        if (i == n) return false;
        string key = to_string(i) + "#" + to_string(k) + "#" + to_string(target);
        if (memo.find(key) != memo.end()) return memo[key];
        if (nums[i] <= target) {
            return memo[key] = dp(nums, i + 1, n, target - nums[i], k - 1) || dp(nums, i + 1, n, target, k);
        }
        else {
            return memo[key] = dp(nums, i + 1, n, target, k);
        }
    }
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size();
        int m = n / 2;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        for (int i = 1; i <= m; ++i) {
            if ((sum * i) % n == 0) {
                if (dp(nums, 0, n, sum * i / n, i)) return true;
            }
        }
        return false;
    }
};