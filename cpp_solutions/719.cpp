class Solution {
public:
    bool criteria(vector<int>& nums, int distance, int k) {
        int right = 0;
        int n = nums.size();
        int cnt = 0;
        for (int left = 0; left < n; ++left) {
            while (right + 1 < n && nums[right + 1] - nums[left] <= distance) right++;
            cnt += (right - left);
        }
        return cnt >= k;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = 1000000;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (criteria(nums, mid, k)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};
