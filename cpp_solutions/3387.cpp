class Solution {
public:
    unordered_map<string, double> dfs(string initialCurrency, double current, vector<vector<string>>& pairs, vector<double>& rates) {
        unordered_map<string, unordered_map<string, double>> graph;
        int n = pairs.size();
        for (int i = 0; i < n; ++i) {
            graph[pairs[i][0]][pairs[i][1]] = rates[i];
            graph[pairs[i][1]][pairs[i][0]] = 1 / rates[i];
        }
        unordered_set<string> visited;
        unordered_map<string, double> res;

        res[initialCurrency] = current;
        visited.insert(initialCurrency);
        queue<string> q;
        q.push(initialCurrency);
        while (!q.empty()) {
            string node = q.front();
            q.pop();
            for (auto& [neighbor, rate] : graph[node]) {
                if (visited.find(neighbor) != visited.end()) continue;
                visited.insert(neighbor);
                q.push(neighbor);
                res[neighbor] = res[node] * rate;
            }
        }
        return res;
    }
    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
        double res = 1.0;
        unordered_map<string, double> firstRd = dfs(initialCurrency, 1.0, pairs1, rates1);
        for (auto& [currency, amount] : firstRd) {
            unordered_map<string, double> secondRd = dfs(currency, amount, pairs2, rates2);
            for (auto& [currency2, amount2] : secondRd) {
                if (currency2 == initialCurrency) res = max(res, amount2);
            }
        }
        return res;
    }
};
