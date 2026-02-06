class Solution {
public:
    bool valid(int l, int r, int k) {
        return (long long)l * k >= r;
    }
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = INT_MAX;
        int left = 0;
        for (int right = 0; right < n; ++right) {
            while (left <= right && !valid(nums[left], nums[right], k)) left++;
            // [left, right] is valid
            res = min(res, n - (right - left + 1));
        }
        return res;
    }
};
