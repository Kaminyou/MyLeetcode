class Solution {
public:
    int minAddToMakeValid(string s) {
        int count = 0;
        int res = 0;
        for (auto& c : s) {
            if (c == '(') {
                count++;
            }
            else {
                count--;
                if (count < 0) {
                    count = 0;
                    res++;
                }
            }
        }
        return res + count;
    }
};