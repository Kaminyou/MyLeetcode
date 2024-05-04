class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size();
        n /= 3;
        long long res = LLONG_MAX;
        
        long long preMin = 0;
        priority_queue<long long> pqPreMin; // max Heap
        for (int i = 0; i < n; ++i) {
            preMin += nums[i];
            pqPreMin.push(nums[i]);
        }
        
        long long sufMax = 0;
        priority_queue<long long, vector<long long>, greater<long long>> pqSufMax; // min Heap
        for (int i = 2 * n; i < 3 * n; ++i) {
            sufMax += nums[i];
            pqSufMax.push(nums[i]);
        }
        
        res = min(res, preMin - sufMax);
        
        // [n - 1, 2 * n + 1]
        vector<long long> preMinArray(n + 2, LLONG_MAX);
        vector<long long> sufMaxArray(n + 2, LLONG_MAX);
        
        preMinArray[0] = preMin;
        for (int i = n; i <= 2 * n; ++i) {
            preMin += nums[i];
            pqPreMin.push(nums[i]);
            long long maxVal = pqPreMin.top();
            pqPreMin.pop();
            preMin -= maxVal;
            preMinArray[i - n + 1] = preMin;
        }
        
        sufMaxArray[n + 1] = sufMax;
        for (int i = 2 * n - 1; i >= n - 1; --i) {
            sufMax += nums[i];
            pqSufMax.push(nums[i]);
            long long minVal = pqSufMax.top();
            pqSufMax.pop();
            sufMax -= minVal;
            sufMaxArray[i - n + 1] = sufMax;
        }
        
        for (int i = 0; i < n + 1; ++i) {
            res = min(res, preMinArray[i] - sufMaxArray[i + 1]);
        }
        return res;
    }
};