class Solution {
public:
    int numSub(string s) {
        long long res = 0;
        long long mod = 1e9 + 7;
        int now = 0;
        for (auto& c : s) {
            if (c == '1') now++;
            else now = 0;
            res += now;
            res %= mod;
        }
        return res;
    }
};

