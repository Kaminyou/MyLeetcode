class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_set<int> st(nums.begin(), nums.end());
        
        int n = nums.size();
        int ans = -1;
        
        int maximum = nums[n - 1];
        for (int i = 0; i < n; ++i) {
            long long start = nums[i];
            if (start * start > maximum) break;
            int length = 1;
            while (start * start <= maximum && st.count(start * start)) {
                start = start * start;
                length++;
            }
            if (length == 1) continue;
            ans = max(ans, length);
        }
        return ans;
    }
};