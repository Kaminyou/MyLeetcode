class Solution {
public:
    bool valid(int num) {
        while (num) {
            int digit = num % 10;
            if (!digit) return false;
            num /= 10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i < n; ++i) {
            int a = i;
            int b = n - i;
            if (valid(a) && valid(b)) return {a, b};
        }
        return {0, 0};
    }
};
