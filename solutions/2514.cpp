class Solution {
public:
    unordered_map<long long, long long> mp;
    long long inv(long long a, long long mod) {
        if (mp.find(a) != mp.end()) return mp[a];
        if (a == 1) return 1;
        return mp[a] = (mod - mod / a) * inv(mod % a, mod) % mod;
    }
    int countAnagrams(string s) {
        stringstream ss(s);
        string temp;
        long long ans = 1;
        long long mod = 1e9 + 7;
        
        vector<int> counts(26, 0);
        while (getline(ss, temp, ' ')) {
            for (int i = 0; i < 26; ++i) counts[i] = 0;
            int total = temp.size();
            for (int i = 0; i < total; ++i) counts[temp[i] - 'a']++;
            long long sum = 1;
            for (int i = 1; i <= total; ++i) {
                sum *= i;
                sum %= mod;
            }
            for (int i = 0; i < 26; ++i) {
                for (int j = 2; j <= counts[i]; ++j) {
                    sum *= inv(j, mod);
                    sum %= mod;
                }
            }
            ans *= sum;
            ans %= mod;
        }
        return ans;
    }
};