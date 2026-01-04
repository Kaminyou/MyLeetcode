class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        bool isPrime[100001];
        for (int i = 0; i < 100001; ++i) isPrime[i] = true;
        for (int num = 2; num * num <= 100000; ++num) {
            if (isPrime[num]) {
                int i = 2;
                while (num * i <= 100000) {
                    isPrime[num * i] = false;
                    i++;
                }
            }
        }
        vector<int> primes;
        for (int i = 2; i < 100001; ++i) {
            if (isPrime[i]) primes.push_back(i);
        }
        int n = primes.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            if (primes[i] * primes[i] >= 100001) break;
            //mp[primes[i] * primes[i]] = 1 + primes[i] + primes[i] * primes[i];
            for (int j = i + 1; j < n; ++j) {
                if (primes[i] * primes[j] >= 100001) break;
                mp[primes[i] * primes[j]] = 1 + primes[i] +  primes[j] + primes[i] * primes[j];
            }
        }
        for (int i = 0; i < n; ++i) {
            if (primes[i] * primes[i] * primes[i] >= 100001) break;
            mp[primes[i] * primes[i] * primes[i]] = 1 + primes[i] + primes[i] * primes[i] + primes[i] * primes[i] * primes[i];
        }
        int res = 0;
        for (auto& num : nums) {
            res += mp[num];
        }
        return res;
    }
};

