class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> counts(n, 0);
        int cnt = 0;
        int current = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (nums[i] > current) cnt++;
            else {
                cnt = 1;
            }
            current = nums[i];
            counts[i] = cnt;
        }
        for (int i = 0; i < n; ++i) {
            int end1 = i + k - 1;
            int end2 = i + 2 * k - 1;
            if (end2 >= n) break;
            if (counts[end1] >= k && counts[end2] >= k) return true;
            if (counts[end2] >= 2 * k) return true;
        }
        return false;
    }
};
