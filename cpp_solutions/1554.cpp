class Solution {
public:
    bool check(string& s1, string& s2, int j, int m) {
        for (int i = 0; i < m; ++i) {
            if (i != j && s1[i] != s2[i]) return false;
            if (i == j && s1[i] == s2[i]) return false;
        }
        return true;
    }
    bool differByOne(vector<string>& dict) {
        int n = dict.size();
        int m = dict[0].size();
        long long mod = 1e9 + 7;
        vector<long long> hash(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                hash[i] = ((hash[i] * 26) + (dict[i][j] - 'a')) % mod;
            }
        }
        
        long long multiply = 1;
        for (int j = m - 1; j >= 0; --j) {
            unordered_map<long long, vector<int>> mp;
            for (int i = 0; i < n; ++i) {
                long long adjustHash = (hash[i] - dict[i][j] * multiply + mod) % mod;
                if (mp.find(adjustHash) != mp.end()) {
                    for (auto collision : mp[adjustHash]) {
                        // check if there are only #j different
                        if (check(dict[i], dict[collision], j, m)) return true;
                    }
                }
                mp[adjustHash].push_back(i);
            }
            multiply *= 26;
            multiply %= mod;
        }
        return false;
    }
};