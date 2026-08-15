class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        int m = units.size();
        int n = units[0].size();
        if (n == 1) {
            long long sum = 0;
            for (int i = 0; i < m; ++i) sum += units[i][0];
            return sum;
        }
        vector<vector<int>> lastTwo(m, vector<int>(2, INT_MAX));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (units[i][j] <= lastTwo[i][1]) {
                    lastTwo[i][0] = lastTwo[i][1];
                    lastTwo[i][1] = units[i][j];
                }
                else if (units[i][j] <= lastTwo[i][0]) {
                    lastTwo[i][0] = units[i][j];
                }
            }
        }
        int smallest = INT_MAX;
        long long sum = 0;
        for (int i = 0; i < m; ++i) {
            smallest = min(smallest, lastTwo[i][0]);
            sum += lastTwo[i][0];
        }
        sum -= smallest;
        for (int i = 0; i < m; ++i) {
            smallest = min(smallest, lastTwo[i][1]);
        }
        sum += smallest;
        return sum;
    }
};

