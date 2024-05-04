class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();
        int maxSize = 0;
        for (int i = 0; i < n; ++i) {
            mp[nums[i]].push_back(i);
            int m = mp[nums[i]].size();
            maxSize = max(maxSize, m);
        }
        int res = INT_MAX;
        for (auto& element : mp) {
            if (element.second.size() == maxSize) {
                res = min(res, element.second[maxSize - 1] - element.second[0] + 1);
            }
        }
        return res;
    }
};