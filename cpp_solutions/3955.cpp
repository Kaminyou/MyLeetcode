class Solution {
public:
    void backtracking(int index, string& s, vector<string>& res, int n, int k) {
        if (index == n) {
            if (k >= 0) res.push_back(s);
            return;
        }
        s.push_back('0');
        backtracking(index + 1, s, res, n, k);
        s.pop_back();
        if (k >= index) {
            if (index >= 1 && s[index - 1] == '1') return;
            s.push_back('1');
            backtracking(index + 1, s, res, n, k - index);
            s.pop_back();
        }
    }
    vector<string> generateValidStrings(int n, int k) {
        vector<string> res;
        string curr = "";
        backtracking(0, curr, res, n, k);
        return res;
    }
};
