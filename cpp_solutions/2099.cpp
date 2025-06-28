class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> numIndex;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            numIndex.push_back({nums[i], i});
        }
        sort(numIndex.begin(), numIndex.end(), greater<pair<int, int>>());
        vector<int> indexMapping(n, -1);
        for (int i = 0; i < n; ++i) {
            indexMapping[numIndex[i].second] = i;
        }
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (indexMapping[i] < k) {
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};
