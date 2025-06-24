class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int curr = -1;
        vector<int> res;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] == key) {
                for (int j = max(i - k, curr + 1); j <= min(i + k, n - 1); ++j) {
                    res.push_back(j);
                    curr = j;
                }
            }
        }
        return res;
    }
};
