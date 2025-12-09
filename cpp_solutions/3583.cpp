class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        long long res = 0;
        long long mod = 1e9 + 7;
        unordered_map<int, long long> leftCnt;
        unordered_map<int, long long> rightCnt;
        for (auto& num : nums) rightCnt[num]++;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            rightCnt[nums[i]]--;
            long long left = leftCnt[nums[i] * 2];
            long long right = rightCnt[nums[i] * 2];
            res += (left * right) % mod;
            res %= mod;
            leftCnt[nums[i]]++;
        }
        return res;
    }
};
