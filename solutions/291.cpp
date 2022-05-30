class Solution {
public:
    bool backtracking(string& pattern, string& s, int pIdx, int sIdx, unordered_map<string, char>& s2c, unordered_map<char, string>& c2s) {
        if (pIdx == pattern.size() && sIdx == s.size()) return true;
        if (pIdx == pattern.size() && sIdx != s.size()) return false;
        if (pIdx != pattern.size() && sIdx == s.size()) return false;
        for (int i = sIdx; i < s.size(); i++) {
            string temp = s.substr(sIdx, i - sIdx + 1);
            if (s2c.find(temp) != s2c.end()) {
                if (s2c[temp] != pattern[pIdx]) continue;
                if (c2s[pattern[pIdx]] != temp) continue;
                if (backtracking(pattern, s, pIdx + 1, i + 1, s2c, c2s)) return true;
            }
            else {
                if (c2s.find(pattern[pIdx]) != c2s.end()) continue;
                bool flag = false;
                s2c[temp] = pattern[pIdx];
                c2s[pattern[pIdx]] = temp;
                flag = (backtracking(pattern, s, pIdx + 1, i + 1, s2c, c2s));
                s2c.erase(temp);
                c2s.erase(pattern[pIdx]);
                if (flag) return true;
            }
        }
        return false;
    }
    bool wordPatternMatch(string pattern, string s) {
        unordered_map<string, char> s2c;
        unordered_map<char, string> c2s;
        return backtracking(pattern, s, 0, 0, s2c, c2s);
    }
};