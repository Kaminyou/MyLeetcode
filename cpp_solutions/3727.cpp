class Solution {
public:
    static bool compare(int a, int b) {
        return abs(a) < abs(b);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), compare);
        int half = n / 2;
        long long res = 0;
        for (int i = 0; i < half; ++i) {
            res -= nums[i] * nums[i];
        }
        for (int i = half; i < n; ++i) {
            res += nums[i] * nums[i];
        }
        return res;
    }
};
