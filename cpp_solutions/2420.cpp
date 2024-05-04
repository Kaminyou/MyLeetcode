class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> decreasing(n, 1);
        vector<int> increasing(n, 1);
        
        for (int i = 1; i < n; ++i) {
            if (nums[i] <= nums[i - 1]) decreasing[i] = decreasing[i - 1] + 1;
            else decreasing[i] = 1;
        }
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] <= nums[i + 1]) increasing[i] = increasing[i + 1] + 1;
            else increasing[i] = 1;
        }

        vector<int> res;
        for (int i = k; i < n - k; ++i) {
            if (decreasing[i - 1] >= k && increasing[i + 1] >= k) res.push_back(i);
        }
        return res;
    }
};