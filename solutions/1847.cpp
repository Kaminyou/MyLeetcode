class Solution {
public:
    static bool compare(const vector<int>& v1, const vector<int>& v2) {
        if (v1[1] != v2[1]) return v1[1] > v2[1];
        return v1[0] > v2[0];
    }
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        set<int> roomSet;
        int n = queries.size();
        for (int i = 0; i < n; i++) {
            queries[i].push_back(i);
        }
        sort(queries.begin(), queries.end(), compare);
        sort(rooms.begin(), rooms.end(), compare);
        
        int roomsIdx = 0;
        vector<int> res(n, -1);
        for (int i = 0; i < n; ++i) {
            int querySize = queries[i][1]; 
            int queryRoom = queries[i][0];
            int queryIdx = queries[i][2];
            while (roomsIdx < rooms.size() && rooms[roomsIdx][1] >= querySize) {
                roomSet.insert(rooms[roomsIdx][0]);
                roomsIdx++;
            }
            if (roomSet.size() == 0) continue;
            auto it = roomSet.lower_bound(queryRoom);
            if (it == roomSet.begin()) res[queryIdx] = *it;
            else {
                auto prevIt = prev(it);
                if (it == roomSet.end()) res[queryIdx] = *prevIt;
                else {
                    int diffNext = abs(*it - queryRoom);
                    int diffPrev = abs(*prevIt - queryRoom);
                    if (diffPrev <= diffNext) res[queryIdx] = *prevIt;
                    else res[queryIdx] = *it;
                }
            }
        }
        return res;
    }
};