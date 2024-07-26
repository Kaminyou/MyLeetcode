class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // floyd-warshall
        vector<vector<int>> distances(n, vector<int>(n, INT_MAX / 2));
        for (int i = 0; i < n; i++) {
            distances[i][i] = 0;
        }
        for (auto edge : edges) {
            distances[edge[0]][edge[1]] = edge[2];
            distances[edge[1]][edge[0]] = edge[2];
        }
        
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    distances[i][j] = min(distances[i][j], distances[i][k] + distances[k][j]);
                }
            }
        }
        
        // count city
        vector<int> counts;
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (distances[i][j] != 0 && distances[i][j] <= distanceThreshold) count++;
            }
            counts.push_back(count);
        }
        
        
        int minCity = INT_MAX;
        int ans = -1;
        for (int i = 0; i < n; i++) {
            if (counts[i] <= minCity) {
                ans = i;
                minCity = counts[i];
            }
        }
        return ans;
    }
};
