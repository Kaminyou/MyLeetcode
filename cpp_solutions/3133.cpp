class Solution {
public:
    long long minEnd(int n, int x) {
        long long res = x;
        long long remain = n - 1;
        long long position = 1;
        while (remain) {
            if (!(res & position)) {
                res |= (remain & 1) * position;
                remain >>= 1;
            }
            position <<= 1;
        }
        return res;
    }
};

