class Solution {
public:
    int findMin(vector<int>& nums) {
        int size = nums.size();
        if (size == 1) return nums[0];
        if (nums[0] < nums[size - 1]) return nums[0];
        
        int left = 0;
        int right = size - 1;
        int mid = 0;
        while (left < right){
            mid = left + (right - left) / 2;
            
            if (nums[mid] < nums[right]) right = mid;
            else if (nums[mid] > nums[right]) left = mid + 1; 
            else right = right - 1;
        }
        return nums[left];
    }
};
