class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> sStack;
        stack<char> tStack;
        for (auto c : s) {
            if (c == '#') {
                if (!sStack.empty()) sStack.pop();
            }
            else (sStack.push(c));
        }
        for (auto c : t) {
            if (c == '#') {
                if (!tStack.empty()) tStack.pop();
            }
            else (tStack.push(c));
        }
        if (sStack.size() != tStack.size()) return false;
        int n = sStack.size();
        while (n--) {
            if (sStack.top() != tStack.top()) return false;
            sStack.pop();
            tStack.pop();
        }
        return true;
    }
};