class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if (n & 1) return false;
        int lower = 0;
        int upper = 0;
        for (int i = 0; i < n; ++i) {
            if (locked[i] == '1') {
                if (s[i] == '(') {
                    upper++;
                    lower++;
                }
                else {
                    upper--;
                    lower--;
                }
            }
            else {
                upper++;
                lower--;
            }
            if (lower < 0) lower += 2;
            if (upper < 0) return false;
        }
        return lower == 0;
    }
};
