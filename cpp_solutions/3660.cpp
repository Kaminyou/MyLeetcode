class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> preMax(n, 0);
        vector<int> sufMin(n, 0);
        vector<int> res(n, 0);
        for (int i = 0; i < n; ++i) {
            preMax[i] = max(i == 0 ? 0 : preMax[i - 1], nums[i]);
        }
        for (int i = n - 1; i >= 0; --i) {
            sufMin[i] = min(i == n - 1 ? INT_MAX : sufMin[i + 1], nums[i]);
        }
        res[n - 1] = preMax[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            if (preMax[i] > sufMin[i + 1]) {
                res[i] = res[i + 1];
            }
            else {
                res[i] = preMax[i];
            }
        }
        return res;
    }
};
