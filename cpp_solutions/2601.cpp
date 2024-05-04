class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        vector<bool> primeTable(1001, true);
        primeTable[0] = false;
        primeTable[1] = false;
        for (int i = 1; i <= 1000; ++i) {
            if (primeTable[i] == false) continue;
            for (int num = i * 2; num <= 1000; num += i) {
                primeTable[num] = false;
            }
        }
        vector<int> primes;
        for (int i = 0; i <= 1000; ++i) {
            if (primeTable[i]) {
                primes.push_back(i);
            }
        }
        
        int n = nums.size();
        for (int i = n - 2; i >= 0; --i) {
            int next = nums[i + 1];
            int current = nums[i];
            if (current < next) continue;
            // current - ? < next
            // ? > current - next
            int target = current - next;
            auto it = upper_bound(primes.begin(), primes.end(), target);
            if (it == primes.end()) return false;
            int index = it - primes.begin();
            int prime = primes[index];
            if (nums[i] <= prime) return false;
            nums[i] -= prime;
        }
        return true;
    }
};