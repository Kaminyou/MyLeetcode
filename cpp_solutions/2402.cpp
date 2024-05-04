typedef pair<long long, int> P;
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<int> count(n, 0);
        
        priority_queue<P, vector<P>, greater<P>> pq;
        set<int> availableRoom;
        for (int i = 0; i < n; ++i) availableRoom.insert(i);
        
        long long basetime = 0;
        for (auto& meeting : meetings) {
            long long duration = meeting[1] - meeting[0];
            basetime = max(basetime, (long long)meeting[0]);
            
            while (!pq.empty() && pq.top().first <= basetime) {
                auto [t, currRoomIdx] = pq.top();
                pq.pop();
                availableRoom.insert(currRoomIdx);
            }
            
            if (!availableRoom.empty()) {
                int roomIdx = *(availableRoom.begin());
                availableRoom.erase(roomIdx);
                count[roomIdx]++;
                pq.push({basetime + duration, roomIdx});
            }
            else {
                auto [t, roomIdx] = pq.top();
                pq.pop();
                availableRoom.insert(roomIdx);
                basetime = t;
                
                // add room with the saming ending time
                while (!pq.empty() && pq.top().first <= basetime) {
                    auto [t, roomIdx] = pq.top();
                    pq.pop();
                    availableRoom.insert(roomIdx);
                }
                
                // get an empty room
                int currRoomIdx = *(availableRoom.begin());
                availableRoom.erase(currRoomIdx);
                count[roomIdx]++;
                pq.push({basetime + duration, currRoomIdx});
            }
        }
        
        int res = -1;
        int maxUse = 0;
        for (int i = 0; i < n; ++i) {
            if (count[i] > maxUse) {
                maxUse = count[i];
                res = i;
            }
        }
        
        return res;
    }
};
