class Solution {
public:
    int upperbound(vector<int>& arr, int x) {
        int left = 0;
        int right = arr.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] > x) right = mid;
            else left = mid + 1;
        }
        return left;
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        unordered_map<int, vector<int>> guardInRow;
        unordered_map<int, vector<int>> guardInCol;
        unordered_map<int, vector<int>> wallInRow;
        unordered_map<int, vector<int>> wallInCol;
        vector<vector<bool>> unavailable(m, vector<bool>(n, false));
        for (auto guard : guards) {
            guardInRow[guard[0]].push_back(guard[1]);
            guardInCol[guard[1]].push_back(guard[0]);
            unavailable[guard[0]][guard[1]] = true;
        }
        for (auto wall : walls) {
            wallInRow[wall[0]].push_back(wall[1]);
            wallInCol[wall[1]].push_back(wall[0]);
            unavailable[wall[0]][wall[1]] = true;
        }
        
        for (auto& element : guardInRow) sort(element.second.begin(), element.second.end());
        for (auto& element : guardInCol) sort(element.second.begin(), element.second.end());
        for (auto& element : wallInRow) sort(element.second.begin(), element.second.end());
        for (auto& element : wallInCol) sort(element.second.begin(), element.second.end());
        
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // is guard or wall
                if (unavailable[i][j]) continue;
                
                // check left and right
                if (guardInRow.find(i) != guardInRow.end()) {
                    if (wallInRow.find(i) == wallInRow.end()) {
                        // has guard but no wall
                        continue;
                    }
                    else {
                        // has guard and wall
                        int rG = upperbound(guardInRow[i], j);
                        int lG = rG - 1;

                        // only left guard
                        if (rG == guardInRow[i].size()) {
                            // no wall > guard
                            int index = upperbound(wallInRow[i], guardInRow[i][lG]);
                            if (index == wallInRow[i].size()) {
                                continue;
                            }
                            // wall > col
                            if (wallInRow[i][index] > j) continue;
                            
                        }
                        // only right
                        else if (lG == -1) {
                            // find wall right to the curr pos
                            int index = upperbound(wallInRow[i], j);
                            if (index == wallInRow[i].size() || wallInRow[i][index] > guardInRow[i][rG]) {
                                continue;
                            }
                        }
                        // middle
                        else {
                            // more than left guard
                            int indexRightToLeftGuard = upperbound(wallInRow[i], guardInRow[i][lG]);
                            int indexRightToCurrCol = upperbound(wallInRow[i], j);
                            if (indexRightToLeftGuard == wallInRow[i].size() || indexRightToCurrCol == wallInRow[i].size()) continue;
                            if (wallInRow[i][indexRightToLeftGuard] > j || wallInRow[i][indexRightToCurrCol] > guardInRow[i][rG]) continue;
                        }
                    }
                }
                // check up and down
                if (guardInCol.find(j) != guardInCol.end()) {
                    if (wallInCol.find(j) == wallInCol.end()) {
                        // has guard but no wall
                        continue;
                    }
                    else {
                        // has guard and wall
                        // down > up
                        int downG = upperbound(guardInCol[j], i);
                        int upG = downG - 1;

                        // only up guard
                        if (downG == guardInCol[j].size()) {
                            // no wall > guard
                            int index = upperbound(wallInCol[j], guardInCol[j][upG]);
                            if (index == wallInCol[j].size()) {
                                continue;
                            }
                            if (wallInCol[j][index] > i) continue;
                        }
                        // only down
                        else if (upG == -1) {
                            // find wall down to the curr pos
                            int index = upperbound(wallInCol[j], i);
                            if (index == wallInCol[j].size() || wallInCol[j][index] > guardInCol[j][downG]) {
                                continue;
                            }
                        }
                        // middle
                        else {
                            // more than up guard
                            int indexDownToUpGuard = upperbound(wallInCol[j], guardInCol[j][upG]);
                            int indexDownToCurrCol = upperbound(wallInCol[j], i);
                            if (indexDownToUpGuard == wallInCol[j].size() || indexDownToCurrCol == wallInCol[j].size()) continue;
                            if (wallInCol[j][indexDownToUpGuard] > i || wallInCol[j][indexDownToCurrCol] > guardInCol[j][downG]) continue;
                        }
                    }
                }
                res += 1;
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<char>> grid(m, vector<char>(n, 'E'));
        for (auto& wall : walls) {
            grid[wall[0]][wall[1]] = 'W';
        }
        for (auto& guard : guards) {
            grid[guard[0]][guard[1]] = 'G';
        }
        for (auto& guard : guards) {
            for (auto& direction : directions) {
                int x = guard[0];
                int y = guard[1];
                while (true) {
                    int nextX = x + direction.first;
                    int nextY = y + direction.second;
                    if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n) break;
                    if (grid[nextX][nextY] == 'W') break;
                    if (grid[nextX][nextY] == 'G') break;
                    grid[nextX][nextY] = 'P';
                    x = nextX;
                    y = nextY;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 'E') res++;
            }
        }
        return res;
    }
};
