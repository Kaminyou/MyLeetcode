typedef pair<long long, pair<long long, long long>> P;
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<P, vector<P>, greater<P>> pq;
        for (auto& prime : primes) {
            pq.push(make_pair(prime, make_pair(prime, 1)));
        }
        
        vector<long long> dp(n, 0);
        dp[0] = 1;
        int i = 1;
        while (i < n) {
            auto [num, e] = pq.top();
            auto [src, index] = e;
            pq.pop();
            if (dp[i - 1] != num) {
                dp[i] = num;
                i++;
            }
            pq.push(make_pair(src * dp[index], make_pair(src, index + 1)));
        }
        return dp[n - 1];
    }
};