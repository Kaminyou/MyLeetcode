class Solution {
public:
    int rev(int num) {
        int res = 0;
        while (num) {
            res *= 10;
            res += num % 10;
            num /= 10;
        }
        return res;
    }
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> counts;
        for (int i = 0; i < n; ++i) {
            int computed = nums[i] - rev(nums[i]);
            counts[computed] += 1;
        }
        long long res = 0;
        long long mod = 1e9 + 7;
        for (auto& p : counts) {
            long long count = p.second;
            res += (count * (count - 1)) >> 1;
            res %= mod;
        }
        return res;
    }
};
