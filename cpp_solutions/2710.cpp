class Solution {
public:
    string removeTrailingZeros(string num) {
        int n = num.size();
        while (n != 1 && num[n - 1] == '0') {
            n--;
        }
        return num.substr(0, n);
    }
};