class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minVal = INT_MAX;
        int minIdx = -1;
        int maxVal = INT_MIN;
        int maxIdx = -1;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] < minVal) {
                minVal = nums[i];
                minIdx = i;
            }
            if (nums[i] > maxVal) {
                maxVal = nums[i];
                maxIdx = i;
            }
        }
        if (minIdx > maxIdx) swap(minIdx, maxIdx);
        return min({maxIdx + 1, n - minIdx, minIdx + 1 + n - maxIdx});
    }
};
