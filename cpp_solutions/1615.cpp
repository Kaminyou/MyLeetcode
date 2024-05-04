class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degrees(n, 0);
        unordered_map<int, unordered_set<int>> mp;
        for (auto& road : roads) {
            degrees[road[0]]++;
            degrees[road[1]]++;
            mp[road[0]].insert(road[1]);
            mp[road[1]].insert(road[0]);
        }
        int maxValue = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int indegreeI = degrees[i];
                int indegreeJ = degrees[j];
                int total = indegreeI + indegreeJ;
                if (mp[i].count(j)) total--;
                maxValue = max(maxValue, total);
            }
        }
        return maxValue;
    }
};