class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long current = 0;
        long long leftSum = 0;
        long long rightSum = 0;

        for (auto costElement : cost) rightSum += costElement;
        long long res = LLONG_MAX;
        long long sum = 0;
        
        vector<vector<int>> numsWithCost;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            numsWithCost.push_back({nums[i], cost[i]});
            sum += static_cast<long long>(nums[i]) * cost[i];
        }
        sort(numsWithCost.begin(), numsWithCost.end());

        for (int i = 0; i < n; ++i) {
            long long diff = abs(numsWithCost[i][0] - current);
            current = numsWithCost[i][0];
            sum += leftSum * diff;
            sum -= rightSum * diff;
            res = min(res, sum);
            leftSum += numsWithCost[i][1];
            rightSum -= numsWithCost[i][1];
        }
        return res;
    }
};
