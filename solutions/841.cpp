class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        queue<int> q;
        int cnt = n;
        q.push(0);
        visited[0] = true;
        n--;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto& neighbor : rooms[node]) {
                if (visited[neighbor]) continue;
                q.push(neighbor);
                visited[neighbor] = true;
                n--;
            }
        }
        return n == 0;
    }
};