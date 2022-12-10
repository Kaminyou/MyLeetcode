class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        vector<vector<int>> neighbors(n);
        for (auto& edge : edges) {
            neighbors[edge[0]].push_back(vals[edge[1]]);
            neighbors[edge[1]].push_back(vals[edge[0]]);
        }
        
        for (int i = 0; i < n; ++i) {
            sort(neighbors[i].begin(), neighbors[i].end(), greater<int>());
        }
        
        int maxVal = INT_MIN;
        for (int i = 0; i < n; ++i) {
            int currentVal = vals[i];
            int n = neighbors[i].size();
            for (int j = 0; j < min(n, k); ++j) {
                if (neighbors[i][j] < 0) break;
                currentVal += neighbors[i][j];
            }
            maxVal = max(maxVal, currentVal);
        }
        return maxVal;
    }
};