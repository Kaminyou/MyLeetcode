class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int left = 0;
        int index = 0;
        int consecutive = 1;
        int n = nums.size();
        vector<int> res(n - k + 1, -1);
        for (int right = 0; right < n; ++right) {
            if (right > 0 && nums[right] - 1 == nums[right - 1]) consecutive++;
            if (right - left + 1 > k) {
                if (nums[left] + 1 == nums[left + 1]) consecutive--;
                left++;
            }
            if (right - left + 1 == k) {
                if (consecutive == k) res[index] = nums[right];
                else res[index] = -1;
                index++;
            }
        }
        return res;
    }
};
