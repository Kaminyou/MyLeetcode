class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        if (s == target) return true;
        int cntSOne = 0;
        int cntTargetOne = 0;
        for (auto& c : s) {
            if (c == '1') cntSOne++;
        }
        for (auto& c : target) {
            if (c == '1') cntTargetOne++;
        }
        return cntSOne > 0 && cntTargetOne > 0;
    }
};
