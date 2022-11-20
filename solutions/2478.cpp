class Solution {
public:
    bool isPrime(char c) {
        if (c == '2') return true;
        if (c == '3') return true;
        if (c == '5') return true;
        if (c == '7') return true;
        return false;
    }
    bool isNotPrime(char c) {
        return !isPrime(c);
    }
    long long backtracking(int index, int k, int minLength, string& s, vector<vector<long long>>& memo) {
        if (index == s.size() && k == 0) return memo[index][k] = 1;
        if (index == s.size() || k == 0) return memo[index][k] = 0;
        if (isNotPrime(s[index])) return memo[index][k] = 0;
        if (memo[index][k] != -1) return memo[index][k];
        long long ans = 0;
        long long mod = 1e9 + 7;
        for (int i = index; i < s.size(); ++i) {
            if (i - index + 1 >= minLength && isNotPrime(s[i])) {
                if (s.size() - i - 1 >= minLength * (k - 1)) {
                    ans += backtracking(i + 1, k - 1, minLength, s, memo);
                    ans %= mod;
                }
                else break;
            }
        }
        return memo[index][k] = ans;
    }
    int beautifulPartitions(string s, int k, int minLength) {

        if (isNotPrime(s[0])) return 0;
        int n = s.size();
        if (isPrime(s[n - 1])) return 0;
        if (n < minLength) return 0;
        vector<vector<long long>> memo(n + 1, vector<long long>(k + 1, -1));
        return backtracking(0, k, minLength, s, memo);
    }
};