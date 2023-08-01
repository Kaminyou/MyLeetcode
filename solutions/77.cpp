class Solution {
public:
    vector<vector<int>> res;
    void backtracking(int start, int n, int k, vector<int>& v) {
        if (v.size() == k) {
            res.push_back(v);
        }
        else {
            for (int i = start; i <= n; ++i) {
                v.push_back(i);
                backtracking(i + 1, n, k, v);
                v.pop_back();
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> v;
        backtracking(1, n, k, v);
        return res;
    }
};