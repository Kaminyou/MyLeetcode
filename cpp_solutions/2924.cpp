class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> inDegrees(n, 0);
        for (auto& edge : edges) {
            inDegrees[edge[1]]++;
        }
        int cnt = 0;
        int team = -1;
        for (int i = 0; i < n; ++i) {
            if (inDegrees[i] == 0) {
                team = i;
                cnt++;
            }
        }
        if (cnt != 1) return -1;
        return team;
    }
};
