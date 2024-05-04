class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int minValue = INT_MIN;
        int n = nums.size();
        for (int i = 0; i < n / 2; ++i) {
            int sum = nums[i] + nums[n - i - 1];
            minValue = max(minValue, sum);
        }
        return minValue;
    }
};
