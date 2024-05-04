class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int anchor = -1;
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                anchor = i;
                break;
            }
        }
        if (anchor == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int j = anchor + 1;
        while (j < n && nums[j] > nums[anchor]) j++;
        j--;
        swap(nums[anchor], nums[j]);
        reverse(nums.begin() + anchor + 1, nums.end());
    }
};