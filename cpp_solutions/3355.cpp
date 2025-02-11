class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> difference(n + 1, 0);
        for (auto& query : queries) {
            difference[query[0]]++;
            difference[query[1] + 1]--;
        }
        int current = 0;
        for (int i = 0; i < n; ++i) {
            current += difference[i];
            if (current < nums[i]) return false;
        }
        return true;
    }
};
