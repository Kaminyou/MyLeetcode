class Solution {
public:
    int gcd(int x, int y) {
        return y == 0 ? x : gcd(y, x % y);
    }
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int res = 1;
        for (int i = 0; i < n; ++i) {
            map<pair<int, int>, int> mp;
            int duplicate = 1;
            for (int j = i + 1; j < n; ++j) {
                if (points[j][0] == points[i][0] && points[j][1] == points[i][1]) {
                    duplicate += 1;
                    continue;
                }
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                int d = gcd(dx, dy);
                mp[make_pair(dy / d, dx / d)]++;
            }
            res = max(res, duplicate);
            for (auto element : mp) {
                res = max(res, duplicate + element.second);
            }
        }
        return res;
    }
};