class Solution {
public:
    bool isPrime(int num, vector<int>& primes) {
        if (num == 1) return false;
        for (auto& prime : primes) {
            if (num == prime) return true;
            if (num % prime == 0) return false;
        }
        return true;
    }
    int diagonalPrime(vector<vector<int>>& nums) {
        unordered_set<int> notPrime;
        vector<int> primes;
        notPrime.insert(1);
        for (int i = 2; i <= 2 * 1e3; ++i) {
            if (notPrime.count(i)) continue;
            primes.push_back(i);
            for (int j = 2; i * j <= 2 * 1e3; ++j) {
                notPrime.insert(i * j);
            }
        }
        
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (!isPrime(nums[i][i], primes)) continue;
            res = max(res, nums[i][i]);
        }
        for (int i = 0; i < n; ++i) {
            if (!isPrime(nums[i][n - i - 1], primes)) continue;
            res = max(res, nums[i][n - i - 1]);
        }
        return res;
    }
};