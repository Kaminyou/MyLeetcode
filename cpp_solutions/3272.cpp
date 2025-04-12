class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        vector<long long> fac(n + 1, 1);
        for (int i = 1; i <= n; ++i) fac[i] = fac[i - 1] * i;
        long long res = 0;
        int base = pow(10, (n - 1) / 2);
        unordered_set<string> st;
        for (int i = base; i < base * 10; ++i) {
            string s = to_string(i);
            string rs = s;
            reverse(rs.begin(), rs.end());
            s += rs.substr(n % 2);
            if (stoll(s) % k) continue;
            string t = s;
            sort(t.begin(), t.end());
            if (st.count(t)) continue;
            st.insert(t);
            vector<int> cnt(10, 0);
            for (auto& c : t) cnt[c - '0']++;
            long long temp = (n - cnt[0]) * fac[n - 1];
            for (int x : cnt) {
                temp /= fac[x];
            }
            res += temp;
        }
        return res;
    }
};
