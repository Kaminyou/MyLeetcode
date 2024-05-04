class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1)
            return false;
        if (n <= 3)
            return true;

        if (n % 2 == 0 || n % 3 == 0)
            return false;

        for (int i = 5; i * i <= n; i = i + 6)
            if (n % i == 0 || n % (i + 2) == 0)
                return false;

        return true;
    }
    vector<int> closestPrimes(int left, int right) {
        int prev = -1;
        int minInterval = INT_MAX;
        vector<int> res = {-1, -1};
        for (int i = left; i <= right; ++i) {
            if (isPrime(i)) {
                int current = i;
                if (prev != -1) {
                    int interval = current - prev;
                    if (interval < minInterval) {
                        minInterval = interval;
                        res[0] = prev;
                        res[1] = current;
                    }
                }
                prev = current;
            }
        }
        return res;
    }
};