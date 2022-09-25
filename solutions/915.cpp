class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxArr(n, 0);
        vector<int> minArr(n, 0);
        maxArr[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            maxArr[i] = max(maxArr[i - 1], nums[i]);
        }
        minArr[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            minArr[i] = min(minArr[i + 1], nums[i]);
        }
        for (int i = 0; i < n - 1; ++i) {
            if (maxArr[i] <= minArr[i + 1]) return i + 1;
        }
        return -1;
    }
};