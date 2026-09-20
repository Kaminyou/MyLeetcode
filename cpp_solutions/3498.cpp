class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        for (int i = 0; i < s.size(); ++i) {
            sum += (i + 1) * (26 - (s[i] - 'a'));
        }
        return sum;
    }
};
