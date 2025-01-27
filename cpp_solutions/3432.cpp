class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        int res = 0;
        for (int i = 0; i < n - 1; ++i) {
            int diff = (prefix[n] - prefix[i + 1]) - (prefix[i + 1] - prefix[0]);
            if (diff & 1) continue;
            res++;
        }
        return res;
    }
};
