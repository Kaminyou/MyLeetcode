class Solution {
public:
    long long makeIntegerBeautiful(long long n, int target) {
        // get sum;
        int sum = 0;
        long long temp = n;
        while (temp) {
            sum += temp % 10;
            temp /= 10;
        }
        if (sum <= target) return 0;
        
        long long res = 0;
        int index = 0;
        bool add = false;
        while (sum > target && n > 0) {
            long long digit = n % 10;
            sum -= digit;
            res += (long long)(10 - digit - add) * pow(10, index);
            index++;
            sum += (1 - add);
            add = true;
            n /= 10;
        }
        return res;
    }
};