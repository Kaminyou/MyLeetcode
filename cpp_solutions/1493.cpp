class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> fromLeft(n, 0);
        vector<int> fromRight(n, 0);
        int current = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 1) current += 1;
            else current = 0;
            fromLeft[i] = current;
        }
        current = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (nums[i] == 1) current += 1;
            else current = 0;
            fromRight[i] = current;
        }

        int res = 0;
        for (int i = 0; i < n; ++i) {
            int left = 0;
            if (i > 0) left = fromLeft[i - 1];
            int right = 0;
            if (i < n - 1) right = fromRight[i + 1];
            res = max(res, left + right);
        }
        return res;
    }
};