class Solution {
public:
    int N;
    pair<int, int> idx2position(int idx) {
        idx--;
        int x = idx / N;
        int y;
        if (x & 1) {
            y = N - 1 - (idx % N);
        }
        else {
            y = idx % N;
        }
        return {x, y};
    }
    int position2idx(pair<int, int> position) {
        int idx;
        if (position.first & 1) {
            idx = position.first * N + (N - 1 - position.second);
        }
        else {
            idx = position.first * N + position.second;
        }
        idx++;
        return idx;
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        // bfs
        N = board.size();
        reverse(board.begin(), board.end());
        vector<vector<bool>> visited(N, vector<bool>(N, false));
        queue<int> q;
        q.push(position2idx({0, 0}));
        visited[0][0] = true;
        int level = 0;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                int currentIdx = q.front();
                q.pop();
                if (currentIdx == N * N) return level;
                pair<int, int> currentPosition = idx2position(currentIdx);
                for (int j = 1; j <= 6; ++j) {
                    if (currentIdx + j > N * N) break;
                    int nextIdx = currentIdx + j;
                    pair<int, int> nextPosition = idx2position(nextIdx);
                    if (board[nextPosition.first][nextPosition.second] != -1) {
                        nextIdx = board[nextPosition.first][nextPosition.second];
                        nextPosition = idx2position(nextIdx);
                        if (visited[nextPosition.first][nextPosition.second]) continue;
                        q.push(nextIdx);
                        visited[nextPosition.first][nextPosition.second] = true;
                    }
                    else {
                        if (visited[nextPosition.first][nextPosition.second]) continue;
                        q.push(nextIdx);
                        visited[nextPosition.first][nextPosition.second] = true;
                    }
                }
            }
            level++;
        }
        return -1;
    }
};

class Solution {
public:
    pair<int, int> translate(int num, int n) {
        num -= 1;
        bool reverse = false;
        int rr = num / n;
        int cc = num % n;
        if (rr & 1) reverse = true;
        if (reverse) cc = n - cc - 1;
        return {n - rr - 1, cc};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        queue<int> q;
        q.push(1);
        int step = 0;
        while (!q.empty()) {
            int m = q.size();
            while (m--) {
                int cur = q.front();
                pair<int, int> ppp = translate(cur, n);
                if (cur == (n * n)) return step;
                q.pop();
                for (int i = 1; i <= 6; ++i) {
                    int next = cur + i;
                    if (next > n * n) break;
                    pair<int, int> p = translate(next, n);
                    int r = p.first;
                    int c = p.second;
                    if (board[r][c] == -2) continue;
                    else if (board[r][c] == -1) {
                        q.push(next);
                    }
                    else {
                        int nnext = board[r][c];
                        q.push(nnext);
                    }
                    board[r][c] = -2;
                }
            }
            step++;
        }
        return -1;
    }
};

