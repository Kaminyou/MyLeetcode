class Solution {
public:
    vector<int> topological(vector<vector<int>>& orders, int k) {
        vector<int> inDegress(k, 0);
        vector<vector<int>> adjacency(k);
        for (auto& order : orders) {
            inDegress[order[1] - 1]++;
            adjacency[order[0] - 1].push_back(order[1] - 1);
        }
        
        queue<int> q;
        for (int i = 0; i < k; ++i) {
            if (inDegress[i] == 0) q.push(i);
        }
        vector<int> res;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            res.push_back(node);
            for (auto& neighbor : adjacency[node]) {
                inDegress[neighbor]--;
                if (inDegress[neighbor] == 0) q.push(neighbor);
            }
        }
        return res;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> rowOrder = topological(rowConditions, k);
        vector<int> colOrder = topological(colConditions, k);
        if (rowOrder.size() != k) return {};
        if (colOrder.size() != k) return {};
        
        vector<int> rowPosition(k, 0);
        vector<int> colPosition(k, 0);
        for (int i = 0; i < k; ++i) {
            rowPosition[rowOrder[i]] = i;
            colPosition[colOrder[i]] = i;
        }
        vector<vector<int>> matrix(k, vector<int>(k, 0));
        for (int i = 0; i < k; ++i) {
            matrix[rowPosition[i]][colPosition[i]] = i + 1;
        }
        return matrix;
    }
};
