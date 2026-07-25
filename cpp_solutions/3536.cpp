class Solution {
public:
    int maxProduct(int n) {
        vector<int> digits;
        while (n) {
            digits.push_back(n % 10);
            n /= 10;
        }
        sort(digits.begin(), digits.end());
        int m = digits.size();
        return digits[m - 1] * digits[m - 2];
    }
};
