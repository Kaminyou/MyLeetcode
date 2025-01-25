class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int from = max(0, i - nums[i]);
            int current = prefix[i + 1] - prefix[from];
            res += current;
        }
        return res;
    }
};
