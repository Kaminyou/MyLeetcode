class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> starts(26, INT_MAX);
        vector<int> ends(26, INT_MIN);
        int n = s.size();

        for (int i = 0; i < n; ++i) {
            int c = s[i] - 'a';
            starts[c] = min(starts[c], i);
            ends[c] = max(ends[c], i);
        }

        vector<pair<int, int>> intervals;

        for (int i = 0; i < 26; ++i) {
            int iS = starts[i];
            if (iS == INT_MAX) continue;

            int trueE = ends[i];
            bool fail = false;

            for (int j = iS; j <= trueE; ++j) {
                int c = s[j] - 'a';

                if (starts[c] < iS) {
                    fail = true;
                    break;
                }

                trueE = max(trueE, ends[c]);
            }

            if (!fail) {
                intervals.push_back({trueE, iS});
            }
        }
        sort(intervals.begin(), intervals.end());
        int m = intervals.size();
        vector<int> dp(m, 1);
        vector<int> sumLength(m, 0);
        vector<vector<pair<int, int>>> dpPaths(m);
        for (int i = 0; i < m; ++i) {
            sumLength[i] = intervals[i].first - intervals[i].second + 1;
            dpPaths[i] = {intervals[i]};
        }
        for (int i = 0; i < m; ++i) {
            if (i >= 1) {
                if (dp[i - 1] == dp[i] && sumLength[i - 1] < sumLength[i]) {
                    sumLength[i] = sumLength[i - 1];
                    dpPaths[i] = dpPaths[i - 1]; 
                }
                if (dp[i - 1] > dp[i]) {
                    dp[i] = dp[i - 1];
                    sumLength[i] = sumLength[i - 1];
                    dpPaths[i] = dpPaths[i - 1]; 
                }
            }
            for (int j = 0; j < i; ++j) {
                if (intervals[j].first < intervals[i].second) {
                    int curLength = intervals[i].first - intervals[i].second + 1;
                    if (dp[j] + 1 == dp[i] && sumLength[j] + curLength < sumLength[i]) {
                        sumLength[i] = sumLength[j] + curLength;
                        dpPaths[i] = dpPaths[j];
                        dpPaths[i].push_back(intervals[i]);
                    }
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        sumLength[i] = sumLength[j] + curLength;
                        dpPaths[i] = dpPaths[j];
                        dpPaths[i].push_back(intervals[i]);
                    }
                }
            }
        }
        vector<string> res;
        for (auto& interval : dpPaths[m - 1]) {
            int start = interval.second;
            int end = interval.first;
            res.push_back(s.substr(start, end - start + 1));
        }
        return res;
    }
};

