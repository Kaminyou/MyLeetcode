class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int left = 1;
        int right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (valid(nums, mid, k)) right = mid;
            else left = mid + 1;
        }
        if (!valid(nums, left, k)) return -1;
        return left;
    }
    bool valid(vector<int>& nums, int target, int k) {
        int n = nums.size();
        vector<int> counts(32, 0);
        for (int i = 0; i < target - 1; ++i) {
            for (int j = 0; j < 32; ++j) {
                if (nums[i] & (1 << j)) counts[j]++;
            }
        }
        for (int i = target - 1; i < n; ++i) {
            for (int j = 0; j < 32; ++j) {
                if (nums[i] & (1 << j)) counts[j]++;
            }
            int curr = 0;
            for (int j = 0; j < 32; ++j) {
                if (counts[j] > 0) curr += (1 << j);
            }
            if (curr >= k) return true;
            for (int j = 0; j < 32; ++j) {
                if (nums[i - target + 1] & (1 << j)) counts[j]--;
            }
        }
        return false;
    }
};
