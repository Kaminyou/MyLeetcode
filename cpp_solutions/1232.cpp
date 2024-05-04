class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        sort(coordinates.begin(), coordinates.end());
        // (y2 - y1) / (x2 - x1) == (y3 - y2) / (x3 - x2)
        // => (y2 - y1) * (x3 - x2) == (y3 - y2) * (x2 - x1)
        int n = coordinates.size();
        if (n < 3) return true;
        for (int i = 1; i < n - 1; ++i) {
            int left = (coordinates[i][1] - coordinates[i - 1][1]) * (coordinates[i + 1][0] - coordinates[i][0]);
            int right = (coordinates[i + 1][1] - coordinates[i][1]) * (coordinates[i][0] - coordinates[i - 1][0]);
            if (left != right) return false;
        }
        return true;
    }
};