class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int maxValue = *max_element(nums.begin(), nums.end());
        return maxValue * k + (k) * (k - 1) / 2;
    }
};
