class Solution {
public:
    vector<int> getSuffix(vector<int>& group) {
        int n = group.size();
        vector<int> suffix(n, 0);
        for (int i = 1; i < n; ++i) {
            int j = suffix[i - 1];
            while (j >= 1 && group[i] != group[j]) {
                j = suffix[j - 1];
            }
            suffix[i] = j + (group[i] == group[j]);
        }
        return suffix;
    }
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int groupIdx = 0;
        int numsIdx = 0;
        
        int n = nums.size();
        vector<int> dp(n, 0);
        while (groupIdx < groups.size()) {
            bool flag = false;
            vector<int> suffix = getSuffix(groups[groupIdx]);
            // from nums[numsIdx] to match suffix
            int start = numsIdx;
            dp[numsIdx] = (groups[groupIdx][0] == nums[numsIdx]);
            if (dp[numsIdx] == groups[groupIdx].size()) {
                groupIdx++;
                numsIdx++;
                flag = true;
            }
            if (!flag) {
                numsIdx++;
                for (; numsIdx < n; ++numsIdx) {
                    int j = dp[numsIdx - 1];
                    while (j > 0 && groups[groupIdx][j] != nums[numsIdx]) {
                        j = suffix[j - 1];
                    }
                    dp[numsIdx] = j + (groups[groupIdx][j] == nums[numsIdx]);
                    if (dp[numsIdx] == groups[groupIdx].size()) {
                        groupIdx++;
                        numsIdx++;
                        flag = true;
                        break;
                    }
                }
            }
            if (!flag) return false;
            if (numsIdx == n && groupIdx != groups.size()) return false;
        }
        return true;
    }
};