class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        
        while (left < right){
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > nums[left]){
                if (target >= nums[left] && target < nums[mid]) right = mid;
                else left = mid + 1;
            } else {
                if (target <= nums[right - 1] && target > nums[mid]) left = mid + 1;
                else right = mid;
            }
        }
        return -1;
    }
};