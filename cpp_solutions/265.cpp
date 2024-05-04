class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int m = costs.size();
        int n = costs[0].size();
        
        for (int i = 1; i < m; i++) {
            // find the first and the second min
            int firstMin = -1;
            int secondMin = -1;
            for (int j = 0; j < n; j++) {
                int cost = costs[i - 1][j];
                if (firstMin == -1 || cost < costs[i - 1][firstMin]) {
                    secondMin = firstMin;
                    firstMin = j;
                }
                else if (secondMin == -1 || cost < costs[i - 1][secondMin]) {
                    secondMin = j;
                }
            }
            
            for (int j = 0; j < n; j++) {
                if (j != firstMin) costs[i][j] = costs[i - 1][firstMin] + costs[i][j];
                else costs[i][j] = costs[i - 1][secondMin] + costs[i][j];
            }
        }
        return *min_element(costs[m - 1].begin(), costs[m - 1].end());
    }
};