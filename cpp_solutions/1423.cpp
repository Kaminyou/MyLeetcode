class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0;
        int n = cardPoints.size();
        for (auto& point : cardPoints) sum += point;
        if (k == n) return sum;
        int interval = n - k;
        int res = INT_MAX;
        int curr = 0;
        for (int i = 0; i < interval - 1; ++i) curr += cardPoints[i];
        for (int i = interval - 1; i < n; ++i) {
            curr += cardPoints[i];
            res = min(res, curr);
            curr -= cardPoints[i - interval + 1];
        }
        return sum - res;
    }
};