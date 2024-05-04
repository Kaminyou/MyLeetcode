class Solution {
public:
    vector<string> res;
    void backtracking(string s, int curr, int leftCnt, int rightCnt) {
        if (leftCnt == 0 && rightCnt == 0) {
            if (isValid(s)) res.push_back(s);
            return;
        }
        
        for (int i = curr; i < s.size(); ++i) {
            if (i > 0 && s[i] == s[i - 1]) continue;
            if (s[i] == '(' && leftCnt) {
                backtracking(s.substr(0, i) + s.substr(i + 1), i, leftCnt - 1, rightCnt);
            }
            if (s[i] == ')' && rightCnt) {
                backtracking(s.substr(0, i) + s.substr(i + 1), i, leftCnt, rightCnt - 1);
            }
        }
    }
    bool isValid(string& s) {
        int cnt = 0;
        for (auto& c : s) {
            if (c == '(') cnt++;
            else if (c == ')') {
                if (cnt == 0) return false;
                cnt--;
            }
        }
        return cnt == 0;
    }
    vector<string> removeInvalidParentheses(string s) {
        int leftCnt = 0;
        int rightCnt = 0;
        for (auto& c : s) {
            if (c == '(') leftCnt++;
            else if (c == ')') {
                if (leftCnt == 0) rightCnt++;
                else leftCnt--;
            }
        }
        backtracking(s, 0, leftCnt, rightCnt);
        return res;
    }
};