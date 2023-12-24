class Solution {
public:
    int cnt(string& s, int state) {
        int n = s.size();
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] - '0' != state) res++;
            state ^= 1; 
        }
        return res;
    }
    int minOperations(string s) {
        return min(cnt(s, 0), cnt(s, 1));
    }
};
