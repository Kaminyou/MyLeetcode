class Solution {
public:
    vector<vector<int>> res;
    void backtracking(int n, int curr, int sum, int target, vector<int>& path, vector<int>& candidates) {
        if (target == sum) {
            res.push_back(path);
            return;
        }
        for (int i = curr; i < n; ++i) {
            if (sum + candidates[i] > target) break;
            path.push_back(candidates[i]);
            backtracking(n, i + 1, sum + candidates[i], target, path, candidates);
            // skip duplicates
            while (i + 1 < n && candidates[i] == candidates[i + 1]) i++;
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> path;
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        backtracking(n, 0, 0, target, path, candidates);
        return res;
    }
};