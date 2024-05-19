class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long sum = 0;
        long long cnt = 0;
        long long sacrifice = INT_MAX;
        for (long long n : nums) {
            sum += max(n ^ k, n);
            cnt += (n ^ k) > n;
            sacrifice = min(sacrifice, abs(n - (n ^ k)));
        }
        return sum - (cnt % 2 ? sacrifice : 0);
    }
};
