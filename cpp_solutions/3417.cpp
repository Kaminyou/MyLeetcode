class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        int index = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<int> res;
        while (index < m * n) {
            int h = index / n;
            int w = index % n;
            if (h & 1) w = (n - w - 1);
            res.push_back(grid[h][w]);
            index += 2;
        }
        return res;
    }
};
