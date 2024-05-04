class Solution {
public:
    int alternateDigitSum(int n) {
        int index = 0;
        int sum = 0;
        vector<int> digits;
        while (n) {
            int digit = n % 10;
            n /= 10;
            digits.push_back(digit);
        }
        int s = digits.size();
        for (int i = s - 1; i >= 0; --i) {
            if (index & 1) sum -= digits[i];
            else sum += digits[i];
            index++;
        }
        return sum;
    }
};