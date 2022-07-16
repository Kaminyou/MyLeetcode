class Solution {
public:
    int M;
    int N;
    int size;
    int position2idx(int x, int y) {
        return x * N + y;
    }
    vector<int> idx2position(int idx) {
        int x = idx / N;
        int y = idx % N;
        return {x, y};
    }
    int dp(int current, unordered_map<int, int>& memo) {
        if (current == 0) {
            return 0;
        }
        if (memo.find(current) != memo.end()) return memo[current];
        int res = INT_MAX;
        for (int i = 0; i < size; ++i) {
            if ((current & (1 << i)) == (1 << i)) {
                int nextState = current;
                vector<int> position = idx2position(i);
                int x = position[0];
                int y = position[1];
                for (int ii = 0; ii < M; ++ii) {
                    int idx = position2idx(ii, y);
                    nextState &= ~(1 << idx);
                }
                for (int j = 0; j < N; ++j) {
                    int idx = position2idx(x, j);
                    nextState &= ~(1 << idx);
                }
                res = min(res, dp(nextState, memo) + 1);
            }
        }
        return memo[current] = res;
    }
    int removeOnes(vector<vector<int>>& grid) {
        M = grid.size();
        N = grid[0].size();
        size = M * N;
        int state = 0;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j]) state |= (1 << (position2idx(i, j)));
            }
        }
        unordered_map<int, int> memo;
        return dp(state, memo);
    }
};