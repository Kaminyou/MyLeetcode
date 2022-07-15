class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int INF = 1e9 + 7;
        vector<vector<int>> distances(k + 2, vector<int>(n, INF));
        distances[0][src] = 0;
        for (int i = 1; i <= k + 1; ++i) {
            distances[i][src] = 0;
            for (auto& flight : flights) {
                distances[i][flight[1]] = min(distances[i][flight[1]], distances[i - 1][flight[0]] + flight[2]);
            }
        }
        return distances[k + 1][dst] == INF ? -1 : distances[k + 1][dst];
    }
};