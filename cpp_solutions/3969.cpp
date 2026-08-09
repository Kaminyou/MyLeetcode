class Solution {
public:
    bool valid(long long sum , int x) {
        int index = 0;
        int digit = -1;
        while (sum) {
            digit = sum % 10;
            if (index == 0 && digit != x) return false;
            sum /= 10;
            index++;
        }
        return digit == x;
    }
    int countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= n; ++j) {
                // [i, j]
                long long sum = prefix[j] - prefix[i - 1];
                if (valid(sum, x)) res++;
            }
        }
        return res;
    }
};
