class Solution {
public:
    int sSize;
    int pSize;
    vector<vector<int>> memo;
    int _isMatch(string& s, string& p, int sIdx, int pIdx) {
        if (memo[sIdx][pIdx] != -1) return memo[sIdx][pIdx];
        if (pIdx == pSize - 1 && p[pIdx] == '*') return memo[sIdx][pIdx] = 1;
        if (sIdx == sSize && pIdx == pSize) return memo[sIdx][pIdx] = 1;
        if (sIdx < sSize && pIdx == pSize) return memo[sIdx][pIdx] = 0;
        if (p[pIdx] == '?') {
            if (sIdx == sSize) return memo[sIdx][pIdx] = 0;
            return memo[sIdx][pIdx] = _isMatch(s, p, sIdx + 1, pIdx + 1); 
        }
        else if (p[pIdx] == '*') {
            if (sIdx < sSize) return memo[sIdx][pIdx] = _isMatch(s, p, sIdx + 1, pIdx) || _isMatch(s, p, sIdx, pIdx + 1);
            return memo[sIdx][pIdx] = _isMatch(s, p, sIdx, pIdx + 1); 
        }
        else {
            if (s[sIdx] != p[pIdx]) return false;
            return memo[sIdx][pIdx] = _isMatch(s, p, sIdx + 1, pIdx + 1); 
        }
    }
    bool isMatch(string s, string p) {
        sSize = s.size();
        pSize = p.size();
        memo.resize(sSize + 1, vector<int>(pSize + 1, -1));
        return _isMatch(s, p, 0, 0);
    }
};