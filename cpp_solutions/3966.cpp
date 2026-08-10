class Solution {
public:
    long long dp(string& s, int index, int prevDigit, int isTight, int isLZ, int k, long long memo[][11][2][2]) {
        if (s.size() == index) return !isLZ;
        if (memo[index][prevDigit][isTight][isLZ] != -1) return memo[index][prevDigit][isTight][isLZ];
        int up = s[index] - '0';
        if (!isTight) up = 9;
        long long cnt = 0;
        for (int digit = 0; digit <= up; ++digit) {
            int newIsTight = isTight && (digit == up);
            int newIsLZ = isLZ && (digit == 0);
            if (newIsLZ) {
                cnt += dp(s, index + 1, 10, newIsTight, newIsLZ, k, memo);
            } else if (isLZ || abs(prevDigit - digit) <= k) {
                cnt += dp(s, index + 1, digit, newIsTight, newIsLZ, k, memo);
            }
        }
        return memo[index][prevDigit][isTight][isLZ] = cnt;
    }
    long long goodIntegers(long long l, long long r, int k) {
        long long memo[18][11][2][2]; // idx, prev dig, tight, leading zero
        string rr = to_string(r);
        string ll = to_string(l - 1);
        memset(memo, -1, sizeof(memo));
        long long rrr = dp(rr, 0, 10, 1, 1, k, memo);
        memset(memo, -1, sizeof(memo));
        long long lll = dp(ll, 0, 10, 1, 1, k, memo);
        return rrr - lll;
    }
};
