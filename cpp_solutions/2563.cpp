class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long res = 0;
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            long long small = (long long)lower - (long long)nums[i];
            long long big = (long long)upper - (long long)nums[i];
            // find >= small
            auto smallIt = lower_bound(nums.begin(), nums.begin() + i, small);
            int smallIdx = smallIt - nums.begin();
            // find <= big
            auto bigIt = upper_bound(nums.begin(), nums.begin() + i, big);
            bigIt--;
            int bigIdx = bigIt - nums.begin();
            
            res += (bigIdx - smallIdx) + 1;
        }
        return res;
    }
};

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long res = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int rightUpper = n - 1;
        int rightLower = n;
        for (int left = 0; left < n; ++left) {
            while (rightLower > 0 && nums[left] + nums[rightLower - 1] >= lower) {
                rightLower--;
            }
            while (rightUpper > 0 && nums[left] + nums[rightUpper] > upper) {
                rightUpper--;
            }
            int usedRightLower = max(left + 1, rightLower);
            if (usedRightLower == n) continue;
            if (nums[left] + nums[usedRightLower] < lower) continue;
            if (nums[left] + nums[rightUpper] > upper) continue;
            if (usedRightLower > rightUpper) continue;
            res += (rightUpper - usedRightLower + 1);
        }
        return res;
    }
};

