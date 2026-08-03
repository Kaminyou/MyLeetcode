class Solution {
public:
    vector<int> getPrimes() {
        vector<int> primes;
        vector<bool> visited(1001, false);
        for (int i = 2; i < 1001; ++i) {
            if (!visited[i]) primes.push_back(i);
            for (int j = 2; i * j < 1001; ++j) {
                visited[i * j] = false;
            }
        }
        return primes;
    }
    long long getAnswer(vector<int>& nums, int prime) {
        int n = nums.size();
        long long sum = 0;
        long long res = INT_MIN;
        for (int i = 0; i < n; ++i) {
            int val = nums[i];
            if (val % prime != 0) val = val * -1;
            sum += val;
            res = max(res, sum);
            if (sum < 0) sum = 0;
        }
        return res;
    }
    
    int divisibleGame(vector<int>& nums) {
        vector<int> primes = getPrimes();
        for (auto& num : nums) {
            if (num == 1) continue;
            bool isPrime = true;
            for (auto& prime : primes) {
                if (num % prime == 0) {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime) primes.push_back(num);
        }
        long long maxPrime = -1;
        long long maxVal = LLONG_MIN;
        for (auto& prime : primes) {
            long long val = getAnswer(nums, prime);
            if (val > maxVal) {
                maxVal = val;
                maxPrime = prime;
            }
        }
        long long ans = maxVal * maxPrime;
        long long mod = 1e9 + 7;
        return (ans + mod) % mod;
    }
};

