class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int mismatch = 0;
        for (auto& c : s) {
            if (c == '(') {
                open++;
            }
            else {
                open--;
                if (open < 0) {
                    open = 0;
                    mismatch++;
                }
            }
        }
        return open + mismatch;
    }
};
