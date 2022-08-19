class Solution {
public:
    static bool compare(vector<int>& p1, vector<int>& p2) {
        if (p1[0] == p2[0]) return p1[1] < p2[1];
        return p1[0] < p2[0];
    }
    int cross(vector<int> o, vector<int> p1, vector<int> p2) {
        // OP1 x OP2
        return (p1[0] - o[0]) * (p2[1] - o[1]) - (p1[1] - o[1]) * (p2[0] - o[0]);
    }
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        sort(trees.begin(), trees.end(), compare);
        vector<vector<int>> upper;
        vector<vector<int>> lower;
        
        int n = trees.size();
        for (int i = 0; i < n; ++i) {
            while (lower.size() >= 2 && cross(lower[lower.size() - 2], lower[lower.size() - 1], trees[i]) < 0) lower.pop_back();
            lower.push_back(trees[i]);
        }
        
        for (int i = n - 1; i >= 0; --i) {
            while (upper.size() >= 2 && cross(upper[upper.size() - 2], upper[upper.size() - 1], trees[i]) < 0) upper.pop_back();
            upper.push_back(trees[i]);
        }

        for (auto point : upper) {
            lower.push_back(point);
        }
        sort(lower.begin(), lower.end(), compare);
        vector<vector<int>> res;
        int m = lower.size();
        for (int i = 0; i < m; ++i) {
            if (i == 0) res.push_back(lower[i]);
            else {
                if ((lower[i][0] == lower[i - 1][0]) && (lower[i][1] == lower[i - 1][1])) continue;
                res.push_back(lower[i]);
            }
        }
        return res;
    }
};