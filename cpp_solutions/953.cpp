class Solution {
public:
    bool isSorted(string& s1, string& s2, vector<int>& ascii2idx) {
        int m = s1.size();
        int n = s2.size();
        int common = min(m, n);
        for (int i = 0; i < common; ++i) {
            if (s1[i] == s2[i]) continue;
            else if (ascii2idx[s1[i] - 'a'] > ascii2idx[s2[i] - 'a']) return false;
            else return true;
        }
        if (m > n) return false;
        return true;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> ascii2idx(26, 0);
        for (int i = 0; i < 26; ++i) ascii2idx[order[i] - 'a'] = i;
        int n = words.size();
        for (int i = 0; i < n - 1; ++i) {
            if (!isSorted(words[i], words[i + 1], ascii2idx)) return false;
        }
        return true;
    }
};