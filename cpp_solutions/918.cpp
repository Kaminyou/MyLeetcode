class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int currentMaxSum = 0;
        int currentMax = INT_MIN;
        int currentMinSum = 0;
        int currentMin = INT_MAX;
        int total = 0;
        for (auto& num : nums) {
            total += num;
            currentMaxSum = max(currentMaxSum + num, num);
            currentMax = max(currentMax, currentMaxSum);
            currentMinSum = min(currentMinSum + num, num);
            currentMin = min(currentMin, currentMinSum);
        }
        if (currentMax > 0) return max(currentMax, total - currentMin);
        return currentMax;
    }
};