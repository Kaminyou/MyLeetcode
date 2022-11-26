class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> rightY(n + 1, 0);
        vector<int> leftN(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            rightY[i] = rightY[i + 1];
            if (customers[i] == 'Y') rightY[i]++;
        }
        for (int i = 1; i <= n; ++i) {
            leftN[i] = leftN[i - 1];
            if (customers[i - 1] == 'N') leftN[i]++;
        }
        int close = -1;
        int penalty = INT_MAX;
        for (int i = 0; i <= n; ++i) {
            int currentPenalty = rightY[i] + leftN[i];
            if (currentPenalty < penalty) {
                penalty = currentPenalty;
                close = i;
            }
        }
        return close;
    }
};
