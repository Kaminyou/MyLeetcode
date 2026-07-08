class Solution {
public:
    long long mod = 1e9 + 7;
    long long inv(long long a) {
        if (a == 1) return 1;
        return (mod - mod / a) * inv(mod % a) % mod;
    }
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        string ss;
        vector<int> availables;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') continue;
            availables.push_back(i);
            ss.push_back(s[i]);
        }
        int m = ss.size();
        long long sum = 0;
        long long factor = 1;
        long long curr = 0;
        vector<long long> sumSuffix(m + 1, 0);
        vector<long long> stringSuffix(m + 1, 0);
        vector<long long> factorPrefix(m + 2, 1);
        for (int i = m - 1; i >= 0; --i) {
            int digit = ss[i] - '0';
            sum += digit;
            curr += digit * factor;
            factor *= 10;
            curr %= mod;
            factor %= mod;
            sum %= mod;
            sumSuffix[i] = sum;
            stringSuffix[i] = curr;
            factorPrefix[m - i] = factor;
        }
        vector<int> res;
        for (auto& q : queries) {
            int start = q[0];
            int end = q[1];
            int startIdx = lower_bound(availables.begin(), availables.end(), start) - availables.begin();
            int endIdx = upper_bound(availables.begin(), availables.end(), end) - availables.begin() - 1;
            if (startIdx == availables.size() || startIdx > endIdx) {
                res.push_back(0);
                continue;
            }
            // [startIdx, endIdx]
            long long sum = sumSuffix[startIdx] - sumSuffix[endIdx + 1];
            long long str = (stringSuffix[startIdx] - stringSuffix[endIdx + 1]) % mod;
            int f = availables.size() - endIdx - 1;
            str *= inv(factorPrefix[f]);
            str %= mod;
            res.push_back((((sum * str) % mod) + mod) % mod);
        }
        return res;
    }
};

