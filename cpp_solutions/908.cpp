class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int maxElement = INT_MIN;
        int minElement = INT_MAX;
        for (auto& num : nums) {
            maxElement = max(maxElement, num);
            minElement = min(minElement, num);
        }
        return max(0, maxElement - minElement - 2 * k);
    }
};