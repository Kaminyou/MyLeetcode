class Solution {
public:
    vector<vector<int>> res;
    void backtracking(vector<int>& candidates, int start, int remain, vector<int>& path) {
        if (remain == 0) {
            res.push_back(path);
            return;
        }
        int n = candidates.size();
        for (int i = start; i < n; i++) {
            if (remain < candidates[i]) continue;
            path.push_back(candidates[i]);
            backtracking(candidates, i, remain - candidates[i], path);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        backtracking(candidates, 0, target, path);
        return res;
    }
};