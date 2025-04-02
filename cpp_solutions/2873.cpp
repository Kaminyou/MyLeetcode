class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long res = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    long long cur = ((long long)nums[i] - nums[j]) * (long long)nums[k];
                    res = max(res, cur);
                }
            }
        }
        return res;
    }
};
