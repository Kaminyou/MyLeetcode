class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        int left = 0;
        int res = 0;
        for (int right = 0; right < nums.size(); ++right) {
            counts[nums[right]] += 1;
            while (right >= left && counts[nums[right]] > k) {
                counts[nums[left]] -= 1;
                left++;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};
