class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long maxVal = INT_MIN;
        long long minVal = INT_MAX;
        for (auto& num : nums) {
            maxVal = max(maxVal, (long long)num);
            minVal = min(minVal, (long long)num);
        }
        return (maxVal - minVal) * (long long)k;
    }
};
