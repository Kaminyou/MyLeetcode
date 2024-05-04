class Solution {
public:
    long long dp(int i, int j, vector<int>& robot, vector<int>& factories, vector<vector<long long>>& memo) {
        if (i == robot.size()) return 0;
        if (j == factories.size()) return LLONG_MAX / 2;
        if (memo[i][j] != -1) return memo[i][j];
        long long use = abs(robot[i] - factories[j]) + dp(i + 1, j + 1, robot, factories, memo);
        long long notUse = dp(i, j + 1, robot, factories, memo);
        return memo[i][j] = min(use, notUse);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        vector<int> factories;
        for (auto& singleFactory : factory) {
            int idx = singleFactory[0];
            int cnt = singleFactory[1];
            for (int i = 0; i < cnt; ++i) factories.push_back(idx);
        }
        vector<vector<long long>> memo(robot.size() + 1, vector<long long>(factories.size() + 1, -1));
        return dp(0, 0, robot, factories, memo);
    }
};