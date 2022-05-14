class Solution {
public:
    vector<vector<int>> res;
    void backtracking(int n, int start, vector<int>& path) {
        int upperbound = sqrt(n);
        for (int i = start; i <= upperbound; ++i) {
            if (n % i != 0) continue;
            path.push_back(i);
            backtracking(n / i, i, path);
            
            path.push_back(n / i);
            
            res.push_back(path);
            
            path.pop_back();
            path.pop_back();
        }
    }
    vector<vector<int>> getFactors(int n) {
        vector<int> path;
        backtracking(n, 2, path);
        return res;
    }
};