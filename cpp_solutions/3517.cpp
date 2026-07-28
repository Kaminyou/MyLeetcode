class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> counts(26, 0);
        for (auto& c : s) {
            counts[c - 'a']++;
        }
        string mid = "";
        for (int i = 0; i < 26; ++i) {
            if (counts[i] & 1) {
                mid.push_back('a' + i);
                counts[i] -= 1;
            }
            counts[i] /= 2;
        }
        string res = "";
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < counts[i]; ++j) {
                res.push_back('a' + i);
            }
        }
        string rev = res;
        reverse(rev.begin(), rev.end());
        return res + mid + rev;
    }
};
