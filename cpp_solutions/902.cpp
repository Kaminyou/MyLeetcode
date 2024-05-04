class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string nStr = to_string(n);
        int size = nStr.size();
        int digitNum = digits.size();
        
        int res = 0;
        
        // size < size of n
        for (int i = 1; i <= size - 1; ++i) {
            res += (int)pow(digitNum, i);
        }
        
        // size == size of n
        for (int i = 0; i < size; ++i) {
            int currDigit = nStr[i] - '0';
            bool haveDigit = false;
            for (auto& digit : digits) {
                if (stoi(digit) < currDigit) {
                    res += (int)pow(digitNum, size - i - 1);
                }
                else if (stoi(digit) == currDigit) {
                    haveDigit = true;
                }
            }
            if (!haveDigit) return res;
        }
        
        // + 1: match n
        return res + 1;
    }
};