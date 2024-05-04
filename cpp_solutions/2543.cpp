class Solution {
public:
    bool isReachable(int targetX, int targetY) {
        int gcd = __gcd(targetX, targetY);
        return gcd == (gcd & -gcd);
    }
};
