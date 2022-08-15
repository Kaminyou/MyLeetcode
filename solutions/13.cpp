class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        int index = 0;
        while (index < s.size()) {
            if (s[index] == 'V') sum += 5;
            else if (s[index] == 'L') sum += 50;
            else if (s[index] == 'D') sum += 500;
            else if (s[index] == 'M') sum += 1000;
            else if (s[index] == 'I') {
                if (index + 1 < s.size() && s[index + 1] == 'V') {
                    sum += 4;
                    index++;
                }
                else if (index + 1 < s.size() && s[index + 1] == 'X') {
                    sum += 9;
                    index++;
                }
                else sum += 1;
            }
            else if (s[index] == 'X') {
                if (index + 1 < s.size() && s[index + 1] == 'L') {
                    sum += 40;
                    index++;
                }
                else if (index + 1 < s.size() && s[index + 1] == 'C') {
                    sum += 90;
                    index++;
                }
                else sum += 10;
            }
            else if (s[index] == 'C') {
                if (index + 1 < s.size() && s[index + 1] == 'D') {
                    sum += 400;
                    index++;
                }
                else if (index + 1 < s.size() && s[index + 1] == 'M') {
                    sum += 900;
                    index++;
                }
                else sum += 100;
            }
            index++;
        }
        return sum;
    }
};
// I: 1 <-
// V: 5
// X: 10 <-
// L: 50
// C: 100 <-
// D: 500
// M: 1000
// IV: 4
// IX: 9
// XL: 40
// XC: 90
// CD: 400
// CM: 900
