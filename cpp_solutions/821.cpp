class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int> res(n, INT_MAX / 2);
        for (int i = 0; i < n; ++i) {
            if (s[i] == c) res[i] = 0;
            else {
                if (i == 0) continue;
                else res[i] = res[i - 1] + 1;
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == c) res[i] = 0;
            else {
                if (i == n - 1) continue;
                else res[i] = min(res[i], res[i + 1] + 1);
            }
        }
        return res;
    }
};