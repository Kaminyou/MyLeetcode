class Solution {
public:
    int dp1[30][30][30];
    int dp2[30][30][30];
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        return dp(n, firstPlayer, secondPlayer);
    }
    vector<int> dp(int n, int a, int b) {
        if (a + b == n + 1) return {1, 1};
        if (dp1[n][a][b] != 0) {
            return {dp1[n][a][b], dp2[n][a][b]};
        }
        if (a > b) return dp(n, b, a);
        if (a + b > n + 1) {
            return dp(n, n + 1 - b, n + 1 - a);
        }

        int bb = n + 1 - b;
        int maxVal = INT_MIN / 2;
        int minVal = INT_MAX / 2;

        if (b > (n + 1) / 2) {
            int range1 = a - 1;
            int range2 = bb - a - 1;
            int z = (b - bb - 1 + 1) / 2;
            for (int x = 0; x <= range1; x++) {
                for (int y = 0; y <= range2; y++) {
                    auto temp = dp((n + 1) / 2, x + 1, x + 1 + y + z + 1);
                    minVal = min(minVal, temp[0] + 1);
                    maxVal = max(maxVal, temp[1] + 1);
                }
            }
        } else {
            int range1 = a - 1;
            int range2 = b - a - 1;
            for (int x = 0; x <= range1; x++) {
                for (int y = 0; y <= range2; y++) {
                    auto temp = dp((n + 1) / 2, x + 1, x + 1 + y + 1);
                    minVal = min(minVal, temp[0] + 1);
                    maxVal = max(maxVal, temp[1] + 1);
                }
            }
        }
        dp1[n][a][b] = minVal;
        dp2[n][a][b] = maxVal;
        return {minVal, maxVal};
    }
};
