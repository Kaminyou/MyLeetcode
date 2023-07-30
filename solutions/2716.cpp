class Solution {
public:
    int minimizedStringLength(string s) {
        vector<bool> hash(26, false);
        for (auto& c : s) {
            hash[c - 'a'] = true;
        }
        int res = 0;
        for (int i = 0; i < 26; ++i) {
            res += hash[i];
        }
        return res;
    }
};