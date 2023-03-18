typedef pair<int, int> P;
class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long score = 0;
        int n = nums.size();
        vector<bool> marked(n, false);
        priority_queue<P, vector<P>, greater<P>> pq;
        for (int i = 0; i < n; ++i) {
            pq.push({nums[i], i});
        }
        
        while (!pq.empty()) {
            auto [num, idx] = pq.top();
            pq.pop();
            if (marked[idx]) continue;
            score += num;
            marked[idx] = true;
            if (idx - 1 >= 0) marked[idx - 1] = true;
            if (idx + 1 < n) marked[idx + 1] = true;
        }
        return score;
    }
};