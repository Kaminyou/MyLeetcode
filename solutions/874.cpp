class Solution {
public:
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x = 0;
        int y = 0;
        int directionIdx = 0;
        int res = 0;
        unordered_set<int> obstacleHash;
        for (auto& obstacle : obstacles) {
            obstacle[0] += 30000;
            obstacle[1] += 30000;
            obstacleHash.insert((obstacle[0] << 16) + obstacle[1]);
        }
        for (auto& command : commands) {
            if (command == -2) {
                directionIdx = (directionIdx - 1 + 4) % 4;
            }
            else if (command == -1) {
                directionIdx = (directionIdx + 1) % 4;
            }
            else {
                for (int i = 0; i < command; ++i) {
                    int next = ((x + directions[directionIdx].first + 30000) << 16) + (y + directions[directionIdx].second + 30000);
                    if (obstacleHash.find(next) != obstacleHash.end()) break;
                    x += directions[directionIdx].first;
                    y += directions[directionIdx].second;
                    res = max(res, x * x + y * y);
                }
            }
        }
        return res;
    }
};