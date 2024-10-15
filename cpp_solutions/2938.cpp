class Solution {
public:
    long long minimumSteps(string s) {
        long long res = 0;
        int cnt = 0;
        int n = s.size();
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '0') cnt++;
            else res += cnt;
        }
        return res;
    }
};

