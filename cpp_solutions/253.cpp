class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        
        int res = 0;
        for (auto& interval : intervals) {
            while (!pq.empty() && pq.top() <= interval[0]) pq.pop();
            pq.push(interval[1]);
            res = max(res, static_cast<int>(pq.size()));
        }
        return res;
    }
};