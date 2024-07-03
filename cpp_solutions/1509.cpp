class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if (n <= 3) return 0;
        sort(nums.begin(), nums.end());
        int minVal = INT_MAX;
        for (int i = 0; i <= 3; ++i) {
            minVal = min(minVal, abs(nums[i] - nums[i + (n - 4)]));
        }
        return minVal;
    }
};

