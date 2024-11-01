class Solution {
public:
    string makeFancyString(string s) {
        int cnt = 0;
        char curr = '#';
        string res;
        for (auto& c : s) {
            if (c != curr) {
                curr = c;
                cnt = 1;
                res.push_back(c);
            }
            else {
                cnt++;
                if (cnt <= 2) res.push_back(c);
            }
        }
        return res;
    }
};
