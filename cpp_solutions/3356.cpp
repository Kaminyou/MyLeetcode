class Solution {
public:
    bool check(vector<int>& nums, vector<vector<int>>& queries, int k) {
        // only use the first k queries
        int n = nums.size();
        int m = queries.size();
        vector<int> difference(n + 1, 0);
        for (int i = 0; i < min(k, m); ++i) {
            difference[queries[i][0]] += queries[i][2];
            difference[queries[i][1] + 1] -= queries[i][2];
        }
        int current = 0;
        for (int i = 0; i < n; ++i) {
            current += difference[i];
            if (current < nums[i]) return false;
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int left = 0;
        int right = queries.size() + 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (check(nums, queries, mid)) right = mid;
            else left = mid + 1;
        }
        if (left == queries.size() + 1) return -1;
        return left;
    }
};
