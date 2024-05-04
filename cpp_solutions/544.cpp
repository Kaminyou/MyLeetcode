class Solution {
public:
    void helper(int n, vector<string>& v) {
        if (n == 1) return;
        for (int i = 0; i < n / 2; ++i) {
            v[i] = "(" + v[i] + ","+ v[n - i - 1] + ")";
        }
        helper(n / 2, v);
    }
    string findContestMatch(int n) {
        vector<string> v;
        for (int i = 1; i <= n; ++i) v.push_back(to_string(i));
        helper(n, v);
        return v[0];
    }
};