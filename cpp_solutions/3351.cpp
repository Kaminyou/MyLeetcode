class Solution {
public:
    int sumOfGoodSubsequences(vector<int>& nums) {
        int n = nums.size();
        long long mod = 1e9 + 7;
        vector<long long> left(n, 0);
        vector<long long> right(n, 0);

        unordered_map<int, long long> leftNumCnt;
        unordered_map<int, long long> rightNumCnt;

        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            left[i] = leftNumCnt[num - 1] + leftNumCnt[num + 1];
            left[i] %= mod;
            leftNumCnt[num] += left[i] + 1;
            leftNumCnt[num] %= mod;
        }
        
        for (int i = n - 1; i >= 0; --i) {
            int num = nums[i];
            right[i] = rightNumCnt[num - 1] + rightNumCnt[num + 1];
            right[i] %= mod;
            rightNumCnt[num] += right[i] + 1;
            rightNumCnt[num] %= mod;
        }
        
        long long res = 0;
        
        for (int i = 0; i < n; ++i) {
            long long cnt = left[i] + right[i] + left[i] * right[i] + 1;
            cnt %= mod;
            res += cnt * nums[i];
            res %= mod;
        }
        return res;
    }
};

