class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        int difference = INT_MAX;
        int res = -1;
        for (int i = 0; i < n - 2; ++i) {
            int left = i + 1;
            int right = n - 1;
            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];
                int currentDiff = abs(target - currentSum);
                if (currentDiff < difference) {
                    difference = currentDiff;
                    res = currentSum;
                }
                if (currentSum > target) right--;
                else left++;
            }
        }
        return res;
    }
};