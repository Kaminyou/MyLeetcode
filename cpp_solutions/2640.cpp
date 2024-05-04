class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long> conver(n, 0);
        conver[0] = nums[0] * 2;
        long long maxVal = nums[0];
        for (int i = 1; i < n; ++i) {
            maxVal = max(maxVal, (long long)nums[i]);
            conver[i] = nums[i] + maxVal;
        }
        for (int i = 1; i < n; ++i) {
            conver[i] = conver[i - 1] + conver[i];
        }
        return conver;
    }
};