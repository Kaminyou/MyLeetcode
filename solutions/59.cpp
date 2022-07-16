class Solution {
public:
    int N;
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    void nextPosition(vector<vector<int>>& grid, int& currRow, int& currCol, int& direction) {
        int nextRow = currRow + directions[direction][0];
        int nextCol = currCol + directions[direction][1];
        if (nextRow >= N || nextRow < 0 || nextCol >= N || nextCol < 0 || grid[nextRow][nextCol] != 0) {
            direction = (direction + 1) % 4;
        }
        currRow = currRow + directions[direction][0];
        currCol = currCol + directions[direction][1];
    }
    vector<vector<int>> generateMatrix(int n) {
        N = n;
        vector<vector<int>> grid(n, vector<int>(n, 0));
        int index = 1;
        int currRow = 0;
        int currCol = 0;
        int direction = 0;
        // 0: right; 1:down; 2:left; 3:up
        while (index <= n * n) {
            grid[currRow][currCol] = index;
            nextPosition(grid, currRow, currCol, direction);
            index++;
        }
        return grid;
    }
};