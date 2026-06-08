class Solution {
public:
    struct Node {
        long long cnt;
        long long sum;
    };
    Node memo[20][3][11][11];
    bool vis[20][3][11][11];
    Node _dfs(string& s, int pos, int length, bool tight, int prev2, int prev1) {
        if (pos == s.size()) return Node(1, 0);
        if (!tight && vis[pos][length][prev2][prev1]) return memo[pos][length][prev2][prev1];
        Node res = Node(0, 0);
        int limit = tight ? (s[pos] - '0') : 9;
        for (int d = 0; d <= limit; ++d) {
            bool ntight = tight && (d == limit);
            if (length == 0) {
                if (d == 0) {
                    Node child = _dfs(s, pos + 1, 0, ntight, 10, 10);
                    res.cnt += child.cnt;
                    res.sum += child.sum;
                }
                else {
                    Node child = _dfs(s, pos + 1, 1, ntight, 10, d);
                    res.cnt += child.cnt;
                    res.sum += child.sum;
                }
            }
            else if (length == 1) {
                Node child = _dfs(s, pos + 1, 2, ntight, prev1, d);
                res.cnt += child.cnt;
                res.sum += child.sum;
            }
            else {
                int add = 0;
                if ((prev1 > prev2 && prev1 > d) || (prev1 < prev2 && prev1 < d)) add = 1;
                Node child = _dfs(s, pos + 1, 2, ntight, prev1, d);
                res.cnt += child.cnt;
                res.sum += child.sum + child.cnt * add;
            }
        }
        if (!tight) {
            vis[pos][length][prev2][prev1] = true;
            memo[pos][length][prev2][prev1] = res;
        }
        return res;
    }
    long long dfs(long long num) {
        if (num < 0) return 0;
        memset(vis, 0, sizeof(vis));
        string s = to_string(num);
        Node res = _dfs(s, 0, 0, true, 10, 10);
        return res.sum;
    }
    long long totalWaviness(long long num1, long long num2) {
        return dfs(num2) - dfs(num1 - 1);
    }
};
