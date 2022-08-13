class Solution {
public:
    int largestPalindrome(int n) {
        int upper = pow(10, n) - 1;
        int lower = upper / 10;
        for (int current = upper; current > lower; current--) {
            string s = to_string(current);
            reverse(s.begin(), s.end());
            string target = to_string(current) + s;
            long long targetLL = stoll(target);
            for (long long multi = upper; multi * multi > targetLL; multi--) {
                if (targetLL % multi == 0) return targetLL % 1337;
            }
        }
        return 9;
    }
};