class Solution {
public:
    int binaryStartSearch(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) right = mid;
            else left = mid + 1;
        }
        return left;
    }
    int binaryEndSearch(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) right = mid;
            else left = mid + 1;
        }
        return left;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = binaryStartSearch(nums, target);
        if (left == nums.size() || nums[left] != target) return {-1, -1};
        int right = binaryEndSearch(nums, target) - 1;
        return {left, right};
    }
};