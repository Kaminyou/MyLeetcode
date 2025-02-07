class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ball2color;
        unordered_map<int, int> colors;
        int diffColor = 0;
        int n = queries.size();
        vector<int> res(n, 0);
        for (int i = 0; i < n; ++i) {
            int ball = queries[i][0];
            int color = queries[i][1];
            int originalColor = ball2color[ball];
            ball2color[ball] = color;
            if (originalColor != 0) {
                colors[originalColor]--;
                if (colors[originalColor] == 0) diffColor--;
            }
            colors[color]++;
            if (colors[color] == 1) diffColor++;
            res[i] = diffColor;
        }
        return res;
    }
};
