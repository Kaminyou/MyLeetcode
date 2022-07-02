typedef long long LL;
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        const LL mod = 1e9 + 7;
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        horizontalCuts.insert(horizontalCuts.begin(), 0);
        horizontalCuts.push_back(h);
        verticalCuts.insert(verticalCuts.begin(), 0);
        verticalCuts.push_back(w);
        int maxHorizontalInterval = 0;
        int maxVerticalInterval = 0;
        for (int i = 1; i < horizontalCuts.size(); ++i) {
            maxHorizontalInterval = max(maxHorizontalInterval, horizontalCuts[i] - horizontalCuts[i - 1]);
        }
        for (int i = 1; i < verticalCuts.size(); ++i) {
            maxVerticalInterval = max(maxVerticalInterval, verticalCuts[i] - verticalCuts[i - 1]);
        }
        LL res = static_cast<LL>(maxHorizontalInterval) * maxVerticalInterval;
        return res % mod;
    }
};