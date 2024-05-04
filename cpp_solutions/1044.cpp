class Solution {
public:
    vector<int> power;
    string rabinKarp(string& s, int mid) {
        if (mid == 0) return "";
        int n = s.size(), curr = 0, mod = 1e7 + 7;
        unordered_map<int, vector<int>> hash;
        for (int i = 0; i < mid; ++i) {
            curr = (curr * 26 + s[i] - 'a') % mod;
        }
        hash[curr] = {0};
        for (int i = mid; i < s.size(); ++i) {
            curr = ((curr - power[mid - 1] * (s[i - mid] - 'a')) % mod + mod) % mod;
            curr = (curr * 26 + s[i] - 'a') % mod;
            if (!hash.count(curr)) {
                hash[curr] = {i - mid + 1};
            }
            else {
                string currStr = s.substr(i - mid + 1, mid);
                for (int start : hash[curr]) {
                    if (s.substr(start, mid) == currStr) {
                        return currStr;
                    }
                }
                hash[curr].push_back(i - mid + 1);
            }
        }
        return "";
    }
    string longestDupSubstring(string s) {
        int mod = 1e7 + 7;
        string res = "";
        power.resize(s.size(), 1);
        for (int i = 1; i < s.size(); ++i) {
            power[i] = power[i - 1] * 26;
            power[i] %= mod;
        }
        int left = 0;
        int right = s.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            string duplicate = rabinKarp(s, mid);
            if (duplicate.size() > res.size()) {
                res = duplicate;
                left = mid + 1;
            }
            else right = mid;
        }
        return res;
    }
};