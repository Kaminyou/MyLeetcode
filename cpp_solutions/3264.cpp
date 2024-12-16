typedef pair<int, int> P;
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<P, vector<P>, greater<P>> pq;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            pq.push({nums[i], i});
        }
        while (k--) {
            P p = pq.top();
            pq.pop();
            pq.push({p.first * multiplier, p.second});
        }
        while (!pq.empty()) {
            P p = pq.top();
            pq.pop();
            nums[p.second] = p.first;
        }
        return nums;
    }
};
