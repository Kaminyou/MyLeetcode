class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        int sum = 0;
        for (int i = 1; i < n; ++i) {
            int diff = heights[i] - heights[i - 1];
            if (diff <= 0) continue;
            pq.push(diff);
            if (pq.size() > ladders) {
                int temp = pq.top();
                pq.pop();
                sum += temp;
            }
            if (sum > bricks) return i - 1;
        }
        return n - 1;
    }
};

