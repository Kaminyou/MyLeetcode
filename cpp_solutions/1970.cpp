class Solution {
public:
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool criteria(int idx, int row, int col, vector<vector<int>>& cells) {
        // not able to pass
        vector<vector<bool>> valid(row, vector<bool>(col, true));
        for (int i = 0; i <= idx; ++i) {
            int r = cells[i][0] - 1;
            int c = cells[i][1] - 1;
            valid[r][c] = false;
        }
        bool canReach = false;
        queue<pair<int, int>> q;
        for (int i = 0; i < col; ++i) {
            if (valid[0][i]) {
                q.push({0, i});
                valid[0][i] = false;
            }
        }
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for (auto& direction : directions) {
                int neighborR = r + direction.first;
                int neighborC = c + direction.second;
                if (neighborR < 0 || neighborR >= row || neighborC < 0 || neighborC >= col) continue;
                if (!valid[neighborR][neighborC]) continue;
                q.push({neighborR, neighborC});
                valid[neighborR][neighborC] = false;
                if (neighborR == row - 1) canReach = true;
            }
        }
        return !canReach;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int left = 0;
        int right = row * col - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (criteria(mid, row, col, cells)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};