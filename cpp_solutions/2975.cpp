class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        long long mod = 1e9 + 7;
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        unordered_set<long long> st;
        hFences.insert(hFences.begin(), 1);
        hFences.push_back(m);

        vFences.insert(vFences.begin(), 1);
        vFences.push_back(n);

        int mm = hFences.size();
        for (int i = 0; i < mm - 1; ++i) {
            for (int j = i + 1; j < mm; ++j) {
                long long length = hFences[j] - hFences[i];
                st.insert(length);
            }
        }

        long long res = -1;
        int nn = vFences.size();
        for (int i = 0; i < nn - 1; ++i) {
            for (int j = i + 1; j < nn; ++j) {
                long long length = vFences[j] - vFences[i];
                if (!st.count(length)) continue;
                res = max(res, length * length);
            }
        }
        return res % mod;
    }
};

