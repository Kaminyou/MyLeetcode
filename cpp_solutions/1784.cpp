class Solution {
public:
    bool checkOnesSegment(string s) {
        int curr = '1';
        int changes = 0;
        for (auto& c : s) {
            if (c != curr) {
                curr = c;
                changes++;
            }
        }
        return changes <= 1;
    }
};
