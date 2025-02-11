class Solution {
public:
    bool check(vector<int>& counts, int k) {
        int n = counts.size();
        for (int i = 0; i < n; ++i) {
            int end1 = i + k - 1;
            int end2 = i + 2 * k - 1;
            if (end2 >= n) break;
            if (counts[end1] >= k && counts[end2] >= k) return true;
            if (counts[end2] >= 2 * k) return true;
        }
        return false;
    }
    int maxIncreasingSubarrays(vector<int>& nums) {
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
        int left = 1;
        int right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (!check(counts, mid)) right = mid;
            else left = mid + 1;
        }
        return left - 1;
    }
};
