class Solution {
public:
    int sumCounts(vector<int>& nums) {
        bool exist[101];
        int n = nums.size();
        int res = 0;
        for (int left = 0; left < n; ++left) {
            for (int right = left; right < n; ++right) {
                for (int i = 0; i <= 100; ++i) exist[i] = false;
                int cnt = 0;
                for (int i = left; i <= right; ++i) {
                    if (!(exist[nums[i]])) {
                        exist[nums[i]] = true;
                        cnt++;
                    }
                }
                res += cnt * cnt;
            }
        }
        return res;
    }
};
