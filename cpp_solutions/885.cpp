class Solution {
public:
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> res;
        int index = 2;
        int directionIdx = 0;
        int x = rStart;
        int y = cStart;
        while (res.size() < rows * cols) {
            int move = index / 2;
            while (move--) {
                if (x >= 0 && x < rows && y >= 0 && y < cols) res.push_back({x, y});
                x += directions[directionIdx].first;
                y += directions[directionIdx].second;
            }
            index++;
            directionIdx = (directionIdx + 1) % 4;
        }
        return res;
    }
};
