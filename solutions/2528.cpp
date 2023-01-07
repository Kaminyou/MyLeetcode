class Solution {
public:
    bool criteria(vector<long long> diffArray, long long target, int r, long long k) {
        // given k, can all be >= target or not
        
        int n = diffArray.size();
        long long currentValue = 0;
        for (int i = 0; i < n; ++i) {
            currentValue += diffArray[i];
            if (currentValue < target) {
                k -= (target - currentValue);
                if (k < 0) return true;
                int lastIdx = min(i + r * 2 + 1, n);
                if (lastIdx < n) diffArray[lastIdx] -= (target - currentValue);
                currentValue += (target - currentValue);
            }
        }
        return false;
    }
    long long maxPower(vector<int>& stations, int r, int k) {
        
        int n = stations.size();
        vector<long long> prefixSum(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            prefixSum[i] = prefixSum[i - 1] + stations[i - 1];
        }
        vector<long long> sumWindowArray(n, 0);
        for (int i = 0; i < n; ++i) {
            int leftBound = max(0, i - r);
            int rightBound = min(i + 1 + r, n);
            sumWindowArray[i] = stations[i] + prefixSum[i] - prefixSum[leftBound] + prefixSum[rightBound] - prefixSum[i + 1];
        }
        vector<long long> diffArray(n, 0);
        diffArray[0] = sumWindowArray[0];
        for (int i = 1; i < n; ++i) {
            diffArray[i] = sumWindowArray[i] - sumWindowArray[i - 1];
        }
        
        long long left = 0;
        long long right = 1e11;
        while (left < right) {
            // the least power of a city that can not be achieved
            long long mid = left + (right - left) / 2;
            if (criteria(diffArray, mid, r, k)) right = mid;
            else left = mid + 1;
        }
        return left - 1; // the max power of a city can be achieved
    }
};