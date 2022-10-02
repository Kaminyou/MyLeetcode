class Solution {
public:
    int deleteString(string s) {
        int start = 0;
        int n = s.size();
        vector<int> suffix(n, 0);
        
        int cnt = 0;
        while (start < s.size()) {
            // in s[start:n - 1]
            bool flag = false;
            suffix[start] = 0;
            for (int i = start + 1; i < n; ++i) {
                if (flag) break;
                int j = suffix[i - 1];
                while (j >= 1 && s[i] != s[j + start]) {
                    j = suffix[j - 1];
                }
                suffix[i] = j + (s[i] == s[j + start]);
            }

            for (int k = n - 1; k >= start; --k) {
                if (suffix[k] * 2 == (k - start + 1)) {
                    start += suffix[k];
                    cnt++;
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                cnt++;
                break;
            }
        }
        return cnt;
    }
};