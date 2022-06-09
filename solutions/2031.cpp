class Counter {
private:
    vector<int> counts;
public:
    Counter() {
        // allow -1e5 ~ 1e5
        counts.resize(1e5 * 2 + 1, 0);
    }
    void add(int value) {
        counts[value + 1e5]++;
    }
    int getCount(int index) {
        return counts[index + 1e5];
    }
    
};
class Solution {
public:
    int subarraysWithMoreZerosThanOnes(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + (nums[i] == 1 ? 1 : -1);
        }
        
        long long res = 0;
        const long long mod = 1e9 + 7;
        Counter* counter = new Counter();
        
        long long preValue = 0;
        long long preCount = 0;
        for (auto& num : prefixSum) {
            if (num == preValue + 1) preCount += counter->getCount(preValue);
            else preCount -= counter->getCount(preValue - 1);
            counter->add(num);
            preValue = num;
            preCount %= mod;
            res += preCount;
            res %= mod;
        }
        return res;
    }
};