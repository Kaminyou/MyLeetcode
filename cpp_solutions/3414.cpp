class Solution {
public:
    static bool compare(const vector<int>& v1, const vector<int>& v2) {
        if (v1[1] != v2[1]) return v1[1] < v2[1];
        return v1[0] < v2[0];
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 0) return {};

        for (int i = 0; i < n; ++i) intervals[i].push_back(i);

        sort(intervals.begin(), intervals.end(), compare);

        vector<int> reverseIdx(n, -1);
        for (int i = 0; i < n; ++i) {
            reverseIdx[i] = intervals[i][3];
        }

        vector<int> ends;
        vector<vector<long long>> dp(n, vector<long long>(4, 0));

        vector<vector<vector<int>>> ids(n, vector<vector<int>>(4));

        auto update = [&](int i, int j, long long value,
                          vector<int> candidate) {
            sort(candidate.begin(), candidate.end());

            if (value > dp[i][j] ||
                (value == dp[i][j] && candidate < ids[i][j])) {
                dp[i][j] = value;
                ids[i][j] = candidate;
            }
        };

        for (int i = 0; i < n; ++i) {
            update(i, 0, intervals[i][2], {reverseIdx[i]});

            if (i >= 1) {
                update(i, 0, dp[i - 1][0], ids[i - 1][0]);
            }

            ends.push_back(intervals[i][1]);
        }

        for (int j = 1; j < 4; ++j) {
            for (int i = 0; i < n; ++i) {
                update(i, j, dp[i][j - 1], ids[i][j - 1]);

                if (i >= 1) {
                    update(i, j, dp[i - 1][j], ids[i - 1][j]);
                }

                auto it = lower_bound(
                    ends.begin(), ends.begin() + i, intervals[i][0]
                );

                if (it != ends.begin()) {
                    --it;
                    int k = it - ends.begin();

                    vector<int> candidate = ids[k][j - 1];
                    candidate.push_back(reverseIdx[i]);

                    update(
                        i, j,
                        dp[k][j - 1] + (long long)intervals[i][2],
                        candidate
                    );
                } else {
                    update(i, j, intervals[i][2], {reverseIdx[i]});
                }
            }
        }

        return ids[n - 1][3];
    }
};
