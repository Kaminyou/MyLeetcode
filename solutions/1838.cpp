class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int left = 0;
        long long used = 0;
        int res = 0;
        for (int right = 0; right < n; ++right) {
            int prev = nums[right];
            if (right >= 1) prev = nums[right - 1];
            used += (long long)(right - left) * (nums[right] - prev);
            while (used > (long long)k) {
                used -= (long long)nums[right] - nums[left];
                left++;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};