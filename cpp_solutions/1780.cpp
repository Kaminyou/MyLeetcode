class Solution {
public:
    bool checkPowersOfThree(int n) {
        while (n) {
            int now = 1;
            while (now * 3 <= n) {
                now *= 3;
            }
            n -= now;
            if (n >= now) return false;
        }
        return true;
    }
};
