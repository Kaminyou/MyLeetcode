class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, vector<int>> mpX;
        unordered_map<int, vector<int>> mpY;
        for (auto& building : buildings) {
            mpX[building[0]].push_back(building[1]);
            mpY[building[1]].push_back(building[0]);
        }
        for (auto& [k, v] : mpX) {
            sort(v.begin(), v.end());
        }
        for (auto& [k, v] : mpY) {
            sort(v.begin(), v.end());
        }
        int res = 0;
        for (auto& building : buildings) {
            if (mpX[building[0]][0] == building[1]) continue;
            if (mpX[building[0]].back() == building[1]) continue;
            if (mpY[building[1]][0] == building[0]) continue;
            if (mpY[building[1]].back() == building[0]) continue;
            res++;
        }
        return res;
    }
};
