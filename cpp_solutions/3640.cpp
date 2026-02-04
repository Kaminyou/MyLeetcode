class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> ps;
        int index = 0;
        while (index < n) {
            int left = index;
            while (index + 1 < n && nums[index] > nums[index + 1]) index++;
            if (index > left) {
                ps.push_back({left, index});
            }
            index++;
        }

        long long res = LLONG_MIN;

        for (auto [l, r] : ps) {
            long long midSum = accumulate(nums.begin() + l, nums.begin() + r + 1, 0ll);
            if (l - 1 < 0) continue;
            if (r + 1 >= n) continue;
            if (nums[l] == nums[l - 1]) continue;
            if (nums[r] == nums[r + 1]) continue;
            long long leftSum = nums[l - 1];
            long long maxLeftSum = leftSum;
            l--;
            while (l - 1 >= 0 && nums[l] > nums[l - 1]) {
                l--;
                leftSum += nums[l];
                maxLeftSum = max(maxLeftSum, leftSum);
            }

            long long rightSum = nums[r + 1];
            long long maxRightSum = rightSum;
            r++;
            while (r + 1 < n && nums[r + 1] > nums[r]) {
                r++;
                rightSum += nums[r];
                maxRightSum = max(maxRightSum, rightSum);
            }
            res = max(res, maxLeftSum + maxRightSum + midSum);
        }
        return res;
    }
};
