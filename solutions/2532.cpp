typedef pair<int, int> PT; // {time, i}
class Solution {
public:
    int findCrossingTime(int n, int k, vector<vector<int>>& time) {
        priority_queue<PT> bridgeLeftPQ;
        priority_queue<PT> bridgeRightPQ;
        priority_queue<PT, vector<PT>, greater<PT>> oldPT; // left
        priority_queue<PT, vector<PT>, greater<PT>> newPT; // right
        
        int currentTime = 0;
        for (int i = 0; i < k; ++i) {
            oldPT.push({currentTime, i});
        }
        while (n) {
            // move available workers to the left side of bridge
            while (!oldPT.empty() && oldPT.top().first <= currentTime) {
                PT p = oldPT.top();
                oldPT.pop();
                int idx = p.second;
                bridgeLeftPQ.push({time[idx][0] + time[idx][2], idx});
            }
            
            // move available workers to the right side of bridge
            while (!newPT.empty() && newPT.top().first <= currentTime) {
                PT p = newPT.top();
                newPT.pop();
                int idx = p.second;
                bridgeRightPQ.push({time[idx][0] + time[idx][2], idx});
            }
            
            // pick one from bridge
            if (!bridgeRightPQ.empty()) {
                int idx = bridgeRightPQ.top().second;
                bridgeRightPQ.pop();
                currentTime += time[idx][2];
                oldPT.push({currentTime + time[idx][3], idx});
                n--;
            }
            else if (!bridgeLeftPQ.empty() && n > bridgeRightPQ.size() + newPT.size()) {
                int idx = bridgeLeftPQ.top().second;
                bridgeLeftPQ.pop();
                currentTime += time[idx][0];
                newPT.push({currentTime + time[idx][1], idx});
            }
            else {
                int minTime = INT_MAX;
                if (!oldPT.empty()) {
                    PT p = oldPT.top();
                    minTime = min(minTime, p.first);
                }

                if (!newPT.empty()) {
                    PT p = newPT.top();
                    minTime = min(minTime, p.first);
                }
                currentTime = minTime;
            }
        }
        return currentTime;
    }
};