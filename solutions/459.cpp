class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t = s + s;
        int index = t.find(s, 1);
        if (index == s.size()) return false;
        return true;
    }
};