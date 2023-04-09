class Solution {
public:
    bool criteria(int maxVal, vector<int>& nums, int p) {
        int cnt = 0;
        int n = nums.size();
        for (int i = 0; i + 1 < n; ++i) {
            if (nums[i + 1] - nums[i] <= maxVal) {
                i++;
                cnt++;
            }
        }
        return cnt >= p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums[n - 1];
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (criteria(mid, nums, p)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};