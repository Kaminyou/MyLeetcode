class Solution {
public:
    int M;
    int N;
    int position2idx(int x, int y) {
        return x * N + y;
    }
    pair<int, int> idx2position(int idx) {
        int x = idx / N;
        int y = idx % N;
        return make_pair(x, y);
    }
    string toHash(int idx1, int idx2) {
        return to_string(idx1) + "#" + to_string(idx2);
    }
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool isReachable(int x, int y, int targetX, int targetY, int boxX, int boxY, vector<vector<char>>& grid) {
        grid[boxX][boxY] = '#';
        unordered_set<int> st;
        queue<int> q;
        q.push(position2idx(x, y));
        st.insert(position2idx(x, y));
        
        while (!q.empty()) {
            int currPosition = q.front();
            q.pop();
            auto [currX, currY] = idx2position(currPosition);
            if (currX == targetX && currY == targetY) {
                grid[boxX][boxY] = '.';
                return true;
            }
            for (auto& direction : directions) {
                int nextX = currX + direction.first;
                int nextY = currY + direction.second;
                if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N) continue;
                if (grid[nextX][nextY] != '.') continue;
                int nextIdx = position2idx(nextX, nextY);
                if (st.find(nextIdx) != st.end()) continue;
                
                q.push(nextIdx);
                st.insert(nextIdx);
            }
        }
        grid[boxX][boxY] = '.';
        return false;
    }
    int minPushBox(vector<vector<char>>& grid) {
        M = grid.size();
        N = grid[0].size();
        
        int player;
        int box;
        int target;
        
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == 'S') player = position2idx(i, j);
                else if (grid[i][j] == 'B') box = position2idx(i, j);
                else if (grid[i][j] == 'T') target = position2idx(i, j);
                if (grid[i][j] != '#') grid[i][j] = '.';
            }
        }
        
        unordered_set<string> st;
        queue<pair<int, int>> q;
        q.push(make_pair(box, player));
        
        int res = 0;
        while (!q.empty()) {
            int k = q.size();
            while (k--) {
                auto [currentBox, currentPlayer] = q.front();
                q.pop();
                if (currentBox == target) return res;
                
                auto currentBoxPosition = idx2position(currentBox);
                auto currentPlayerPosition = idx2position(currentPlayer);

                for (auto& direction : directions) {
                    int nextBoxX = currentBoxPosition.first + direction.first;
                    int nextBoxY = currentBoxPosition.second + direction.second;
                    int nextPlayerX = currentBoxPosition.first - direction.first;
                    int nextPlayerY = currentBoxPosition.second - direction.second;
                    if (nextBoxX < 0 || nextBoxX >= M || nextBoxY < 0 || nextBoxY >= N) continue;
                    if (grid[nextBoxX][nextBoxY] == '#') continue;
                    if (nextPlayerX < 0 || nextPlayerX >= M || nextPlayerY < 0 || nextPlayerY >= N) continue;
                    if (grid[nextPlayerX][nextPlayerY] == '#') continue;
                    
                    string nextHash = toHash(position2idx(nextPlayerX, nextPlayerY), position2idx(currentBoxPosition.first, currentBoxPosition.second));
                    if (st.find(nextHash) != st.end()) continue;
                    if (!isReachable(currentPlayerPosition.first,
                                      currentPlayerPosition.second,
                                      nextPlayerX,
                                      nextPlayerY,
                                      currentBoxPosition.first,
                                      currentBoxPosition.second, grid)) continue;
                    
                    q.push(make_pair(position2idx(nextBoxX, nextBoxY),
                                     position2idx(
                                         currentBoxPosition.first,
                                         currentBoxPosition.second
                                     )));
                    st.insert(nextHash);   
                }
            }
            res++;
        }
        return -1;
    }
};