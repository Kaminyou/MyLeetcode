class Solution {
public:
    string clearDigits(string s) {
        int cnt = 0;
        int n = s.size();
        vector<bool> used(n, true);
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] >= '0' && s[i] <= '9') {
                cnt++;
                used[i] = false;
            }
            else {
                if (cnt) {
                    cnt--;
                    used[i] = false;
                }
            }
        }
        string res;
        for (int i = 0; i < n; ++i) {
            if (used[i]) res.push_back(s[i]);
        }
        return res;
    }
};
