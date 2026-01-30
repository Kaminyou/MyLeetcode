class Solution {
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        unordered_map<string, int> s2node;
        int node = 0;
        for (int i = 0; i < 26; ++i) {
            string s = "";
            s.push_back(i + 'a');
            s2node[s] = node;
            node++;
        }
        for (auto& s : original) {
            if (s2node.count(s)) continue;
            s2node[s] = node;
            node++;
        }
        for (auto& s : changed) {
            if (s2node.count(s)) continue;
            s2node[s] = node;
            node++;
        }
        vector<vector<long long>> dp(node, vector<long long>(node, LLONG_MAX / 2));
        int m = original.size();
        for (int i = 0; i < node; ++i) dp[i][i] = 0;
        for (int i = 0; i < m; ++i) {
            int from = s2node[original[i]];
            int to = s2node[changed[i]];
            dp[from][to] = min(dp[from][to], (long long)cost[i]);
        }
        for (int k = 0; k < node; ++k) {
            for (int i = 0; i < node; ++i) {
                for (int j = 0; j < node; ++j) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }

        unordered_set<int> lengths;
        for (auto& [k, v] : s2node) {
            lengths.insert(k.size());
        }
        
        int n = source.size();
        vector<long long> dp2(n + 1, LLONG_MAX / 2);
        dp2[0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int length : lengths) {
                int j = i - length + 1;
                if (j < 0) continue;
                string sSub = source.substr(j, length);
                string tSub = target.substr(j, length);
                if (!s2node.count(sSub)) continue;
                if (!s2node.count(tSub)) continue;
                long long currCost = dp[s2node[sSub]][s2node[tSub]];
                dp2[i + 1] = min(dp2[i + 1], dp2[j] + currCost);
            }
        }

        return dp2[n] == LLONG_MAX / 2 ? -1 : dp2[n];
    }
};
