class Solution {
public:
    long long maximumBooks(vector<int>& books) {
        int n = books.size();
        vector<long long> dp(n, 0);
        stack<int> stk;
        
        long long res = 0;
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && books[stk.top()] > books[i] - (i - stk.top())) stk.pop();
            if (!stk.empty()) {
                long long j = stk.top();
                long long L = i - j;
                dp[i] = dp[j] + ((long long)books[i] + (books[i] - L + 1)) * L / 2;
            }
            else {
                long long L = min(i + 1, books[i]);
                dp[i] = ((long long)books[i] + (books[i] - L + 1)) * L / 2;
            }
            stk.push(i);
            res = max(res, dp[i]);
        }
        return res;
    }
};