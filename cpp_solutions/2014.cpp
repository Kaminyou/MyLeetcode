class Solution {
public:
    string res = "";
    int countOccur(const string& s, const string& sub) {
        if (sub.size() == 0) return s.size();
        int occur = 0;
        int subIdx = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == sub[subIdx]) subIdx++;
            if (subIdx == sub.size()) {
                subIdx = 0;
                occur++;
            }
        }
        return occur;
    }
    void recursive(const string& s, string sub, const int& k) {
        int n = countOccur(s, sub);
        if (n < k) return;
        if (sub.size() >= res.size() && sub > res) res = sub;
        for (char c = 'a'; c <= 'z'; c++) {
            recursive(s, sub + c, k);
        }
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        recursive(s, "", k);
        return res;
    }
};