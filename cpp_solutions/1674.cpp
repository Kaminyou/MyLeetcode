class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        // space = [2, limit * 2]
        // a <= b
        // 2: [2, a]
        // 1: [a + 1, a + b - 1]
        // 0: [a + b]
        // 1: [a + b + 1, b + limit]
        // 2: [b + limit + 1, limit * 2]
        
        int n = nums.size();
        vector<int> diff(limit * 2 + 2, 0);
        for (int i = 0; i < n / 2; ++i) {
            int a = nums[i];
            int b = nums[n - i - 1];
            if (a > b) swap(a, b);
            // a <= b
            diff[2] += 2;
            diff[a + 1] -= 1;
            diff[a + b] -= 1;
            diff[a + b + 1] += 1;
            diff[b + limit + 1] += 1;
        }
        int res = INT_MAX;
        int curr = 0;
        for (int i = 2; i <= limit * 2; ++i) {
            curr += diff[i];
            res = min(res, curr);
        }
        return res;
    }
};

