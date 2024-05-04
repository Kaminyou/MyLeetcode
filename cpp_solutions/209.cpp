class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int right = 0;
        int currentSum = 0;
        int n = nums.size();
        int res = INT_MAX;
        while (left < n) {
            while (currentSum < target && right < n) {
                currentSum += nums[right];
                right++;
            }
            if (currentSum >= target) res = min(res, right - left);
            currentSum -= nums[left];
            left++;
        }
        if (res == INT_MAX) return 0;
        return res;
    }
};