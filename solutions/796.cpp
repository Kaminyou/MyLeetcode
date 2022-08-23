class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;
        string ss = s + s;
        int index = ss.find(goal);
        if (index == string::npos) return false;
        return true;
    }
};