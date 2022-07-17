class Solution {
public:
    bool checkValidString(string s) {
        // check from left
        int leftCount = 0;
        int starCount = 0;
        for (auto c : s) {
            if (c == '(') leftCount++;
            else if (c == ')') {
                if (leftCount < 1) {
                    if (starCount == 0) return false;
                    else starCount--;
                }
                else {
                    leftCount--;
                }
            }
            else {
                starCount++;
            }
        }
        if (leftCount != 0) {
            if (leftCount > starCount) return false;
        }
        // check from right
        int rightCount = 0;
        starCount = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            char c = s[i];
            if (c == ')') rightCount++;
            else if (c == '(') {
                if (rightCount < 1) {
                    if (starCount == 0) return false;
                    else starCount--;
                }
                else {
                    rightCount--;
                }
            }
            else {
                starCount++;
            }
        }
        if (rightCount != 0) {
            if (rightCount > starCount) return false;
        }
        return true;
    }
};