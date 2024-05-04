class Solution {
public:
    vector<vector<int>> res;
    void backtracking(int k, vector<int>& path, int currStart, int currSum, int n) {
        if (currSum == n && path.size() == k) {
            res.push_back(path);
            return;
        }
        if (path.size() > k) return;
        if (currSum > n) return;
        else {
            for (int i = currStart; i <= 9; i++) {
                path.push_back(i);
                backtracking(k, path, i + 1, currSum + i, n);
                path.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> path;
        backtracking(k, path, 1, 0, n);
        return res;
    }
};