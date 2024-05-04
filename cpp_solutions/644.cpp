class Solution {
public:
    // mid is too large?
    bool criteria(vector<int>& nums, double mid, int k) {
        double sum = 0;
        double preSum = 0;
        double minSum = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            double diff = nums[i] - mid;
            sum += diff;
            if (i >= k) {
                preSum += nums[i - k] - mid;
                minSum = min(minSum, preSum);
            }
            if (i >= k - 1) {
                double maxAvg = sum - minSum;
                if (maxAvg > 0) return false;
            }
        }
        return true;
    }
    double findMaxAverage(vector<int>& nums, int k) {
        double maxVal = INT_MIN;
        double minVal = INT_MAX;
        for (auto& num : nums) {
            maxVal = max(maxVal, (double)num);
            minVal = min(minVal, (double)num);
        }
        
        double left = minVal;
        double right = maxVal;
        while (right - left > 0.00001) {
            double mid = left + (right - left) / 2;
            if (criteria(nums, mid, k)) right = mid;
            else left = mid;
        }
        return left;
    }
};