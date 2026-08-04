class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> leftMax(n + 2, 0);
        vector<int> rightMax(n + 2, 0);
        for (int i = 1; i <= n; ++i) {
            leftMax[i] = max(leftMax[i - 1], nums[i - 1]);
        }
        for (int i = n; i >= 1; --i) {
            rightMax[i] = max(rightMax[i + 1], nums[i - 1]);
        }
        int res = 0;
        for (int i = 1; i + k <= n; ++i) {
            res = max(res, leftMax[i] + rightMax[i + k]);
        }
        return res;
        
    }
};
