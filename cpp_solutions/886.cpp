class Solution {
public:
    bool partitionable(int node, vector<vector<int>>& adjacency, vector<int>& colors) {
        queue<int> q;
        q.push(node);
        colors[node] = 1;
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            int currentColor = colors[current];
            int nextColor = 3 - currentColor;
            for (auto& neighbor : adjacency[current]) {
                if (colors[neighbor] != 0 && colors[neighbor] != nextColor) return false;
                if (colors[neighbor] == 0) {
                    q.push(neighbor);
                    colors[neighbor] = nextColor;
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adjacency(n);
        for (auto& dislike : dislikes) {
            adjacency[dislike[0] - 1].push_back(dislike[1] - 1);
            adjacency[dislike[1] - 1].push_back(dislike[0] - 1);
        }
        vector<int> colors(n, 0);
        for (int i = 0; i < n; ++i) {
            if (colors[i] == 0) {
                if (!partitionable(i, adjacency, colors)) return false;
            }
        }
        return true;
    }
};