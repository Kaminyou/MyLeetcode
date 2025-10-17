class Solution {
public:
    unordered_map<long long, int> memo;
    int dp(string& s, int k, int index, long long hash, bool canChange) {
        if (s.size() == index) return 0;
        long long key = (((long long)index) << 27) + (hash << 1) + canChange;
        if (memo.count(key)) return memo[key];
        
        int currChar = s[index] - 'a';
        long long currHash = hash | (1 << currChar);
        int currCnt = __builtin_popcount(currHash);
        int res = 0;
        if (currCnt > k) {
            res = max(res, 1 + dp(s, k, index + 1, (1 << currChar), canChange));
        }
        else {
            res = max(res, dp(s, k, index + 1, currHash, canChange));
        }
        if (canChange) {
            for (int i = 0; i < 26; ++i) {
                long long newHash = hash | (1 << i);
                int newCnt = __builtin_popcount(newHash);
                if (newCnt > k) {
                    res = max(res, 1 + dp(s, k, index + 1, (1 << i), false));
                }
                else {
                    res = max(res, dp(s, k, index + 1, newHash, false));
                }
            }
        }
        return memo[key] = res;
    }
    int maxPartitionsAfterOperations(string s, int k) {
        return 1 + dp(s, k, 0, 0, true);
    }
};
