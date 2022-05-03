class Solution {
public:
    int newInteger(int n) {
        // base 10 to base 9
        int res = 0;
        long long multi = 1;
        while (n) {
            int k = n % 9;
            n /= 9;
            res += (k * multi);
            multi *= 10;
        }
        return res;
    }
};