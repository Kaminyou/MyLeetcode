class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        // [0, 10 ^ n)
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        if (n == 0) return dp[0];
        dp[1] = 9;
        if (n == 1) return dp[0] + dp[1];
        int multiply = 9;
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] * multiply;
            multiply--;
        }
        int total = 0;
        for (int i = 0; i <= n; ++i) total += dp[i];
        return total;
    }
    int multiply(int start, int length) {
        int res = 1;
        for (int i = 0; i < length; ++i) {
            res *= start;
            start--;
        }
        return res;
    }
    bool isUnique(int n) {
        string nStr = to_string(n);
        vector<bool> used(10, false);
        for (auto c : nStr) {
            if (used[c - '0']) return false;
            used[c - '0'] = true;
        }
        return true;
    }
    int countSpecialNumbers(int n) {
        string nStr = to_string(n);
        int length = nStr.size();
        
        // [0, 10^m)
        int uniques = countNumbersWithUniqueDigits(length - 1);
        uniques--; // delete 0
        
        // [10^m + 1, n)
        vector<bool> used(10, false);
        uniques += (nStr[0] - '0' - 1) * multiply(9, length - 1);
        
        used[nStr[0] - '0'] = true;
        for (int i = 1; i < length; ++i) {
            int usedCnt = 0;
            for (int j = 0; j < (nStr[i] - '0'); ++j) {
                if (used[j]) usedCnt++;
            }
            uniques += (nStr[i] - '0' - usedCnt) * multiply(9 - i, length - 1 - i);
            if (used[nStr[i] - '0']) break;
            used[nStr[i] - '0'] = true;
        }
        // n
        if (isUnique(n)) uniques++;
        return uniques;
        
    }
};