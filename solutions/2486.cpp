class Solution {
public:
    int appendCharacters(string s, string t) {
        int tIdx = 0;
        int n = t.size();
        for (auto& c : s) {
            if (tIdx < n) {
                if (c == t[tIdx]) tIdx++;
            }
        }
        return n - tIdx;
    }
};