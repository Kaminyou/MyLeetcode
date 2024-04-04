class Solution {
public:
    int maxDepth(string s) {
        int cnt = 0;
        int res = 0;
        for (auto& c : s) {
            if (c == '(') cnt++;
            else if (c == ')') cnt--;
            res = max(res, cnt);
        }
        return res;
    }
};
