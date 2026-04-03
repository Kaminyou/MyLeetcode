class Solution {
public:
    int dp[100001][2];
    int shoot(int index, int mode, vector<pair<int, int>>& r, vector<int>& walls) {
        int n = r.size();
        if (mode == 0) {
            int leftBound = index == 0 ? INT_MIN : r[index - 1].first + 1;
            auto iter1 = lower_bound(walls.begin(), walls.end(), max(leftBound, r[index].first - r[index].second));
            auto iter2 = upper_bound(walls.begin(), walls.end(), r[index].first);
            return iter2 - iter1;
        }
        else {
            int rightBound = index == n - 1 ? INT_MAX : r[index + 1].first - 1;
            auto iter1 = lower_bound(walls.begin(), walls.end(), r[index].first);
            auto iter2 = upper_bound(walls.begin(), walls.end(), min(rightBound, r[index].first + r[index].second));
            return iter2 - iter1;
        }
    }
    int overlap(int index, vector<pair<int, int>>& r, vector<int>& walls) {
        auto iter1 = lower_bound(walls.begin(), walls.end(), r[index - 1].first);
        auto iter2 = upper_bound(walls.begin(), walls.end(), r[index].first);
        int temp = shoot(index - 1, 1, r, walls) + shoot(index, 0, r, walls) - (iter2 - iter1);
        return max(0, temp);
    }
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        vector<pair<int, int>> r(n);
        for (int i = 0; i < n; ++i) {
            r[i] = {robots[i], distance[i]};
        }
        sort(r.begin(), r.end());
        sort(walls.begin(), walls.end());
        dp[0][0] = shoot(0, 0, r, walls);
        dp[0][1] = shoot(0, 1, r, walls);
        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][0] + shoot(i, 0, r, walls), dp[i - 1][1] + shoot(i, 0, r, walls) - overlap(i, r, walls));
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + shoot(i, 1, r, walls);
        }
        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};
