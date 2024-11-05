class Solution {
public:
    int minChanges(string s) {
        int n = s.size();
        int half = n / 2;
        int res = 0;
        for (int i = 0; i < half; ++i) {
            char l = s[2 * i];
            char r = s[2 * i + 1];
            if (l != r) res++;
        }
        return res;
    }
};
