class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        // x
        vector<pair<int, int>> xs;
        vector<pair<int, int>> ys;
        for (auto& rectangle: rectangles) {
            xs.push_back({rectangle[0], rectangle[2]});
            ys.push_back({rectangle[1], rectangle[3]});
        }
        sort(xs.begin(), xs.end());
        sort(ys.begin(), ys.end());

        int gap = 0;
        int m = xs.size();
        int maxEnd = INT_MIN;
        for (int i = 0; i < m - 1; ++i) {
            maxEnd = max(maxEnd, xs[i].second);
            if (xs[i + 1].first >= maxEnd) gap++;
        }
        if (gap >= 2) return true;
        gap = 0;
        maxEnd = INT_MIN;
        for (int i = 0; i < m - 1; ++i) {
            maxEnd = max(maxEnd, ys[i].second);
            if (ys[i + 1].first >= maxEnd) gap++;
        }
        if (gap >= 2) return true;
        return false;
    }
};
