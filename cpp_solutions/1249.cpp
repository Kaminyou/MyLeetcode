class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string tempLeft = "";
        int cnt = 0;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                if (cnt >= 0) {
                    tempLeft.push_back(s[i]);
                    cnt++;
                }
            }
            else if (s[i] == ')') {
                if (cnt > 0) {
                    tempLeft.push_back(s[i]);
                    cnt--;
                }
            }
            else {
                tempLeft.push_back(s[i]);
            }
        }
        string tempRight = "";
        cnt = 0;
        n = tempLeft.size();
        for (int i = n - 1; i >= 0; --i) {
            if (tempLeft[i] == ')') {
                if (cnt >= 0) {
                    tempRight.push_back(tempLeft[i]);
                    cnt++;
                }
            }
            else if (tempLeft[i] == '(') {
                if (cnt > 0) {
                    tempRight.push_back(tempLeft[i]);
                    cnt--;
                }
            }
            else {
                tempRight.push_back(tempLeft[i]);
            }
        }
        reverse(tempRight.begin(), tempRight.end());
        return tempRight;
    }
};
