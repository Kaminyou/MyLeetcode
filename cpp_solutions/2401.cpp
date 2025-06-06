class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int res = 1;
        int right = 0;
        int now = 0;
        int n = nums.size();
        for (int left = 0; left < n; ++left) {
            while (right < n && ((nums[right] & now) == 0)) {
                now |= nums[right];
                right++;
            }
            res = max(res, right - left);
            now ^= nums[left];
        }
        return res;
    }
};
