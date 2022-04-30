class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int n = nums.size();
        
        long long sum = 0;
        for (int i = 0; i < n; i++) sum += nums[i];
        
        long long left = 0;
        long long right;
        long long minDiff = LLONG_MAX;
        int minIndex = 0;
        for (int i = 0; i < n; i++) {
            left += nums[i];
            right = sum - left;
            int leftDiff = left / (i + 1);
            
            int rightDiff;
            if (i < n - 1) rightDiff = right / (n - i - 1);
            else rightDiff = 0;
            if (abs(leftDiff - rightDiff) < minDiff) {
                minDiff = abs(leftDiff - rightDiff);
                minIndex = i;
            }
        }
        return minIndex;
    }
};