class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        
        priority_queue<int, vector<int>, greater<int>> pq;
        int index = 0;
        int n = events.size();
        int cnt = 0;
        for (int i = 1; i <= 100000; ++i) {
            while (index < n && events[index][0] == i) {
                pq.push(events[index][1]);
                index++;
            }
            while (!pq.empty() && pq.top() < i) {
                pq.pop();
            }
            if (!pq.empty()) {
                pq.pop();
                cnt++;
            }
        }
        return cnt;
    }
};