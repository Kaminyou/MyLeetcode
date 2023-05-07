class Solution {
public:
    int dfs(int n, int node, vector<int>& cost, int& res) {
        int left = node * 2;
        int right = node * 2 + 1;
        if (left > n || right > n) return cost[node - 1];
        int leftVal = dfs(n, left, cost, res);
        int rightVal = dfs(n, right, cost, res);
        res += abs(leftVal - rightVal);
        cost[node - 1] += max(leftVal, rightVal);
        return cost[node - 1];
    }
    int minIncrements(int n, vector<int>& cost) {
        int res = 0;
        dfs(n, 1, cost, res);
        return res;
    }
};