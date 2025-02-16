class Solution {
public:
    bool doesAliceWin(string s) {
        int cnt = 0;
        for (auto& c : s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') cnt++;
        }
        return cnt != 0;
    }
};
