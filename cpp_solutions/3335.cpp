class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        long long res = 0;
        long long mod = 1e9 + 7;
        vector<long long> hash(26, 0);
        vector<long long> hashTemp(26, 0);
        for (auto& c : s) hash[c - 'a']++;
        for (int i = 0; i < t; ++i) {
            for (int i = 0; i < 25; ++i) {
                hashTemp[i + 1] = hash[i];
            }
            hashTemp[0] = hash[25];
            hashTemp[1] += hash[25];
            for (int i = 0; i < 26; ++i) {
                hash[i] = hashTemp[i];
                hash[i] %= mod;
            }
        }
        for (int i = 0; i < 26; ++i) {
            res += hash[i];
            res %= mod;
        }
        return res;
    }
};
