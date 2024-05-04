class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        // maximum lenght of subarray equal to sum - x
        int sum = 0;
        for (auto& num : nums) sum += num;
        int target = sum - x;
        if (target < 0) return -1;
        
        int n = nums.size();
        int left = 0;
        int curr = 0;
        int res = -1;
        for (int right = 0; right < n; ++right) {
            curr += nums[right];
            while (curr > target) {
                curr -= nums[left];
                left++;
            }
            if (curr == target) {
                res = max(res, right - left + 1);
            }
        }
        if (res == -1) return -1;
        return n - res;
    }
};