class Solution {
public:
    char processStr(string s, long long k) {
        long long length = 0;
        for (auto c : s) {
            if (c >= 'a' && c <= 'z') length++;
            else if (c == '*') length = max(0LL, length - 1);
            else if (c == '#') length *= 2;
        }
        if (k >= length) return '.';
        for (int i = s.size() - 1; i >= 0; --i) {
            int c = s[i];
            if (c >= 'a' && c <= 'z') {
                length--;
                if (length == k) return c;
            }
            else if (c == '*') {
                length++;
            }
            else if (c == '#') {
                long long half = length / 2;
                if (k >= half) k -= half;
                length = half;
            }
            else if (c == '%') {
                k = length - k - 1;
            }
        }
        return '.';
    }
};
