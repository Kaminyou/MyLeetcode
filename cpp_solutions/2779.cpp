class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int right = 0;
        int n = nums.size();
        int res = 0;
        for (int left = 0; left < n; ++left) {
            while (right + 1 < n && nums[right + 1] <= nums[left] + k * 2) right++;
            res = max(res, right - left + 1);
        }
        return res;
    }
};
