class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long res = 0;
        int left = 0;
        int maxValue = *max_element(nums.begin(), nums.end());
        int cnt = 0;
        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] == maxValue) cnt++;
            while (cnt >= k) {
                if (nums[left] == maxValue) cnt--;
                left++;
            }
            // [0, ..., (left - 1)] -> right are valid interval
            res += left;
        }
        return res;
    }
};
