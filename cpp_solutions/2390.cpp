class Solution {
public:
    string removeStars(string s) {
        string res;
        int n = s.size();
        int star = 0;
        for (int i = n - 1; i >= 0; --i) {
            char curr = s[i];
            if (s[i] == '*') star++;
            else {
                if (star > 0) {
                    star--;
                }
                else {
                    res.push_back(curr);
                }
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};