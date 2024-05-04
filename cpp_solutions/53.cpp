class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxVal = INT_MIN;
        int currSum = 0;
        for (auto num : nums) {
            currSum += num;
            maxVal = max(maxVal, currSum);
            if (currSum < 0) {
                currSum = 0;
            }
        }
        return maxVal;
    }
};