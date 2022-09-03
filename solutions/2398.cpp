class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int left = 0;
        int n = chargeTimes.size();
        long long sum = 0;
        multiset<int> maxSt;
        int res = 0;
        for (int right = 0; right < n; ++right) {
            sum += runningCosts[right];
            maxSt.insert(chargeTimes[right]);
            while (left <= right && sum * (right - left + 1) + *maxSt.rbegin() > budget) {
                sum -= runningCosts[left];
                maxSt.erase(maxSt.find(chargeTimes[left]));
                left++;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};
// class Solution {
// public:
//     bool criteria(vector<int>& chargeTimes, vector<long long>& prefixSum, int k, long long budget) {
//         deque<int> dq;
//         vector<int> maxRange;
//         int n = chargeTimes.size();
//         for (int right = 0; right < n; ++right) {
//             while (!dq.empty() && dq.front() + k <= right) dq.pop_front();
//             while (!dq.empty() && chargeTimes[right] >= chargeTimes[dq.back()]) dq.pop_back();
//             dq.push_back(right);
//             if (right - k + 1 >= 0) maxRange.push_back(chargeTimes[dq.front()]);
//         }
//         // less or equal to budget
//         int left = 0;
//         long long minValue = LLONG_MAX;
//         for (int right = 0; right < n; ++right) {
//             if (right - left + 1 > k) left++;
//             if (right - left + 1 == k) {
//                 minValue = min(minValue, maxRange[left] + (prefixSum[right + 1] - prefixSum[left]) * (right - left + 1));
//             }
//         }
//         return minValue > budget;
        
//     }
//     int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
//         int n = chargeTimes.size();
//         int res = 0;        
        
//         vector<long long> prefixSum(n + 1, 0);
//         for (int i = 0; i < n; ++i) prefixSum[i + 1] = prefixSum[i] + runningCosts[i];
        
//         int left = 1;
//         int right = n + 1;
//         while (left < right) {
//             int mid = left + (right - left) / 2;
//             if (criteria(chargeTimes, prefixSum, mid, budget)) right = mid;
//             else left = mid + 1;
//         }
//         left--;
//         return left;
//     }
// };