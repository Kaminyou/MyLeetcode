class Solution {
public:
    int counting(const vector<int>& nums, int criteria) {
        int sum = 0;
        int left = 0;
        int res = 0;
        for (int right = 0; right < nums.size(); ++right) {
            sum += nums[right];
            while (sum > criteria) {
                sum -= nums[left];
                left++;
            }
            res += right - left + 1;
        }
        return res;
    }
    int kthSmallestSubarraySum(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        for (auto num : nums) right += num;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int count = counting(nums, mid);
            if (count >= k) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};