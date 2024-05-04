class Solution {
public:
    bool isPrime(int n) {
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) return false;
        }
        return true;
    }
    int smallestValue(int n) {
        int temp = n;
        bool dividable = true;
        int sum = 0;
        while (dividable) {
            dividable = false;
            for (int i = 2; i <= n; ++i) {
                if (n % i == 0) {
                    n /= i;
                    sum += i;
                    dividable = true;
                    break;
                }
            }
        }
        if (sum == temp) return sum;
        if (isPrime(sum)) return sum;
        else return smallestValue(sum);
    }
};