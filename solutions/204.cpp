class Solution {
public:
    int countPrimes(int n) {
        // [0 ... n - 1]
        vector<bool> primes(n, false);
        int res = 0;
        for (int i = 2; i < n; ++i) {
            if (primes[i]) continue;
            res++;
            for (int j = 2; j * i < n; j++) primes[j * i] = true;
        }
        return res;
    }
};