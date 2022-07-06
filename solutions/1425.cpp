class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q;
        int res = INT_MIN;
        vector<int> dp(n, INT_MIN);

        for (int i = 0; i < n; ++i) {
            if (i > k && q.front() == i - k - 1) q.pop_front();
            dp[i] = (q.empty() ? 0 : max(0, dp[q.front()])) + nums[i];
            res = max(res, dp[i]);
            while (!q.empty() && dp[i] >= dp[q.back()]) q.pop_back();
            q.push_back(i);
        }
        return res;
    }
};


// v2
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        multiset<int> mst;
        int res = INT_MIN;
        vector<int> dp(n, INT_MIN);
        dp[0] = nums[0];
        res = max(res, dp[0]);
        mst.insert(dp[0]);
        
        for (int i = 1; i < n; ++i) {
            if (i > k) mst.erase(mst.find(dp[i - k - 1]));
            dp[i] = max(*mst.rbegin(), 0) + nums[i];
            res = max(res, dp[i]);
            mst.insert(dp[i]);
        }
        return res;
    }
};