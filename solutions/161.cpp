class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int m = s.size();
        int n = t.size();
        if (abs(m - n) == 1) {
            // make s > t
            if (m < n) {
                swap(s, t);
                swap(m, n);
            }
            int tIdx = 0;
            for (int i = 0; i < m; i++) {
                if (s[i] == t[tIdx]) tIdx++;
            }
            return tIdx == n;
        }
        else if (m == n) {
            int count = 0;
            for (int i = 0; i < m; i++) {
                if (s[i] != t[i]) count++;
            }
            return count == 1;
        }
        else return false;
    }
};