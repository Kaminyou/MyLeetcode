class Solution {
public:
    int cal_inv(int n) {
        int inv = 0;
        while (n) {
            inv *= 10;
            inv += n % 10;
            n /= 10;
        }
        return inv;
    }
    int mirrorDistance(int n) {
        int inv = cal_inv(n);
        return abs(n - inv);
    }
};
