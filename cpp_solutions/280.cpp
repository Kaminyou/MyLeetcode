class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        bool less = true;
        int n = nums.size();
        for (int i = 0; i < n - 1; ++i) {
            if (less) {
                if (nums[i + 1] < nums[i]) {
                    swap(nums[i], nums[i + 1]);
                }
            }
            else {
                if (nums[i + 1] > nums[i]) {
                    swap(nums[i], nums[i + 1]);
                }
            }
            less ^= 1;
        }
    }
};