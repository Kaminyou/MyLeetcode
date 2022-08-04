class Solution {
public:
    int mirrorReflection(int p, int q) {
        int pN = p / __gcd(p, q);
        int qN = q / __gcd(p, q);
        if (pN & 1) {
            if (qN & 1) return 1;
            else return 0;
        }
        else return 2;
    }
};