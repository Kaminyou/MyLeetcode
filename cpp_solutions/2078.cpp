class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int res = 0;
        int n = colors.size();
        for (int i = n - 1; i >= 1; --i) {
            if (colors[0] != colors[i]) {
                res = max(res, i);
                break;
            }
        }
        for (int i = 0; i <= n - 2; ++i) {
            if (colors[n - 1] != colors[i]) {
                res = max(res, n - 1 - i);
                break;
            }
        }
        return res;
    }
};
