class Solution {
public:
    void preprocessing(int current, int end, int sum, int count, vector<int>& nums, vector<vector<int>>& memo) {
        if (current == end) {
            memo[count].push_back(sum);
            return;
        }
        preprocessing(current + 1, end, sum, count, nums, memo);
        preprocessing(current + 1, end, sum + nums[current], count + 1, nums, memo);
    }
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
        vector<vector<int>> leftPart(n + 1);
        vector<vector<int>> rightPart(n + 1);
        
        preprocessing(0, n, 0, 0, nums, leftPart);
        preprocessing(n, n * 2, 0, 0, nums, rightPart);
        
        for (auto& eachRightPart : rightPart) {
            sort(eachRightPart.begin(), eachRightPart.end());
        }
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int half = sum / 2;
        int res = INT_MAX;
        for (int i = 0; i <= n; ++i) {
            for (auto& firstSum : leftPart[i]) {
                int target = half - firstSum;
                auto it = lower_bound(rightPart[n - i].begin(), rightPart[n - i].end(), target);
                if (it != rightPart[n - i].end()) res = min(res, abs(sum - 2 * (firstSum + *it)));
                if (it != rightPart[n - i].begin()) res = min(res, abs(sum - 2 * (firstSum + *prev(it))));
            }
        }
        return res;
    }
};