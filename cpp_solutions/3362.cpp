class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(), queries.end());
        int n = nums.size();
        vector<int> diff(n + 1, 0);

        int cur = 0;
        int qIdx = 0;
        priority_queue<int> maxQ;
        for (int i = 0; i < n; ++i) {
            cur += diff[i];
            while (qIdx < queries.size() && queries[qIdx][0] == i) {
                maxQ.push(queries[qIdx][1]);
                qIdx++;
            }
            while (nums[i] > cur && !maxQ.empty() && maxQ.top() >= i) {
                cur++;
                diff[maxQ.top() + 1] -= 1;
                maxQ.pop();
            }
            if (nums[i] > cur) return -1;
        }
        return maxQ.size();
    }
};

