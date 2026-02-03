class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        bool top = false;
        bool bottom = false;
        int n = nums.size();
        for (int i = 1; i < n - 1; ++i) {
            if (nums[i - 1] == nums[i] || nums[i] == nums[i + 1]) return false;
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
                if (top) return false;
                top= true;
            }
            if (nums[i] < nums[i - 1] && nums[i] < nums[i + 1]) {
                if (!top) return false;
                if (bottom) return false;
                bottom = true;
            }
        }
        return top && bottom;
    }
};
