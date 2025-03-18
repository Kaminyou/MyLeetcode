class Solution {
    public int longestNiceSubarray(int[] nums) {
        int res = 1;
        int right = 0;
        int now = 0;
        int n = nums.length;
        for (int left = 0; left < n; left += 1) {
            while (right < n && ((nums[right] & now) == 0)) {
                now |= nums[right];
                right++;
            }
            res = Integer.max(res, right - left);
            now ^= nums[left];
        }
        return res;
    }
}
