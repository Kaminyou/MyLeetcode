class Solution {
public:
    vector<string> res;
    void backtracking(int n, int curr, string& path, int open, int close) {
        if (curr == n * 2) {
            res.push_back(path);
            return;
        }
        if (open < n) {
            path.push_back('(');
            backtracking(n, curr + 1, path, open + 1, close);
            path.pop_back();
        }
        if (close < open) {
            path.push_back(')');
            backtracking(n, curr + 1, path, open, close + 1);
            path.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string path = "";
        backtracking(n, 0, path, 0, 0);
        return res;
    }
};