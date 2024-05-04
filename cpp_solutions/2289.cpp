class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        stack<int> st; // monotonic decreasing
        int res = 0;
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && nums[i] > nums[st.top()]) {
                int index = st.top();
                st.pop();
                dp[i]++;
                dp[i] = max(dp[i], dp[index]);
                res = max(res, dp[i]);
            }
            st.push(i);
        }
        return res;
    }
};