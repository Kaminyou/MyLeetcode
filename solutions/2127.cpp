class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<int> inDegrees(n, 0);
        for (int i = 0; i < n; ++i) {
            inDegrees[favorite[i]]++;
        }
        
        vector<bool> visited(n, false);
        vector<int> depth(n, 1);
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (inDegrees[i] == 0) {
                q.push(i);
                visited[i] = true;
            }
        }
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            int next = favorite[node];
            inDegrees[next]--;
            if (inDegrees[next] == 0) {
                q.push(next);
                visited[next] = true;
            }
            depth[next] = depth[node] + 1;
        }

        int maxSize = 0;
        int twoNodeCircleSize = 0;
        for (int i = 0; i < n; ++i) {
            if (visited[i] == false) {
                int cnt = 1;
                int current = favorite[i];
                visited[i] = true;
                while (current != i) {
                    cnt++;
                    visited[current] = true;
                    current = favorite[current];
                }
                
                if (cnt >= 3) {
                    maxSize = max(maxSize, cnt);
                }
                else if (cnt == 2) {
                    twoNodeCircleSize += depth[i] + depth[favorite[i]];
                }
            }
        }
        return max(maxSize, twoNodeCircleSize);
    }
};
