class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.size();
        int ones = 0;
        for (auto& c : s) {
            if (c == '1') ones++;
            c = '0';
        }
        s[n - 1] = '1';
        ones--;
        int index = 0;
        while (ones) {
            s[index] = '1';
            ones--;
            index++;
        }
        return s;
    }
};
