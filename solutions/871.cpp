class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int index = 0;
        int res = 0;
        int n = stations.size();
        priority_queue<int> pq;
        // add the stations with most fuel each time
        for (; startFuel < target; res++) {
            while (index < n && stations[index][0] <= startFuel) {
                pq.push(stations[index++][1]);
            }
            if (pq.empty()) return -1;
            startFuel += pq.top();
            pq.pop();
        }
        return res;
    }
};