class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size() - 1;
        int res = -1;
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum < k) {
                res = max(res, sum);
                left++;
            }
            else if (sum >= k) {
                right--;
            }
        }
        return res;
    }
};